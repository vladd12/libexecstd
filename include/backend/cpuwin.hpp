#pragma once
#include <bitset>
#include <cstdlib>
#include <cstdint>
#include <Windows.h>

/*
* 
*/

namespace CPU {
	constexpr std::size_t dwordSize = sizeof(DWORD) * 8;

	/// \brief Enumeration for what?
	enum ArchProcType : uint16_t {
		intel = PROCESSOR_ARCHITECTURE_INTEL,
		ia32 = PROCESSOR_ARCHITECTURE_IA32_ON_WIN64,
		ia64 = PROCESSOR_ARCHITECTURE_IA64,
		amd_x86_64 = PROCESSOR_ARCHITECTURE_AMD64,
		mips = PROCESSOR_ARCHITECTURE_MIPS,
		alpha = PROCESSOR_ARCHITECTURE_ALPHA,
		alpha64 = PROCESSOR_ARCHITECTURE_ALPHA64,
		arm = PROCESSOR_ARCHITECTURE_ARM,
		arm32 = PROCESSOR_ARCHITECTURE_ARM32_ON_WIN64,
		arm64 = PROCESSOR_ARCHITECTURE_ARM64
	};

	ArchProcType GetArchProcType();
	std::bitset<dwordSize> GetActiveProcBitMask();
	uint32_t GetProcNumber();

	void test();
}
