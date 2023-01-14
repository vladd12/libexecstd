#pragma once
#include "../core/export.hpp"

#include <Windows.h>
#include <bitset>
#include <cstdint>
#include <cstdlib>
#include <vector>

/*
 *
 */

namespace CPU
{
constexpr auto dwordSize = sizeof(DWORD) * 8;

/// \brief Enumeration for what?
enum ArchProcType : uint16_t
{
    intel = PROCESSOR_ARCHITECTURE_INTEL,
    ia32 = PROCESSOR_ARCHITECTURE_IA32_ON_WIN64,
    ia64 = PROCESSOR_ARCHITECTURE_IA64,
    x86_64 = PROCESSOR_ARCHITECTURE_AMD64,
    arm = PROCESSOR_ARCHITECTURE_ARM,
    arm32 = PROCESSOR_ARCHITECTURE_ARM32_ON_WIN64,
    arm64 = PROCESSOR_ARCHITECTURE_ARM64,
    mips = PROCESSOR_ARCHITECTURE_MIPS,
    alpha = PROCESSOR_ARCHITECTURE_ALPHA,
    alpha64 = PROCESSOR_ARCHITECTURE_ALPHA64,
    unknown = PROCESSOR_ARCHITECTURE_UNKNOWN
};

/// \brief Just empty
enum ProcFeature : uint16_t
{
    float_prec_errata = PF_FLOATING_POINT_PRECISION_ERRATA,
    float_emulated = PF_FLOATING_POINT_EMULATED,
    cmp_exchange_double = PF_COMPARE_EXCHANGE_DOUBLE,
    mmx_available = PF_MMX_INSTRUCTIONS_AVAILABLE,
    ppc_movemem_64bit = PF_PPC_MOVEMEM_64BIT_OK,
    alpha_byte = PF_ALPHA_BYTE_INSTRUCTIONS,
    xmmi = PF_XMMI_INSTRUCTIONS_AVAILABLE,
    _3dnow = PF_3DNOW_INSTRUCTIONS_AVAILABLE,
    rdtsc = PF_RDTSC_INSTRUCTION_AVAILABLE,
    pae = PF_PAE_ENABLED,
    xmmi64 = PF_XMMI64_INSTRUCTIONS_AVAILABLE,
    nx = PF_NX_ENABLED,
    cmp_exchange128 = PF_COMPARE_EXCHANGE128,
    cmp64_exchange128 = PF_COMPARE64_EXCHANGE128,
    channels = PF_CHANNELS_ENABLED,
    xsave = PF_XSAVE_ENABLED,
    _2nd_lvl_addr_trnsltn = PF_SECOND_LEVEL_ADDRESS_TRANSLATION,
    virtual_firmware = PF_VIRT_FIRMWARE_ENABLED,
    rdwrfsgs_base = PF_RDWRFSGSBASE_AVAILABLE,
    fastfail = PF_FASTFAIL_AVAILABLE,
    rdrand = PF_RDRAND_INSTRUCTION_AVAILABLE,
    rdtscp = PF_RDTSCP_INSTRUCTION_AVAILABLE,
    rdpid = PF_RDPID_INSTRUCTION_AVAILABLE,
    monitorx = PF_MONITORX_INSTRUCTION_AVAILABLE,
    arm_vfp32 = PF_ARM_VFP_32_REGISTERS_AVAILABLE,
    arm_neon = PF_ARM_NEON_INSTRUCTIONS_AVAILABLE,
    arm_div = PF_ARM_DIVIDE_INSTRUCTION_AVAILABLE,
    arm64_loadstore_atomic = PF_ARM_64BIT_LOADSTORE_ATOMIC,
    arm_external_cache = PF_ARM_EXTERNAL_CACHE_AVAILABLE,
    arm_fmac = PF_ARM_FMAC_INSTRUCTIONS_AVAILABLE,
    arm_v8 = PF_ARM_V8_INSTRUCTIONS_AVAILABLE,
    arm_v8_crypto = PF_ARM_V8_CRYPTO_INSTRUCTIONS_AVAILABLE,
    arm_v8_crc32 = PF_ARM_V8_CRC32_INSTRUCTIONS_AVAILABLE,
    arm_v81_atomic = PF_ARM_V81_ATOMIC_INSTRUCTIONS_AVAILABLE,
    sse3 = PF_SSE3_INSTRUCTIONS_AVAILABLE,
    ssse3 = PF_SSSE3_INSTRUCTIONS_AVAILABLE,
    sse4_1 = PF_SSE4_1_INSTRUCTIONS_AVAILABLE,
    sse4_2 = PF_SSE4_2_INSTRUCTIONS_AVAILABLE,
    sse_daz_mode = PF_SSE_DAZ_MODE_AVAILABLE,
    avx = PF_AVX_INSTRUCTIONS_AVAILABLE,
    avx2 = PF_AVX2_INSTRUCTIONS_AVAILABLE,
    avx512f = PF_AVX512F_INSTRUCTIONS_AVAILABLE
};

libapi ArchProcType GetArchProcType();
libapi std::bitset<dwordSize> GetActiveProcBitMask();
libapi uint32_t GetProcNumber();
libapi std::vector<ProcFeature> GetProcFeatureList();
libapi void test();
} // namespace CPU
