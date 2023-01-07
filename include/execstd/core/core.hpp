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

template<typename T>
auto multiply(T &&left, T &&right) -> decltype(left * right)
{
    return left * right;
}

} // namespace Core
