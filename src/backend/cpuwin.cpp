#include <backend/cpuwin.hpp>
#include <iostream>
#include <memory>

namespace CPU {
	LPSYSTEM_INFO InitSysInfo() {
		auto sysInfo = new SYSTEM_INFO{ 0 };
		GetSystemInfo(sysInfo);
		return sysInfo;
	}

	LPSYSTEM_INFO GetSysInfo() {
		static std::unique_ptr<SYSTEM_INFO> retVal(InitSysInfo());
		return retVal.get();
	}

	ArchProcType GetArchProcType() {
		auto sysInfo = GetSysInfo();
		return static_cast<ArchProcType>(sysInfo->wProcessorArchitecture);
	}

	std::bitset<dwordSize> GetActiveProcBitMask() {
		return std::bitset<dwordSize>(GetSysInfo()->dwActiveProcessorMask);
	}

	uint32_t GetProcNumber() {
		auto num = GetSysInfo()->dwNumberOfProcessors;
		return static_cast<uint32_t>(num);
	}

	void test() {
		auto sysInfo = GetSysInfo();
		std::cout << "wProcessorArchitecture: " << GetArchProcType()
			<< "\nbitmask: " << GetActiveProcBitMask()
			<< "\nnum of proc: " << GetProcNumber()
			<< '\n';
	}

}
