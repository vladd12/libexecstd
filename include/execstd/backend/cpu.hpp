#pragma once

// Use include for Windows build
#ifdef _WIN64
#include "cpuwin.hpp"
#endif

// Use include for Linux build
#ifdef __linux__
#include "cpulinux.hpp"
#endif
