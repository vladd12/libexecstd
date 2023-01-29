#pragma once

#include <cstdint>
#include <cstdlib>

namespace Simple
{

/// @brief Enumeration for representing the type of index.
enum IndexType : std::uint8_t
{
    KernelConfig = 0, ///< Represents a generic kernel config.
    Index1D = 1,      ///< Represents a 1D index.
    Index2D = 2,      ///< Represents a 2D index.
    Index3D = 3,      ///< Represents a 3D index.
    LongIndex1D = 4,  ///< Represents a 1D index.
    LongIndex2D = 5,  ///< Represents a 2D index.
    LongIndex3D = 6,  ///< Represents a 3D index.
    None = UINT8_MAX  ///< Represents no compatible index type.
};

/// @brief Basic index interface.
template <typename T> //
class IBaseIndex
{
protected:
    constexpr static T invalid = -1;
    T size;
    IndexType indexType;

public:
    [[nodiscard]] constexpr auto getSize() const noexcept
    {
        return size;
    }

    [[nodiscard]] constexpr auto getIndexType() const noexcept
    {
        return indexType;
    }
};

using IBaseIntIndex = IBaseIndex<std::uint32_t>;  ///< Basic integer index interface.
using IBaseLongIndex = IBaseIndex<std::uint64_t>; ///< Basic long index interface.

/// @brief Generic index interface.
template <typename TIndex> //
class IGenericIndex
{
private:
    /*
    friend TIndex;
    /// @brief Static casting to TIndex type.
    constexpr const TIndex &toTIndex() const noexcept
    {
        return static_cast<const TIndex &>(*this);
    }
    */

public:
    /// @brief Returns true if the current index is greater
    /// than or equal to 0 and is less than the given dimension.
    [[nodiscard]] virtual const bool inBounds(const TIndex &dimension) const noexcept = 0;

    /// @brief Returns true if the current index is greater
    /// than or equal to 0 and is less than or equal to the given dimension.
    [[nodiscard]] virtual const bool inBoundsInclusive(const TIndex &dimension) const noexcept = 0;

    /// @brief Computes this + right-hand side.
    [[nodiscard]] virtual const TIndex add(const TIndex &rhs) const noexcept = 0;

    /// @brief Computes this - right-hand side.
    [[nodiscard]] virtual const TIndex subtract(const TIndex &rhs) const noexcept = 0;

    /// @brief Operator '+' overloading.
    [[nodiscard]] constexpr TIndex operator+(const TIndex &rhs) const noexcept
    {
        return add(rhs);
        // else try this:
        // return toTIndex() + rhs;
    }

    /// @brief Operator '-' overloading.
    [[nodiscard]] constexpr TIndex operator-(const TIndex &rhs) const noexcept
    {
        return subtract(rhs);
        // else try this:
        // return toTIndex() - rhs;
    }
};

// Forward declarations.
class IIntIndex;
class ILongIndex;

/// @brief Integer index interface.
class IIntIndex : public IBaseIntIndex, IGenericIndex<IBaseIntIndex>
{
public:
    [[nodiscard]] virtual const ILongIndex toLongIndex() const noexcept = 0;
};

/// @brief Long index interface.
class ILongIndex : public IBaseLongIndex, IGenericIndex<IBaseLongIndex>
{
public:
    [[nodiscard]] virtual const IIntIndex toIntIndex() const noexcept = 0;
};

template <typename T> //
class I1Dimension
{
private:
    static constexpr int dimension = 1;

protected:
    T x;

public:
    constexpr I1Dimension() : x(0)
    {
    }

    constexpr I1Dimension(const T xVal) : x(xVal)
    {
    }

    [[nodiscard]] constexpr auto getX() const noexcept
    {
        return x;
    }

    constexpr void setX(const T &value) noexcept
    {
        x = value;
    }

    [[nodiscard]] virtual int getDimension() const noexcept
    {
        return dimension;
    }
};

template <typename T> //
class I2Dimension : public I1Dimension<T>
{
private:
    static constexpr int dimension = 2;

protected:
    T y;

public:
    constexpr I2Dimension() : I1Dimension<T>(), y(0)
    {
    }

    constexpr I2Dimension(const T xVal, const T yVal) : I1Dimension<T>(xVal), y(yVal)
    {
    }

    [[nodiscard]] constexpr auto getY() const noexcept
    {
        return y;
    }

    constexpr void setY(const T &value) noexcept
    {
        y = value;
    }

    [[nodiscard]] virtual int getDimension() const noexcept override
    {
        return dimension;
    }
};

template <typename T> //
class I3Dimension : public I2Dimension<T>
{
private:
    static constexpr int dimension = 3;

protected:
    T z;

public:
    constexpr I3Dimension() : I2Dimension<T>(), z(0)
    {
    }

    constexpr I3Dimension(const T xVal, const T yVal, const T zVal) : I2Dimension<T>(xVal, yVal), z(zVal)
    {
    }

    [[nodiscard]] constexpr auto getZ() const noexcept
    {
        return z;
    }

    constexpr void setZ(const T &value) noexcept
    {
        z = value;
    }

    [[nodiscard]] virtual int getDimension() const noexcept override
    {
        return dimension;
    }
};

class Index1D : public I1Dimension<std::uint32_t>, public IIntIndex
{
public:
};

} // namespace Simple
