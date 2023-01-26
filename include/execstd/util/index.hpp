#pragma once

#include <array>
#include <execstd/core/export.hpp>
#include <execstd/util/compare.hpp>

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

/// \brief Helper value for fast using.
/// \see is_correct_args_num
template <std::size_t N, typename... Args> //
inline constexpr auto is_correct_args_num_v = is_correct_args_num<N, Args...>::value;

/// \brief Helper value for fast using.
/// \see is_more_than
template <std::size_t N> //
inline constexpr auto is_more_than_zero_v = is_more_than<N, 0>::value;

/// \brief Implementation of constexpr operator "for" version.
template <class F, std::size_t... I> constexpr inline void for_constexpr_impl(F &&func, std::index_sequence<I...>)
{
    (func(std::integral_constant<std::size_t, I> {}), ...);
}

/// \brief Constexpr operator "for" version.
/// \see for_constexpr_impl
template <std::size_t C, class F> constexpr inline void for_constexpr(F &&func)
{
    for_constexpr_impl(std::forward<F>(func), std::make_index_sequence<C> {});
}

/// \brief Checks that all types are the same.
template <typename T, typename... U> //
using all_same = std::conjunction<std::is_same<T, U>...>;

/// \brief Helper value for fast using.
/// \see all_same
template <typename T, typename... U> //
inline constexpr auto all_same_v = all_same<T, U...>::value;

} // namespace detail

namespace Util
{
/// \brief Template class for representing the index base interface.
template <typename T, std::size_t dim, std::enable_if_t<detail::is_more_than_zero_v<dim>, bool> = true> //
class Index : public IComparable<Index<T, dim>>
{
public:
    using val_type = T;
    using ref_type = T &;
    using rval_type = T &&;
    using const_type = const T;
    using cref_type = const T &;
    using crval_type = const T &&;
    static constexpr auto _dimension = dim;

private:
    val_type _indexes[_dimension];
    template <std::size_t num, typename... Ts> //
    static constexpr auto ctor_cond = detail::all_same_v<Ts...> &&detail::is_correct_args_num_v<num, Ts...>;

public:
    constexpr Index() : IComparable<Index<T, dim>>(), _indexes {}
    {
    }

    template <typename... Ts, std::enable_if_t<ctor_cond<dim, T, Ts...>, bool> = true> //
    constexpr Index(T &&arg, Ts &&...args) : IComparable<Index<T, dim>>(), _indexes { arg, args... }
    {
    }

    template <typename... Ts, std::enable_if_t<ctor_cond<dim + 1, T, Ts...>, bool> = true> //
    Index(Ts... args) : IComparable<Index<T, dim>>(), _indexes { args... }
    {
    }

    constexpr void fill(cref_type value) noexcept
    {
        for (std::size_t i = 0; i < _dimension; i++)
            _indexes[i] = value;
    }

    constexpr const val_type size() const noexcept
    {
        val_type result = 1;
        detail::for_constexpr<_dimension>([&](auto index) { result = result * _indexes[index]; });
        return result;
    }

    const val_type size_rt() const noexcept
    {
        val_type result = 1;
        for (std::size_t i = 0; i < _dimension; i++)
            result = result * _indexes[i];
        return result;
    }

    constexpr const auto dimension() const noexcept
    {
        return _dimension;
    }

    constexpr auto dimension() noexcept
    {
        return _dimension;
    }

    constexpr cref_type operator[](const std::size_t &index) const noexcept
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

    constexpr const compare_result compareTo(const Index<T, dim> &other) const noexcept
    {
        const auto lhs = size(), rhs = other.size();
        if (lhs > rhs)
            return compare_result::greater;
        else if (lhs < rhs)
            return compare_result::less;
        else
            return compare_result::equal;
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
