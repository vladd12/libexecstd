#include <execstd/backend/cpuwin.hpp>
#include <iostream>
#include <memory>

namespace CPU
{
// \brief System Info Initialization
libapi LPSYSTEM_INFO InitSysInfo()
{
    auto sysInfo = new SYSTEM_INFO { 0 };
    GetSystemInfo(sysInfo);
    return sysInfo;
}

libapi LPSYSTEM_INFO GetSysInfo()
{
    static const std::unique_ptr<SYSTEM_INFO> retVal(InitSysInfo());
    return retVal.get();
}

libapi ArchProcType GetArchProcType()
{
    auto cpuArch = GetSysInfo()->wProcessorArchitecture;
    auto archProcType = ArchProcType::unknown;
    switch (cpuArch)
    {
    case PROCESSOR_ARCHITECTURE_INTEL:
    case PROCESSOR_ARCHITECTURE_IA32_ON_WIN64:
    case PROCESSOR_ARCHITECTURE_IA64:
    case PROCESSOR_ARCHITECTURE_AMD64:
    case PROCESSOR_ARCHITECTURE_ARM:
    case PROCESSOR_ARCHITECTURE_ARM32_ON_WIN64:
    case PROCESSOR_ARCHITECTURE_ARM64:
    case PROCESSOR_ARCHITECTURE_MIPS:
    case PROCESSOR_ARCHITECTURE_ALPHA:
    case PROCESSOR_ARCHITECTURE_ALPHA64:
        archProcType = static_cast<ArchProcType>(cpuArch);
        break;
    default:
        archProcType = ArchProcType::unknown;
        break;
    }
    return archProcType;
}

libapi std::bitset<dwordSize> GetActiveProcBitMask()
{
    return std::bitset<dwordSize>(GetSysInfo()->dwActiveProcessorMask);
}

libapi uint32_t GetProcNumber()
{
    auto num = GetSysInfo()->dwNumberOfProcessors;
    return static_cast<uint32_t>(num);
}

libapi std::vector<ProcFeature> GetProcFeatureList()
{
    static const DWORD features[] = { //
        PF_FLOATING_POINT_PRECISION_ERRATA, PF_FLOATING_POINT_EMULATED, PF_COMPARE_EXCHANGE_DOUBLE,
        PF_MMX_INSTRUCTIONS_AVAILABLE, PF_PPC_MOVEMEM_64BIT_OK, PF_ALPHA_BYTE_INSTRUCTIONS,
        PF_XMMI_INSTRUCTIONS_AVAILABLE, PF_3DNOW_INSTRUCTIONS_AVAILABLE, PF_RDTSC_INSTRUCTION_AVAILABLE, PF_PAE_ENABLED,
        PF_XMMI64_INSTRUCTIONS_AVAILABLE, PF_SSE_DAZ_MODE_AVAILABLE, PF_NX_ENABLED, PF_SSE3_INSTRUCTIONS_AVAILABLE,
        PF_COMPARE_EXCHANGE128, PF_COMPARE64_EXCHANGE128, PF_CHANNELS_ENABLED, PF_XSAVE_ENABLED,
        PF_ARM_VFP_32_REGISTERS_AVAILABLE, PF_ARM_NEON_INSTRUCTIONS_AVAILABLE, PF_SECOND_LEVEL_ADDRESS_TRANSLATION,
        PF_VIRT_FIRMWARE_ENABLED, PF_RDWRFSGSBASE_AVAILABLE, PF_FASTFAIL_AVAILABLE, PF_ARM_DIVIDE_INSTRUCTION_AVAILABLE,
        PF_ARM_64BIT_LOADSTORE_ATOMIC, PF_ARM_EXTERNAL_CACHE_AVAILABLE, PF_ARM_FMAC_INSTRUCTIONS_AVAILABLE,
        PF_RDRAND_INSTRUCTION_AVAILABLE, PF_ARM_V8_INSTRUCTIONS_AVAILABLE, PF_ARM_V8_CRYPTO_INSTRUCTIONS_AVAILABLE,
        PF_ARM_V8_CRC32_INSTRUCTIONS_AVAILABLE, PF_RDTSCP_INSTRUCTION_AVAILABLE, PF_RDPID_INSTRUCTION_AVAILABLE,
        PF_ARM_V81_ATOMIC_INSTRUCTIONS_AVAILABLE, PF_MONITORX_INSTRUCTION_AVAILABLE, PF_SSSE3_INSTRUCTIONS_AVAILABLE,
        PF_SSE4_1_INSTRUCTIONS_AVAILABLE, PF_SSE4_2_INSTRUCTIONS_AVAILABLE, PF_AVX_INSTRUCTIONS_AVAILABLE,
        PF_AVX2_INSTRUCTIONS_AVAILABLE, PF_AVX512F_INSTRUCTIONS_AVAILABLE
    };
    std::vector<ProcFeature> result;
    result.reserve(42);

    for (auto &feature : features)
    {
        if (IsProcessorFeaturePresent(feature))
        {
            result.push_back(static_cast<ProcFeature>(feature));
        }
    }
    return result;
}

libapi void test()
{
    auto sysInfo = GetSysInfo();
    std::cout << "wProcessorArchitecture: " << GetArchProcType() << "\nbitmask: " << GetActiveProcBitMask()
              << "\nnum of proc: " << GetProcNumber() << "\n\nfeatures of proc: ";
    for (auto &feauture : GetProcFeatureList())
    {
        std::cout << feauture << ' ';
    }
    std::cout << '\n';
}

} // namespace CPU
