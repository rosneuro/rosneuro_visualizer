#include <gtest/gtest.h>
#include "DataThread.hpp"

class DataThreadTestSuite : public ::testing::Test {
    public:
        DataThreadTestSuite() {}
        ~DataThreadTestSuite() {}
        void SetUp() {
            parent = new QObject();
            dataThread = new DataThread(parent);
        }
        DataThread* dataThread;
        QObject* parent;
};

TEST_F(DataThreadTestSuite, Constructor) {
    EXPECT_EQ(dataThread->topic_, "/neurodata");
    EXPECT_EQ(dataThread->samplerate_, 0);
}

TEST_F(DataThreadTestSuite, Destructor) {
    ASSERT_FALSE(dataThread->abort_);
    dataThread->stop_thread();
    ASSERT_TRUE(dataThread->abort_);
    dataThread->~DataThread();
    ASSERT_TRUE(dataThread->abort_);
}

TEST_F(DataThreadTestSuite, StartThread) {
    dataThread->start_thread();
    ASSERT_EQ(dataThread->restart_, true);
    ASSERT_EQ(dataThread->abort_, false);
}

TEST_F(DataThreadTestSuite, Run) {
    dataThread->restart_ = true;
    dataThread->abort_ = true;

    dataThread->run();

    ASSERT_FALSE(dataThread->restart_);
    ASSERT_TRUE(dataThread->first_msg_);
    ASSERT_EQ(dataThread->mr_nsecs_.size(), 0);
    ASSERT_FALSE(dataThread->abort_);
}

TEST_F(DataThreadTestSuite, OnReceivedData) {
    dataThread->first_msg_ = true;

    rosneuro_msgs::NeuroFrame msg;
    msg.sr = 256;
    dataThread->on_received_data(msg);
    ASSERT_FALSE(dataThread->first_msg_);
    ASSERT_EQ(dataThread->mr_nsecs_.size(), 1);
}

TEST_F(DataThreadTestSuite, ToString) {
    rosneuro_msgs::NeuroDataInfo info;
    info.nchannels = 256;
    info.unit = "unit_test";
    info.transducter = "transducter_test";
    info.prefiltering = "prefiltering_test";
    info.minmax = {0, 1};

    std::string str = dataThread->to_string(info);
    std::string expected = "Number of channels: 256\n"
                           "Unit: unit_test\n"
                           "Transducter: transducter_test\n"
                           "Prefiltering: prefiltering_test\n"
                           "Min/max values: [ 0.000000 1.000000 ]\n";
    ASSERT_EQ(str, expected);
}

TEST_F(DataThreadTestSuite, EstimateMessageRate) {
    double nsecs = 10;
    dataThread->mr_nsecs_ = std::deque<double>(dataThread->mr_queue_length_, 0);
    float rate = dataThread->estimate_message_rate(nsecs);
    float expected = 9.9;
    ASSERT_EQ(rate, expected);

    dataThread->mr_nsecs_ = std::deque<double>(1, 0);
    rate = dataThread->estimate_message_rate(nsecs);
    ASSERT_EQ(rate, 0);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "DataThreadTestSuite");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}