//
// Created by liember on 1/22/21.
//

#include "gtest/gtest.h"
#include "Quadrant.h"

using namespace lieEngine::core;

TEST(Quadrant, init) {
    space::Quadrant<double> rect(10, 10, 10);
    ASSERT_EQ(rect.posX(), 10);
    ASSERT_EQ(rect.posY(), 10);
    ASSERT_EQ(rect.sideSize(), 10);
}

TEST(Quadrant, center) {
    space::Quadrant<double> rect(10, 10, 10);
    auto center = rect.center();
    ASSERT_EQ(center.X(), 15);
    ASSERT_EQ(center.Y(), 15);
    ASSERT_EQ(rect.sideSize(), 10);
}

TEST(Quadrant, contain) {
    space::Quadrant<double> rect(10, 1, 1);
    math::vector2d<double> point1(2, 2);
    math::vector2d<double> point2(11, 2);
    ASSERT_TRUE(rect.contains(point1));
    ASSERT_FALSE(rect.contains(point2));
}

TEST(Quadrant, intersectArea) {
    space::Quadrant<double> rect(10, 1, 1);
    space::Quadrant<double> rect2(10, 9, 9);

    ASSERT_EQ(rect.intersectArea(rect2), 4);
}