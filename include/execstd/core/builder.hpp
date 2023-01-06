#pragma once
#include "../devices/device.hpp"
#include <memory>
#include <vector>

namespace Context {
/// \brief Class for building context of execution
class libapi Builder
{
private:
    /// Forward declaration
    friend class Context;
    std::vector<Devices::Device> deviceList;

public:
    Builder() = delete;
    explicit Builder(uint8_t cType);
    std::shared_ptr<Context> ToContext() const;
};

/// \brief Create context builder with default settings
std::shared_ptr<Builder> CreateDefaultBuilder();
} // namespace Context
