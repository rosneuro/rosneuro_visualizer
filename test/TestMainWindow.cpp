#include <gtest/gtest.h>
#include <QApplication>
#include "MainWindow.hpp"

class MainWindowTestSuite : public ::testing::Test {
public:
    MainWindowTestSuite() {}
    ~MainWindowTestSuite() {}
    void SetUp() {
        qMainWindow = new QMainWindow();
        mainWindow = new MainWindow(qMainWindow);
    }
    MainWindow* mainWindow;
    QMainWindow* qMainWindow;
};

TEST_F(MainWindowTestSuite, AddPanel) {
    EXPECT_EQ(mainWindow->ui_->NeuroTab->count(), 2);
    EEGPanel* eegPanel = new EEGPanel("EEG", qMainWindow);
    mainWindow->addPanel(eegPanel);
    EXPECT_EQ(mainWindow->ui_->NeuroTab->count(), 3);
    delete eegPanel;
}

TEST_F(MainWindowTestSuite, SetCurrentPanel) {
    mainWindow->set_current_panel();
    EXPECT_EQ(mainWindow->current_panel_, mainWindow->ui_->NeuroTab->widget(0));
}

TEST_F(MainWindowTestSuite, DestroyPanelWidgets) {
    mainWindow->destroy_panel_widgets();
    EXPECT_EQ(mainWindow->ui_->NeuroTab->count(), 1);
}

TEST_F(MainWindowTestSuite, OnStartEvent) {
    mainWindow->on_StartEvent();
    EXPECT_EQ(mainWindow->ui_->TopicValue->text().toStdString(), "/neurodata");
}

TEST_F(MainWindowTestSuite, OnStopEvent) {
    mainWindow->on_StopEvent();
    EXPECT_EQ(mainWindow->ui_->StopButton->text().toStdString(), "Stop");
    EXPECT_EQ(mainWindow->ui_->AcquisitionStatus->text().toStdString(), "Idle");
}

TEST_F(MainWindowTestSuite, OnFirstMessage) {
    rosneuro_msgs::NeuroFrame frame;
    frame.sr = 256;
    frame.eeg.info.nsamples = 256;
    mainWindow->on_FirstMessage(frame);
    EXPECT_EQ(mainWindow->ui_->AcquisitionStatus->text().toStdString(), "Idle");
    EXPECT_TRUE(mainWindow->ui_->InfoButton->isEnabled());
}

TEST_F(MainWindowTestSuite, OnMessageInfo) {
    float rate = 1.0;
    unsigned int sequence = 0;
    mainWindow->on_MessageInfo(sequence, rate);
    EXPECT_EQ(mainWindow->messagerate_, rate);
    EXPECT_EQ(mainWindow->sequence_, sequence);
    EXPECT_EQ(mainWindow->ui_->MessageRateLabel->text().toStdString(), "1 Hz");
    EXPECT_EQ(mainWindow->ui_->MessageSeqLabel->text().toStdString(), std::to_string(sequence));
}

TEST_F(MainWindowTestSuite, SetSamplerate) {
    float rate = 256.0;
    mainWindow->set_samplerate(rate);
    EXPECT_EQ(mainWindow->samplerate_, rate);
    EXPECT_EQ(mainWindow->ui_->NativeRateLabel->text().toStdString(), "256 Hz");

    rate = 0.0;
    mainWindow->set_samplerate(rate);
    EXPECT_EQ(mainWindow->ui_->NativeRateLabel->text().toStdString(), "~ Hz");
}

TEST_F(MainWindowTestSuite, StoreChannelLabels) {
    rosneuro_msgs::NeuroFrame frame;
    frame.eeg.info.labels.push_back("eeg1");
    frame.exg.info.labels.push_back("exg1");
    frame.tri.info.labels.push_back("tri1");
    mainWindow->store_channel_labels(frame);
    EXPECT_EQ(mainWindow->eeg_labels_.size(), 1);
    EXPECT_EQ(mainWindow->exg_labels_.size(), 1);
    EXPECT_EQ(mainWindow->tri_labels_.size(), 1);
    EXPECT_EQ(mainWindow->eeg_labels_.at(0).toStdString(), "eeg1");
    EXPECT_EQ(mainWindow->exg_labels_.at(0).toStdString(), "exg1");
    EXPECT_EQ(mainWindow->tri_labels_.at(0).toStdString(), "tri1");
    mainWindow->reset_channel_labels();
    EXPECT_EQ(mainWindow->eeg_labels_.size(), 0);
    EXPECT_EQ(mainWindow->exg_labels_.size(), 0);
    EXPECT_EQ(mainWindow->tri_labels_.size(), 0);
}

TEST_F(MainWindowTestSuite, SetInfo) {
    rosneuro_msgs::NeuroFrame frame;
    frame.eeg.info.nsamples = 256;
    frame.eeg.info.labels.push_back("eeg1");
    frame.exg.info.nsamples = 256;
    frame.exg.info.labels.push_back("exg1");
    frame.tri.info.nsamples = 256;
    frame.tri.info.labels.push_back("tri1");
    mainWindow->set_info(frame);
    SUCCEED();
}

TEST_F(MainWindowTestSuite, OnDataAvailable) {
    rosneuro_msgs::NeuroFrame frame;
    frame.sr = 256;
    frame.eeg.info.nsamples = 256;
    mainWindow->on_DataAvailable(frame);
    EXPECT_EQ(mainWindow->ui_->AcquisitionStatus->text().toStdString(), "Idle");
    EXPECT_FALSE(mainWindow->ui_->InfoButton->isEnabled());
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "MainWindowTestSuite");
    QApplication app(argc, argv);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}