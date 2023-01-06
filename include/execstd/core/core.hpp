#pragma once
#include <cstdint>

namespace Core {
	/// \brief Enumeration for device's type definition
	enum DeviceType : uint8_t {
		Undefined = 0, ///< Undefined device
		CPU       = 1, ///< CPU device
		CUDA      = 2, ///< CUDA device
		OpenCL    = 4, ///< OpenCL device
		All       = 7  ///< All devices (CPU, CUDA and OpenCL)
	};

}

