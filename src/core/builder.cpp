#include <bitset>
#include <execstd/core/context.hpp>

#include <iostream>

namespace Context {
Builder::Builder(uint8_t dType)
{
    std::bitset<4> flags(dType);

    if (flags.test(0)) {
        std::cout << "CPU\n";
    }

    if (flags.test(1)) {
        std::cout << "CUDA\n";
    }

    if (flags.test(2)) {
        std::cout << "OpenCL\n";
    }
}

std::shared_ptr<Context> Builder::ToContext() const
{
    return std::shared_ptr<Context>(new Context(this));
}

std::shared_ptr<Builder> CreateDefaultBuilder()
{
    return std::shared_ptr<Builder>(new Builder(Core::DeviceType::All));
}

} // namespace Context
