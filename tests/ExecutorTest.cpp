#include "Executor.hpp"

#include "gtest/gtest.h"

TEST(Func1, Sample1)
{
    EXPECT_EQ(5, func1(2, 3));
}

TEST(Func1, Sample2)
{
    EXPECT_EQ(4, func1(2, 2));
}

TEST(func1, Sample3)
{
    EXPECT_TRUE(4 > func1(1, 2));
}