#include <gtest/gtest.h>
#include "FilterReference.hpp"

class FilterReferenceTestSuite : public ::testing::Test {
public:
    FilterReferenceTestSuite() {}
    ~FilterReferenceTestSuite() {}
    void SetUp() {
        filterReference = new FilterReference();
    }
    void TearDown() { delete filterReference; }
    FilterReference* filterReference;
};

TEST_F(FilterReferenceTestSuite, ApplyBuffer) {
    unsigned int refIdx = 1;
    Eigen::MatrixXf buffer(3, 3);
    buffer << 1, 2, 3,
              4, 5, 6,
              7, 8, 9;
    filterReference->apply(buffer, refIdx);
    Eigen::MatrixXf expected(3, 3);
    expected << -3, -3, -3,
                 0, 0, 0,
                 7, 8, 9;
    ASSERT_EQ(buffer, expected);
}

TEST_F(FilterReferenceTestSuite, ApplyVector) {
    unsigned int refIdx = 1;
    unsigned int nchannels = 3;
    std::vector<float> data = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    filterReference->apply(data, nchannels, refIdx);
    std::vector<float> expected = {-1.0, 0.0, 3.0, -1.0, 0.0, 6.0};
    ASSERT_EQ(data, expected);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}