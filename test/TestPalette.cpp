#include <gtest/gtest.h>
#include "Palette.hpp"

class MainWindowTestSuite : public ::testing::Test {
public:
    MainWindowTestSuite() {}
    ~MainWindowTestSuite() {}
    void SetUp() {
        palette = new Palette();
    }
    void TearDown() { delete palette; }
    Palette* palette;
};

TEST_F(MainWindowTestSuite, AddColor) {
    QColor color(255, 0, 0);
    palette->add(color);
    QColor expected(255, 0, 0);
    ASSERT_EQ(palette->get(), expected);
}

TEST_F(MainWindowTestSuite, NextColor) {
    QColor color1(255, 0, 0);
    QColor color2(0, 255, 0);
    palette->add(color1);
    palette->add(color2);
    palette->next();
    QColor expected(0, 255, 0);
    ASSERT_EQ(palette->get(), expected);
}

TEST_F(MainWindowTestSuite, PreviousColor) {
    QColor color1(255, 0, 0);
    QColor color2(0, 255, 0);
    palette->add(color1);
    palette->add(color2);
    palette->previous();
    QColor expected(0, 255, 0);
    ASSERT_EQ(palette->get(), expected);
}

TEST_F(MainWindowTestSuite, ResetColor) {
    QColor color1(255, 0, 0);
    QColor color2(0, 255, 0);
    palette->add(color1);
    palette->add(color2);
    palette->next();
    palette->reset();
    QColor expected(255, 0, 0);
    ASSERT_EQ(palette->get(), expected);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}