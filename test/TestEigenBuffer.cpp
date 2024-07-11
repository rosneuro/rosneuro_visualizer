#include <gtest/gtest.h>
#include "EigenBuffer.hpp"

class EigenBufferTestSuite : public ::testing::Test {
    public:
        EigenBufferTestSuite() {}
        ~EigenBufferTestSuite() {}
        void SetUp() {
            nsamples = 10;
            nchannels = 3;
            buffer = new EigenBuffer(nsamples, nchannels);
        }
        void TearDown() { delete buffer; }
        EigenBuffer* buffer;
        int nsamples;
        int nchannels;
};

TEST_F(EigenBufferTestSuite, Constructor) {
    EXPECT_EQ(buffer->samples(), nsamples);
    EXPECT_EQ(buffer->channels(), nchannels);
}

TEST_F(EigenBufferTestSuite, Reset) {
    buffer->reset(20, 4);
    EXPECT_EQ(buffer->samples(), 20);
    EXPECT_EQ(buffer->channels(), 4);
}

TEST_F(EigenBufferTestSuite, AppendDataTest) {
    Eigen::MatrixXf data = Eigen::MatrixXf::Zero(nchannels, nsamples);
    ASSERT_EQ(buffer->get(), data);

    std::vector<float> testData = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0,
                                   11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0, 20.0,
                                   21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0};

    ASSERT_TRUE(buffer->add(testData));
    ASSERT_EQ(buffer->index_, 0);

    Eigen::MatrixXf expected = Eigen::MatrixXf::Zero(nchannels, nsamples);
    expected << 1, 4, 7, 10, 13, 16, 19, 22, 25, 28,
                2, 5, 8, 11, 14, 17, 20, 23, 26, 29,
                3, 6, 9, 12, 15, 18, 21, 24, 27, 30;

    ASSERT_EQ(buffer->get(), expected);

    for (int i = 0; i < nchannels; i++)
        for (int j = 0; j < nsamples; j++)
            ASSERT_EQ(buffer->at(j, i), expected(i, j));
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}