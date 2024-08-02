add_executable(redis-test redis.cpp)

target_link_libraries(redis-test gtest gtest_main)
# 链接redis
target_link_libraries(redis-test redis++::redis++_static)