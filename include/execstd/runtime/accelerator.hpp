#pragma once

#include <execstd/core/core.hpp>
#include <execstd/runtime/context.hpp>

namespace Runtime
{
/// \brief Enumeration for representing general type of an accelerator (device).
using AcceleratorType = Core::DeviceType;

// Forward declaration
class Accelerator;
using AcceleratorPtr = std::shared_ptr<Accelerator>;

/// \brief Abstract builder class for accelerators.
class IAcceleratorBuilder
{
private:
    AcceleratorType acceleratorType;

protected:
    void setAcceleratorType(const AcceleratorType &newType)
    {
        acceleratorType = newType;
    }

public:
    IAcceleratorBuilder() = delete;
    IAcceleratorBuilder(const AcceleratorType &accelType) : acceleratorType(accelType)
    {
    }

    const auto &getAcceleratorType() const
    {
        return acceleratorType;
    }

    virtual AcceleratorPtr createAccelerator(const Context &context) = 0;
};

} // namespace Runtime
