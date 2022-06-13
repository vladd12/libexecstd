#include <iostream>
#include <builder.hpp>

int main(void) {
	using namespace std;
	using namespace Context;
	Builder a(Core::DeviceType::OpenCL | Core::DeviceType::CPU);


	return 0;
}


