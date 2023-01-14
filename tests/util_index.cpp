#include <execstd/util/index.hpp>
#include <gtest/gtest.h>

TEST(Detail_CompileTime, IsCorrectArgsNum_PositiveTest)
{
    constexpr auto expected = true;
    constexpr auto actual = detail::is_correct_args_num_v<3, int, char, double>;
    ASSERT_EQ(expected, actual);
}

TEST(Detail_CompileTime, IsCorrectArgsNum_NegativeTest)
{
    using namespace detail;
    constexpr auto expected = false;
    constexpr auto actualFirst = is_correct_args_num_v<4, int>;
    ASSERT_EQ(expected, actualFirst);
    constexpr auto actualSecond = is_correct_args_num_v<1, int, int, int>;
    ASSERT_EQ(expected, actualSecond);
}

TEST(Detail_CompileTime, IsMoreThanZero_Test)
{
    using namespace detail;
    constexpr auto positive = is_more_than_zero_v<1>;
    constexpr auto negative = is_more_than_zero_v<0>;
    ASSERT_EQ(positive, true);
    ASSERT_NE(positive, negative);
}

TEST(Util_IndexClass, CtorTest)
{
    // Not empty initializer list (aggregate initialization)
    constexpr std::size_t size = 3;
    Util::Index<int, size> test_index1 = { 1, 2, 3 };
    ASSERT_EQ(test_index1[0], 1);
    ASSERT_EQ(test_index1[1], 2);
    ASSERT_EQ(test_index1[2], 3);
    // Empty initializer list
    constexpr Util::Index<int, size> test_index2 = {};
    for (std::size_t i = 0; i < size; i++)
    {
        ASSERT_EQ(test_index2[i], 0);
    }
}

TEST(Util_IndexClass, DimensionTest)
{
    constexpr std::size_t expected1 = 3;
    Util::Index<int, expected1> test_index1;
    ASSERT_EQ(expected1, test_index1.dimension());
    constexpr std::size_t expected2 = 25;
    constexpr Util::Index<int, expected2> test_index2 {};
    ASSERT_EQ(expected2, test_index2.dimension());
}

TEST(Util_IndexClass, FillTest)
{
    constexpr int expected = 5;
    constexpr std::size_t size = 10;
    Util::Index<int, size> test_index = {};
    test_index.fill(expected);
    for (std::size_t i = 0; i < size; i++)
    {
        ASSERT_EQ(expected, test_index[i]);
    }
}

TEST(Util_IndexClass, SizeTest)
{
    constexpr Util::Index3D test_index1 = { 1, 2, 3 };
    constexpr auto actual1 = test_index1.size();
    constexpr decltype(actual1) expected1 = 1 * 2 * 3;
    ASSERT_EQ(expected1, actual1);
    Util::Index<int, 5> test_index2 = { 1, 1, 10, 10, 3 };
    auto actual2 = test_index2.size();
    constexpr auto expected2 = 300;
    ASSERT_EQ(expected2, actual2);
}
