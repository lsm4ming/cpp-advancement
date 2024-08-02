cmake_minimum_required(VERSION 3.22)
project(cpp-advancement)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(third_party)
add_subdirectory(template_example)

# 定义可执行目标
add_executable(cpp-advancement main.cpp)
target_link_libraries(cpp-advancement gtest gtest_main)
target_link_libraries(cpp-advancement Boost::system Boost::filesystem)