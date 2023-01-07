#include <execstd/core/core.hpp>
#include <gtest/gtest.h>

TEST(MultiplyTests, TestIntegerOne_One)
{
    constexpr auto expected = 1;
    const auto actual = Core::multiply(1, 1);
    ASSERT_EQ(expected, actual);
}

TEST(MultiplyTests, TestIntegerZero_Zero)
{
    constexpr auto expected = 0;
    const auto actual = Core::multiply(0, 0);
    ASSERT_EQ(expected, actual);
}

TEST(MultiplyTests, TestIntegerZero_One)
{
    constexpr auto expected = 0;
    const auto actual = Core::multiply(0, 1);
    ASSERT_EQ(actual, expected);
}
