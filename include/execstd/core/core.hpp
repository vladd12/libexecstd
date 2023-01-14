#pragma once
#include <cstdint>
#include <execstd/core/compiler.hpp>
#include <execstd/core/export.hpp>
#include <memory>

namespace Core
{
/// \brief Enumeration for device's type definition
enum DeviceType : uint8_t
{
    Undefined = 0,            ///< Undefined device
    CPU = 1 << 0,             ///< CPU device
    CUDA = 1 << 1,            ///< CUDA device
    OpenCL = 1 << 2,          ///< OpenCL device
    All = CPU | CUDA | OpenCL ///< All devices (CPU, CUDA and OpenCL)
};

/*
/// \brief Compile-time multiplying
template<typename T>
constexpr auto multiply(T &&left, T &&right) -> decltype(left * right)
{
    return left * right;
}
*/

libapi int multiply(int &&left, int &&right);

} // namespace Core
