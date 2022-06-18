#include <iostream>
#include <builder.hpp>
#include <backend/cpu.hpp>


int main(void) {
	using namespace std;
	using namespace Context;
	Builder a(Core::DeviceType::OpenCL | Core::DeviceType::CPU);
	CPU::test();
	return 0;
}


