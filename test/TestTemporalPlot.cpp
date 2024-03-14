#include <gtest/gtest.h>
#include <QApplication>
#include "TemporalPlot.hpp"

class TemporalPlotTestSuite : public ::testing::Test {
public:
    TemporalPlotTestSuite() {}
    ~TemporalPlotTestSuite() {}
    void SetUp() {
        parent = new QWidget();
        temporalPlot = new TemporalPlot(parent);
    }
    TemporalPlot* temporalPlot;
    QWidget* parent;
};

TEST_F(TemporalPlotTestSuite, Constructor) {
    unsigned int nsamples = 1000;
    std::vector<int> channel_selected = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    QList<QString> chlabels = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    temporalPlot->time_window_ = 1;
    temporalPlot->set_channel_labels(chlabels);
    temporalPlot->setup(nsamples, channel_selected);

    EXPECT_EQ(temporalPlot->channel_selected_index_, channel_selected);
    EXPECT_EQ(temporalPlot->channel_labels_, chlabels);
    EXPECT_EQ(temporalPlot->time_window_, 1);
    EXPECT_EQ(temporalPlot->yticker_->ticks().size(), 10);
    EXPECT_EQ(temporalPlot->xticker_->ticks().size(), 2);
    EXPECT_EQ(temporalPlot->yAxis->range().lower, 0.5);
    EXPECT_EQ(temporalPlot->yAxis->range().upper, 10.5);
    EXPECT_EQ(temporalPlot->yAxis->visible(), true);
    EXPECT_EQ(temporalPlot->yAxis->tickLabels(), true);
    EXPECT_EQ(temporalPlot->yAxis->ticker(), temporalPlot->yticker_);
    EXPECT_EQ(temporalPlot->xAxis->ticker(), temporalPlot->xticker_);
    EXPECT_EQ(temporalPlot->xAxis->range().lower, 0);
    EXPECT_EQ(temporalPlot->xAxis->range().upper, 1000);
}

TEST_F(TemporalPlotTestSuite, SetScale) {
    double scale = 100;
    temporalPlot->set_scale(scale);
    EXPECT_EQ(temporalPlot->scale_, scale);
}

TEST_F(TemporalPlotTestSuite, SetTimeWindow) {
    float window = 1;
    temporalPlot->set_time_window(window);
    EXPECT_EQ(temporalPlot->time_window_, window);
}

TEST_F(TemporalPlotTestSuite, Plot){
    unsigned int nsamples = 1000;
    unsigned int nchannels = 10;
    EigenBuffer buffer(nsamples, nchannels);
    std::vector<float> data = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8};
    buffer.add(data);

    std::vector<int> channel_selected = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    QList<QString> chlabels = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    temporalPlot->time_window_ = 1;
    temporalPlot->set_channel_labels(chlabels);
    temporalPlot->setup(nsamples, channel_selected);
    temporalPlot->plot(buffer);

    EXPECT_EQ(temporalPlot->graphCount(), 10);
    for (int i = 0; i < 10; i++)
        EXPECT_EQ(temporalPlot->graph(i)->data()->size(), 200);
}

TEST_F(TemporalPlotTestSuite, Rescale) {
    double value = 100;
    double scale = 100;
    double rescaled = temporalPlot->rescale(value, scale);
    EXPECT_EQ(rescaled, 1);
}

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}