#pragma once
#include "../core/core.hpp"

namespace Devices {
/// \brief Enumeration for representing general type of an device.
using DeviceType = Core::DeviceType;

///
class libapi Device
{
protected:
    DeviceType deviceType;

public:
    Device() = default;
    const auto &getDeviceType() const { return deviceType; }
};

libapi void printCudaInfo();

} // namespace Devices
