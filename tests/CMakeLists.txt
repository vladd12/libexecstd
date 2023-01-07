project(execstd-tests LANGUAGES CXX)

# Getting googletest as GTest::GTest target
include(get_gtest)

# Compiling tests as executable file
add_executable(${PROJECT_NAME} tests.cpp)
# Linking googletest and execstd libraries
target_link_libraries(${PROJECT_NAME} PUBLIC
    GTest::GTest
    execstd
)

# Register test for ctest, see also:
# - https://cmake.org/cmake/help/latest/manual/ctest.1.html
# - https://cmake.org/cmake/help/latest/command/add_test.html
# - https://matgomes.com/cmake-ctest-to-add-cpp-tests/
# - https://matgomes.com/integrate-google-test-into-cmake/
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
