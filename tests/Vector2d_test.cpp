//
// Created by liember on 1/23/21.
//

#include "gtest/gtest.h"
#include "vector2d.h"

using namespace lieEngine::core;

TEST(vector2d, init) {
    math::vector2d<double> vec(12, 324);
    ASSERT_EQ(vec.X(), 12);
    ASSERT_EQ(vec.Y(), 324);
}

TEST(vector2d, copy) {
    auto vec = new math::vector2d<double>(12, 324);
    auto vec2 = new math::vector2d<double>(*vec);

    delete vec;
    ASSERT_EQ(324, vec2->Y());
    ASSERT_EQ(12, vec2->X());

    delete vec2;
}

