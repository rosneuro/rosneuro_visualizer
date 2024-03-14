#include <gtest/gtest.h>
#include "FilterButterworth.hpp"

class FilterButterworthTestSuite : public ::testing::Test {
public:
    FilterButterworthTestSuite() {}
    ~FilterButterworthTestSuite() {}
    void SetUp() {
        filterButterworth = new FilterButterworth();
    }
    void TearDown() { delete filterButterworth; }
    FilterButterworth* filterButterworth;
    int order = 4;
    double samplerate = 1000;
    double cutoff = 100;
    int nchannels = 3;
};

TEST_F(FilterButterworthTestSuite, Constructor) {
    filterButterworth->set_type(FilterType::LOWPASS);
    EXPECT_EQ(filterButterworth->type_, FilterType::LOWPASS);
}

TEST_F(FilterButterworthTestSuite, Setup) {
    filterButterworth->set_type(FilterType::LOWPASS);
    EXPECT_TRUE(filterButterworth->setup(order, samplerate, cutoff, nchannels));
    EXPECT_EQ(filterButterworth->order_, 4);
    EXPECT_EQ(filterButterworth->samplerate_, 1000);
    EXPECT_EQ(filterButterworth->cutoff_, 100);
    EXPECT_EQ(filterButterworth->nchannels_, 3);

    order = -1;
    EXPECT_FALSE(filterButterworth->setup(order, samplerate, cutoff, nchannels));
}

TEST_F(FilterButterworthTestSuite, Apply) {
    filterButterworth->set_type(FilterType::LOWPASS);
    filterButterworth->setup(order, samplerate, cutoff, nchannels);

    std::vector<float> data = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    filterButterworth->apply(data);
    ASSERT_EQ(data.size(), 6);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}