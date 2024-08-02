cmake_minimum_required(VERSION 3.22)
project(cpp-advancement)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)
set(CMAKE_ENABLE_EXPORTS OFF)

add_subdirectory(third_party)

# 定义可执行目标
add_executable(cpp-advancement main.cpp)
target_link_libraries(cpp-advancement gtest gtest_main)
target_link_libraries(cpp-advancement Boost::system Boost::filesystem)