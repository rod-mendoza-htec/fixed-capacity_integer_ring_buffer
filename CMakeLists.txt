cmake_minimum_required(VERSION 3.16)
project(int_ring C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
    unity
    GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
    GIT_TAG        v2.6.1
)
FetchContent_MakeAvailable(unity)

add_library(int_ring src/int_ring.c)
target_include_directories(int_ring PUBLIC include)
target_compile_options(int_ring PRIVATE -Wall -Wextra -Wpedantic)

enable_testing()
add_executable(int_ring_test tests/int_ring_test.c)
target_link_libraries(int_ring_test PRIVATE int_ring unity)
target_compile_options(int_ring_test PRIVATE -Wall -Wextra -Wpedantic)
add_test(NAME int_ring_test COMMAND int_ring_test)