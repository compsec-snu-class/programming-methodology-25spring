cmake_minimum_required(VERSION 3.14)
project(CalculatorTDD)

set(CMAKE_CXX_STANDARD 17)

if(MSVC)
    set(gtest_force_shared_crt ON CACHE BOOL
        "Use shared (DLL) run-time lib even when Google Test is built as static lib." FORCE)

    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

include(CTest)
enable_testing()

add_executable(test_calculator
    calculator.cpp
    test_calculator.cpp
)

target_link_libraries(test_calculator
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_calculator)
