#include "rectangle.h"
#include "trapezoid.h"
#include "rhombus.h"
#include <gtest/gtest.h>
#include <sstream>

TEST(RectangleTest, test1) {
    Rectangle r(1.0, 2.0, 4.0, 5.0);
    EXPECT_DOUBLE_EQ(static_cast<double>(r), 20.0);
    EXPECT_DOUBLE_EQ(r.center_x(), 3.0);
    EXPECT_DOUBLE_EQ(r.center_y(), 4.5);
}

TEST(RectangleTest, test2) {
    Rectangle r1(1, 1, 3, 4);
    Rectangle r2;
    Figure* f[]{&r1, &r2};
    *f[1] = *f[0];
    EXPECT_TRUE(*f[1] == *f[0]);
}

TEST(RhombusTest, test1) {
    Rhombus r(0, 0, 6, 8); 
    EXPECT_DOUBLE_EQ(static_cast<double>(r), 24.0);
    EXPECT_DOUBLE_EQ(r.center_x(), 0.0);
    EXPECT_DOUBLE_EQ(r.center_y(), 0.0);
}

TEST(RhombusTest, test2) {
    Rhombus r;
    Rhombus r2(10, 10, 2, 4);
    r = std::move(r2);
    EXPECT_DOUBLE_EQ(static_cast<double>(r), 4.0);
    EXPECT_DOUBLE_EQ(r.center_x(), 10.0);
}

TEST(TrapezoidTest, test1) {
    Trapezoid t(0, 0, 6, 2, 3); 
    EXPECT_DOUBLE_EQ(static_cast<double>(t), 12.0);
    EXPECT_DOUBLE_EQ(t.center_x(), 0.0);
    EXPECT_DOUBLE_EQ(t.center_y(), 1.25); 
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}