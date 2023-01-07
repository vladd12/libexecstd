#pragma once
#include "../core/core.hpp"

namespace Devices {
///
class libapi Device
{
protected:
    Core::DeviceType dType;

public:
    Device() = default;
    auto GetDeviceType() -> decltype(dType) const { return dType; }
    //    virtual void Foo() = 0;
};

libapi void printCudaInfo();

} // namespace Devices
