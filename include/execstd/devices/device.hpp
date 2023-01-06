#pragma once
#include "../core/core.hpp"

namespace Devices {
using DeviceType = Core::DeviceType;

///
///
class Device
{
protected:
    DeviceType dType;

public:
    Device() = default;
    DeviceType GetDeviceType() const;
    virtual void Foo() = 0;
};

} // namespace Devices
