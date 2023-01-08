#pragma once
#include <execstd/devices/device.hpp>
#include <memory>
#include <vector>

namespace Runtime {
/// \brief Class for building context of execution.
class libapi Builder
{
private:
    /// Forward declaration.
    friend class Context;
    using ContextPtr = std::shared_ptr<Context>;

    std::vector<Devices::Device> deviceList;

public:
    Builder() = delete;
    explicit Builder(uint8_t cType);
    ContextPtr toContext() const;
};
using BuilderPtr = std::shared_ptr<Builder>;

/// \brief Create context builder with default settings.
libapi BuilderPtr createDefaultBuilder();
} // namespace Runtime
