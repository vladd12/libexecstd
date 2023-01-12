#pragma once

#include <array>
#include <cstdint>
#include <type_traits>

namespace detail {
/*

template<std::size_t N, typename... Args>
struct is_correct_args_num
{
    static constexpr auto value = (N == sizeof...(Args));
    using value_type = decltype(value);
    constexpr operator value_type() const noexcept { return value; }
    constexpr value_type operator()() const noexcept { return value; }
};
/// \brief Reductions for using.
template<std::size_t N, typename... Args>
using is_correct_args_num_v = typename is_correct_args_num<N, Args...>::value;
*/

template<bool value>
struct is_correct_args_num_base : std::false_type
{};

template<>
struct is_correct_args_num_base<true> : std::true_type
{};

/// \brief Comparing implementation.
template<std::size_t N, typename... Args>
constexpr auto is_correct_args_num_impl = (N == sizeof...(Args));

/// \brief Checking the number of passed arguments in compile time.
template<std::size_t N, typename... Args>
using is_correct_args_num = is_correct_args_num_base<is_correct_args_num_impl<N, Args...>>;

/// \brief Reduction for using.
template<std::size_t N, typename... Args>
inline constexpr auto is_correct_args_num_v = is_correct_args_num<N, Args...>::value;

} // namespace detail

namespace Util {
/// \brief Templates class for representing the index base interface.
template<typename T, std::size_t dim>
class Index
{
protected:
    std::array<T, dim> indexes;
    using value_type = T;

public:
    Index() : indexes() {}

    template<T... Args, std::enable_if_t<dim == sizeof...(Args), bool> = true>
    Index(T args...) : indexes{args}
    {
        ;
    }
};

} // namespace Util
