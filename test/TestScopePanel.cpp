#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <QApplication>
#include "ScopePanel.hpp"

class ScopePanelTestSuite : public ::testing::Test {
public:
    ScopePanelTestSuite() {}
    ~ScopePanelTestSuite() {}
    void SetUp() {
        name = "TestScopePanel";
        parent = new QWidget();
        scopePanel = new ScopePanel(name, parent);
    }
    ScopePanel* scopePanel;
    QString name;
    QWidget* parent;
};

TEST_F(ScopePanelTestSuite, Constructor) {
    ASSERT_EQ(scopePanel->window_length_, 10.0f);
    ASSERT_EQ(scopePanel->ui_->ScaleValue->isEnabled(), false);
    ASSERT_EQ(scopePanel->ui_->HighPassCheck->isEnabled(), false);
    ASSERT_EQ(scopePanel->ui_->HighPassValue->isEnabled(), false);
    ASSERT_EQ(scopePanel->ui_->LowPassCheck->isEnabled(), false);
    ASSERT_EQ(scopePanel->ui_->LowPassValue->isEnabled(), false);
    ASSERT_EQ(scopePanel->ui_->ReferenceValue->isEnabled(), false);
    ASSERT_EQ(scopePanel->ui_->ReferenceOpt->isEnabled(), false);
    ASSERT_EQ(scopePanel->ui_->ChannelsList->isEnabled(), false);
    ASSERT_EQ(scopePanel->ui_->TimeWindowValue->isEnabled(), false);
}

TEST_F(ScopePanelTestSuite, SetupValidFrame) {
    rosneuro_msgs::NeuroFrame sampleFrame;
    sampleFrame.sr = 256;
    sampleFrame.eeg.info.nchannels = 2560;
    scopePanel->setDataType(DataType::EEG);
    ASSERT_TRUE(scopePanel->setup(sampleFrame));
    ASSERT_EQ(scopePanel->samplerate_, sampleFrame.sr);
    ASSERT_EQ(scopePanel->nsamples_, sampleFrame.eeg.info.nchannels);
}

TEST_F(ScopePanelTestSuite, SetupInvalidFrame) {
    rosneuro_msgs::NeuroFrame invalidFrame;
    ASSERT_FALSE(scopePanel->setup(invalidFrame));
    scopePanel->setDataType(DataType::UNKNOWN);
    ASSERT_FALSE(scopePanel->setup(invalidFrame));
}

TEST_F(ScopePanelTestSuite, Reset) {
    scopePanel->reset();
    ASSERT_EQ(scopePanel->samplerate_, 0);
    ASSERT_EQ(scopePanel->nsamples_, 0);
    ASSERT_FALSE(scopePanel->isset_);
}

TEST_F(ScopePanelTestSuite, Update) {
    rosneuro_msgs::NeuroFrame sampleFrame;
    sampleFrame.sr = 256;
    sampleFrame.eeg.info.nchannels = 16;
    sampleFrame.eeg.data = {1, 2, 3, 4, 5,
                            6, 7, 8, 9, 10,
                            11, 12, 13, 14, 15, 16};

    scopePanel->setDataType(DataType::EEG);
    ASSERT_TRUE(scopePanel->setup(sampleFrame));

    scopePanel->on_LowPassCheckChanged(0);
    scopePanel->on_LowPassValueChanged(0.5);
    scopePanel->SpatialFilterIndex_ = 0;
    scopePanel->update(sampleFrame);
    ASSERT_EQ(scopePanel->buffer_->channels(), 16);

    std::vector<float> expectedData = {1, 2, 3, 4, 5,
                                       6, 7, 8, 9, 10,
                                       11, 12, 13, 14, 15, 16};
    for (int i = 0; i < 16; i++)
        ASSERT_EQ(scopePanel->buffer_->at(0, i), expectedData[i]);

    scopePanel->on_HighPassCheckChanged(0);
    scopePanel->on_HighPassValueChanged(0.5);
    scopePanel->SpatialFilterIndex_ = 1;
    scopePanel->update(sampleFrame);
    ASSERT_EQ(scopePanel->buffer_->channels(), 16);
    for (int i = 0; i < 16; i++)
        ASSERT_EQ(scopePanel->buffer_->at(0, i), expectedData[i]);
}

TEST_F(ScopePanelTestSuite, Draw) {
    rosneuro_msgs::NeuroFrame sampleFrame;
    sampleFrame.sr = 256;
    sampleFrame.eeg.info.nchannels = 16;
    sampleFrame.eeg.data = {1, 2, 3, 4, 5,
                            6, 7, 8, 9, 10,
                            11, 12, 13, 14, 15, 16};

    scopePanel->setDataType(DataType::EEG);
    scopePanel->setup(sampleFrame);
    scopePanel->update(sampleFrame);
    scopePanel->isset_ = true;
    scopePanel->draw();
    SUCCEED();
}

TEST_F(ScopePanelTestSuite, OnScaleChanged) {
    scopePanel->on_ScaleChanged(1);
    ASSERT_EQ(scopePanel->ScaleValue_, 2.5f);
}

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}