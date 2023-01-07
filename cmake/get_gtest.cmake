include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        origin/v1.12.x
)
FetchContent_MakeAvailable(googletest)
