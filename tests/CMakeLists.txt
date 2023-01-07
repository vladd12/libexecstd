project(execstd-tests LANGUAGES CXX)

include(get_gtest)
#find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} tests.cpp)
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PUBLIC
    execstd
    gtest
    gtest_main
)

