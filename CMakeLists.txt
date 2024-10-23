cmake_minimum_required(VERSION 3.25)

project(cpp-advancement)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(third_party)
add_subdirectory(template_example)
add_subdirectory(memory_pool)
add_subdirectory(design)
add_subdirectory(stl_example)
add_subdirectory(objects)
add_subdirectory(tests)
add_subdirectory(concurrency)
add_subdirectory(algorithm)

# 定义可执行目标
# add_executable(main main.cpp)
# target_link_libraries(main gtest gtest_main)
# target_link_libraries(main Boost::filesystem)