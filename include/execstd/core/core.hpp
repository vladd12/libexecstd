#pragma once
#include "export.hpp"
#include <cstdint>

namespace Core {
/// \brief Enumeration for device's type definition
enum DeviceType : uint8_t {
    Undefined = 0, ///< Undefined device
    CPU = 1,       ///< CPU device
    CUDA = 2,      ///< CUDA device
    OpenCL = 4,    ///< OpenCL device
    All = 7        ///< All devices (CPU, CUDA and OpenCL)
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
