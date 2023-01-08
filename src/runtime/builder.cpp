#include <bitset>
#include <execstd/runtime/context.hpp>

#include <iostream>

namespace Runtime {
Builder::Builder(uint8_t dType)
{
    constexpr auto bitwise_size = sizeof(dType) * 8;
    std::bitset<bitwise_size> flags(dType);

    /*
if (flags.test(0)) {
std::cout << "CPU\n";
}

if (flags.test(1)) {
std::cout << "CUDA\n";
}

if (flags.test(2)) {
std::cout << "OpenCL\n";
}
*/
}

ContextPtr Builder::toContext() const
{
    return std::shared_ptr<Context>(new Context(this));
}

BuilderPtr createDefaultBuilder()
{
    return std::shared_ptr<Builder>(new Builder(Core::DeviceType::All));
}

} // namespace Runtime
