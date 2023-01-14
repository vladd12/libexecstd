#pragma once

#include <array>
#include <cstdint>
#include <type_traits>

namespace detail
{
template <bool value> struct is_correct_args_num_base : std::false_type
{
};

template <> struct is_correct_args_num_base<true> : std::true_type
{
};

/// \brief Comparing implementation.
template <std::size_t N, typename... Args> inline constexpr auto is_correct_args_num_impl = (N == sizeof...(Args));

/// \brief Checking the number of passed arguments in compile time.
template <std::size_t N, typename... Args>
using is_correct_args_num = is_correct_args_num_base<is_correct_args_num_impl<N, Args...>>;

/// \brief Reduction for using.
template <std::size_t N, typename... Args>
inline constexpr auto is_correct_args_num_v = is_correct_args_num<N, Args...>::value;

} // namespace detail

namespace Util
{
/// \brief Templates class for representing the index base interface.
template <typename T, std::size_t dim> class Index
{
public:
    using value_type = T;
    value_type _indexes[dim];

    constexpr T &operator[](const std::size_t &index) const noexcept
    {
        if constexpr (index < dim)
            return _indexes[dim];
        else
            return _indexes[0];
    }
};

} // namespace Util
