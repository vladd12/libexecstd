#include <cuda_runtime_api.h>
#include <device_info.hpp>
#include <iostream>
#include <thrust/device_vector.h>
#include <thrust/host_vector.h>

constexpr int notFound = -1;
constexpr int errorCode = 9999;

__host__ int getDeviceCount()
{
    // Getting device count on computer
    int deviceCount = 0;
    cudaGetDeviceCount(&deviceCount);
    // If devices not found, check return value
    if (deviceCount == 0) {
        cudaDeviceProp deviceProp;
        cudaGetDeviceProperties(&deviceProp, 0);
        if (deviceProp.major == errorCode && deviceProp.minor == errorCode)
            deviceCount = notFound;
    }
    return deviceCount;
}

__host__ void printInfo(const cudaDeviceProp &devProp)
{
    // Выводим иформацию об устройстве
    std::cout << "\n\nDevice name: " << devProp.name << ".\n";
    std::cout << "Compute capability: " << devProp.major << "." << devProp.minor << ".\n";
    std::cout << "Maximum global memory size: " << devProp.totalGlobalMem << " bytes.\n";
    std::cout << "Maximum constant memory size: " << devProp.totalConstMem << " bytes.\n";
    std::cout << "Maximum shared memory size per block: " << devProp.sharedMemPerBlock
              << " bytes.\n";
    std::cout << "Maximum block dimensions: " << devProp.maxThreadsDim[0] << " x "
              << devProp.maxThreadsDim[1] << " x " << devProp.maxThreadsDim[2] << ".\n";
    std::cout << "Maximum grid dimensions: " << devProp.maxGridSize[0] << " x "
              << devProp.maxGridSize[1] << " x " << devProp.maxGridSize[2] << ".\n";
    std::cout << "Max threads per block: " << devProp.maxThreadsPerBlock << ".\n";
    std::cout << "Registers per block: " << devProp.regsPerBlock << " 32-bit registers.\n";
    std::cout << "Warp size: " << devProp.warpSize << ".\n";
    std::cout << "Clock rate: " << devProp.clockRate << " kilohertz.\n";
    std::cout << "Multiprocessor count: " << devProp.multiProcessorCount << "\n\n";
}

void printDeviceInformation()
{
    static const auto devices = getDeviceCount();
    cudaDeviceProp deviceProp;
    for (auto dev = 0; dev < devices; dev++) {
        cudaGetDeviceProperties(&deviceProp, dev);
        printInfo(deviceProp);
    }
}
