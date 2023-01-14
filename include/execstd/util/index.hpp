#pragma once

#include <array>
#include <cstdint>
#include <execstd/core/export.hpp>
#include <type_traits>

namespace detail
{
template <bool value> struct is_condition_true : std::false_type
{
};

template <> struct is_condition_true<true> : std::true_type
{
};

/// \brief Implementation of comparing the arguments count with a given N.
template <std::size_t N, typename... Args> //
inline constexpr auto is_correct_args_num_impl = (N == sizeof...(Args));

/// \brief Implementation of numeric comparing (is lhs more than rhs).
template <std::size_t lhs, std::size_t rhs> //
inline constexpr auto is_more_than_impl = (lhs > rhs);

/// \brief Using implementation of comparing the arguments count.
/// \see is_correct_args_num_impl
template <std::size_t N, typename... Args> //
using is_correct_args_num = is_condition_true<is_correct_args_num_impl<N, Args...>>;

/// \brief Using implementation of numeric comparing.
/// \see is_more_than_impl
template <std::size_t lhs, std::size_t rhs> //
using is_more_than = is_condition_true<is_more_than_impl<lhs, rhs>>;

// Inlining values for using.
template <std::size_t N, typename... Args> //
inline constexpr auto is_correct_args_num_v = is_correct_args_num<N, Args...>::value;
template <std::size_t N> //
inline constexpr auto is_more_than_zero_v = is_more_than<N, 0>::value;

/// \brief Implementation of constexpr operator for version.
template <class F, std::size_t... I> constexpr void for_constexpr_impl(F &&func, std::index_sequence<I...>)
{
    (func(std::integral_constant<std::size_t, I> {}), ...);
}

/// \brief Constexpr operator for version.
/// \see for_constexpr_impl
template <size_t C, class F> constexpr void for_constexpr(F &&func)
{
    for_constexpr_impl(std::forward<F>(func), std::make_index_sequence<C> {});
}

} // namespace detail

namespace Util
{
/// \brief Template class for representing the index base interface.
template <typename T, std::size_t dim, std::enable_if_t<detail::is_more_than_zero_v<dim>, bool> = true> //
class Index
{
public:
    using value_type = T;
    using ref_type = T &;
    using const_ref_type = const T &;

    value_type _indexes[dim];
    static constexpr auto _dimension = dim;

    constexpr void fill(const_ref_type value) noexcept
    {
        for (std::size_t i = 0; i < _dimension; i++)
            _indexes[i] = value;
    }

    constexpr const value_type size() const noexcept
    {
        value_type result = 1;
        detail::for_constexpr<_dimension>([&](auto index) { result = result * _indexes[index]; });
        return result;
    }

    constexpr const std::size_t dimension() const noexcept
    {
        return _dimension;
    }

    constexpr std::size_t dimension() noexcept
    {
        return _dimension;
    }

    constexpr const_ref_type operator[](const std::size_t &index) const noexcept
    {
        if (index < _dimension)
            return _indexes[index];
        else
            return _indexes[0];
    }

    constexpr ref_type operator[](const std::size_t &index) noexcept
    {
        if (index < _dimension)
            return _indexes[index];
        else
            return _indexes[0];
    }
};

class libapi Index1D : public Index<std::uint32_t, 1>
{
};

class libapi Index2D : public Index<std::uint32_t, 2>
{
};

class libapi Index3D : public Index<std::uint32_t, 3>
{
};

} // namespace Util
