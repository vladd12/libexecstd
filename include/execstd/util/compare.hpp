#pragma once

#include <cstdint>
#include <type_traits>
#include <utility>

namespace Util
{

/// \see https://en.cppreference.com/w/cpp/utility/compare/compare_three_way
struct compare_three_way
{
    template <typename T, typename U>
    // requires std::three_way_comparable_with<T, U> // with different semantic requirements
    constexpr auto operator()(T &&t, U &&u) const;
};

enum compare_result : std::int8_t
{
    less = -1,
    equal = 0,
    greater = 1
};

struct is_three_way_comparable
{
};

/// \brief IComparable interface that uses the CRTP idiom to simplify using of comparison operators in underlying types.
/// \see https://www.fluentcpp.com/2019/04/09/how-to-emulate-the-spaceship-operator-before-c20-with-crtp/
template <typename T> //
class IComparable
{
private:
    /// \brief Static casting of the current object to underlying type T.
    constexpr const T &toUnderlying() const noexcept
    {
        return static_cast<const T &>(*this);
    }

    /// \brief Using static polymorphism for requiring the implementation of the "compareTo" method in type T.
    constexpr compare_result compare(const T &other) const noexcept
    {
        return toUnderlying().compareTo(other);
    }

    IComparable() = default;
    ~IComparable<T>() = default;
    IComparable<T>(const IComparable<T> &other) = default;
    IComparable<T>(IComparable<T> &&other) = default;
    IComparable<T> &operator=(const IComparable<T> &other) = default;
    IComparable<T> &operator=(IComparable<T> &&other) = default;

    friend T;

public:
    [[nodiscard]] constexpr bool operator==(const T &other) const noexcept
    {
        return (compare(other) == compare_result::equal);
    }

    [[nodiscard]] constexpr bool operator>(const T &other) const noexcept
    {
        return (compare(other) == compare_result::greater);
    }

    [[nodiscard]] constexpr bool operator<(const T &other) const noexcept
    {
        return (compare(other) == compare_result::less);
    }

    [[nodiscard]] constexpr bool operator!=(const T &other) const noexcept
    {
        return !(toUnderlying() == other);
    }

    [[nodiscard]] constexpr bool operator>=(const T &other) const noexcept
    {
        return !(toUnderlying() < other);
    }

    [[nodiscard]] constexpr bool operator<=(const T &other) const noexcept
    {
        return !(toUnderlying() > other);
    }
};

} // namespace Util
