#include <execstd/util/index.hpp>
#include <gtest/gtest.h>

TEST(Detail_IsCorrectArgsNum, PositiveCompileTime_Test)
{
    constexpr auto expected = true;
    constexpr auto actual = detail::is_correct_args_num_v<3, int, char, double>;
    ASSERT_EQ(expected, actual);
}

TEST(Detail_IsCorrectArgsNum, NegativeCompileTime_Test)
{
    using namespace detail;
    constexpr auto expected = false;
    constexpr auto actualFirst = is_correct_args_num_v<4, int>;
    ASSERT_EQ(expected, actualFirst);
    constexpr auto actualSecond = is_correct_args_num_v<1, int, int, int>;
    ASSERT_EQ(expected, actualSecond);
}

TEST(Util_Index, TestCtor)
{
    int n = 1;
    Util::Index<int, 3> index3d { 1, 2, 3 };
    index3d[n];
    ASSERT_EQ(true, true);
}
