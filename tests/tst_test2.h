#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

/* using namespace testing; */
extern "C" {
#include "func.h"
}

TEST(func, no_sol) {
    perem res = peremen(2, 2, 1);
    EXPECT_EQ(0, res.perem_schete);
}

TEST(func, one_sol) {
    perem res = peremen(4, 4, 1);
    EXPECT_EQ(1, res.perem_schete);
    EXPECT_DOUBLE_EQ(-0.5, res.x1);
}

TEST(func, two_sols_1) {
    perem res = peremen(1, 4, 0);
    EXPECT_EQ(2, res.perem_schete);
    EXPECT_DOUBLE_EQ(-4.0, res.x1);
    EXPECT_DOUBLE_EQ(0.0, res.x2);
}

TEST(func, two_sols_2) {
    perem res = peremen(2, -5, 2);
    EXPECT_EQ(2, res.perem_schete);
    EXPECT_DOUBLE_EQ(0.5, res.x1);
    EXPECT_DOUBLE_EQ(2.0, res.x2);
}

TEST(func, stranger_things_1) {
    perem res = peremen(1, 0, 0);
    EXPECT_EQ(1, res.perem_schete);
    EXPECT_DOUBLE_EQ(0.0, res.x1);
}

TEST(func, stranger_things_2) {
    perem res = peremen(0, 1, 0);
    EXPECT_EQ(1, res.perem_schete);
    EXPECT_DOUBLE_EQ(0.0, res.x1);
}

TEST(func, stranger_things_3) {
    perem res = peremen(0, 0, 1);
    EXPECT_EQ(0, res.perem_schete);
}

TEST(func, stranger_things_4) {
    perem res = peremen(0, 0, 0);
    EXPECT_EQ(0, res.perem_schete);
}
