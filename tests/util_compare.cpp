#include <execstd/util/compare.hpp>
#include <gtest/gtest.h>

/// \brief Helper struct for testing Util::IComparable.
struct TestStruct : Util::IComparable<TestStruct>
{
private:
    constexpr const auto sum() const noexcept
    {
        return field1 + field2;
    }

public:
    int field1;
    int field2;

    TestStruct(const int &value1, const int &value2) : IComparable(), field1(value1), field2(value2)
    {
    }

    constexpr const Util::compare_result compareTo(const TestStruct &other) const noexcept
    {
        const auto lhs = sum(), rhs = other.sum();
        if (lhs > rhs)
            return Util::compare_result::greater;
        else if (lhs < rhs)
            return Util::compare_result::less;
        else
            return Util::compare_result::equal;
    }
};

TEST(Util_IComparable, LessTest)
{
    TestStruct test1 { 1, 2 };
    TestStruct test2 { 10, 100 };
    ASSERT_EQ(test1 > test2, false);
    ASSERT_EQ(test1 < test2, true);
    ASSERT_EQ(test1 == test2, false);
    ASSERT_EQ(test1 >= test2, false);
    ASSERT_EQ(test1 <= test2, true);
    ASSERT_EQ(test1 != test2, true);
}

TEST(Util_IComparable, GreaterTest)
{
    TestStruct test1 { 10, 100 };
    TestStruct test2 { 1, 2 };
    ASSERT_EQ(test1 > test2, true);
    ASSERT_EQ(test1 < test2, false);
    ASSERT_EQ(test1 == test2, false);
    ASSERT_EQ(test1 >= test2, true);
    ASSERT_EQ(test1 <= test2, false);
    ASSERT_EQ(test1 != test2, true);
}

TEST(Util_IComparable, EqualTest)
{
    TestStruct test1 { 10, 100 };
    TestStruct test2 { 100, 10 };
    ASSERT_EQ(test1 > test2, false);
    ASSERT_EQ(test1 < test2, false);
    ASSERT_EQ(test1 == test2, true);
    ASSERT_EQ(test1 >= test2, true);
    ASSERT_EQ(test1 <= test2, true);
    ASSERT_EQ(test1 != test2, false);
}
