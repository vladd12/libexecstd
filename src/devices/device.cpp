#include <execstd/devices/device.hpp>

#ifdef CUDA_ENABLE
#include <device_info.hpp>
#else
#include <iostream>
#endif

namespace Devices {

void printCudaInfo()
{
#ifdef CUDA_ENABLE
    printDeviceInformation();
#else
    std::cout << "CUDA devices not found.\n";
#endif
}

} // namespace Devices
