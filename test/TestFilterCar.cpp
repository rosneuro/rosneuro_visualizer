#include <gtest/gtest.h>
#include "FilterCar.hpp"

class FilterCarTestSuite : public ::testing::Test {
public:
    FilterCarTestSuite() {}
    ~FilterCarTestSuite() {}
    void SetUp() {
        filterCar = new FilterCar();
    }
    void TearDown() { delete filterCar; }
    FilterCar* filterCar;
};

TEST_F(FilterCarTestSuite, ApplyBuffer) {
    Eigen::MatrixXf buffer(3, 3);
    buffer << 1, 2, 3,
              4, 5, 6,
              7, 8, 9;
    filterCar->apply(buffer);
    ASSERT_EQ(buffer(0, 0), -3);
    ASSERT_EQ(buffer(1, 0), 0);
    ASSERT_EQ(buffer(2, 0), 3);
}

TEST_F(FilterCarTestSuite, ApplyChannelData) {
    std::vector<float> data = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    filterCar->apply(data, 3);
    ASSERT_EQ(data[0], -1);
    ASSERT_EQ(data[1], 0);
    ASSERT_EQ(data[2], 1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}