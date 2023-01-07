project(cuda-internals LANGUAGES CUDA)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CUDA_STANDARD 14)

# All targets and variables giving by CUDA Toolkit:
# https://cmake.org/cmake/help/latest/module/FindCUDAToolkit.html
# Warning for developers: FindCUDA is deprecated since CMake version 3.10
include(FindCUDAToolkit)
message(STATUS "CUDA include path: ${CUDAToolkit_INCLUDE_DIRS}")
message(STATUS "CUDA library path: ${CUDAToolkit_LIBRARY_DIR}")

file(GLOB_RECURSE CUDA_INNER_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)
file(GLOB_RECURSE CUDA_INNER_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cu)

include_directories(${CUDAToolkit_INCLUDE_DIRS})
add_library(${PROJECT_NAME} STATIC ${CUDA_INNER_HEADERS} ${CUDA_INNER_SOURCES})
target_link_libraries(${PROJECT_NAME} CUDA::cudart_static)

# CMake version detecting and comparing. See also:
# - https://stackoverflow.com/questions/43697154/detect-current-cmake-version-using-cmake
if(${CMAKE_VERSION} VERSION_LESS "3.24.0")
    message(WARNING "Native CUDA Architecture detecting was introduced in CMake 3.24, please update for use this.")
    set_property(TARGET ${PROJECT_NAME} PROPERTY CUDA_ARCHITECTURES OFF)
else()
    # Detecting CUDA acrchitecture native by CMake. See also:
    # - https://stackoverflow.com/a/72332793/17157999
    # - https://cmake.org/cmake/help/latest/prop_tgt/CUDA_ARCHITECTURES.html
    set_property(TARGET ${PROJECT_NAME} PROPERTY CUDA_ARCHITECTURES NATIVE)
endif()


