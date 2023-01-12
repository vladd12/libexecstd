#include <execstd/core/core.hpp>
#include <execstd/devices/device.hpp>
#include <gtest/gtest.h>

TEST(MultiplyTests, TestIntegerOne)
{
    constexpr auto expected = 3;
    const auto actual = Core::multiply(3, 1);
    ASSERT_EQ(expected, actual);
}

TEST(MultiplyTests, TestIntegerZero)
{
    constexpr auto expected = 0;
    const auto actual = Core::multiply(3, 0);
    ASSERT_EQ(expected, actual);
}

TEST(MultiplyTests, TestIntegerZero_One)
{
    constexpr auto expected = 0;
    const auto actual = Core::multiply(0, 1);
    ASSERT_EQ(actual, expected);
}

TEST(CUDA_Tests, TestDeviceInfo)
{
    Devices::printCudaInfo();
    ASSERT_EQ(true, true);
}
