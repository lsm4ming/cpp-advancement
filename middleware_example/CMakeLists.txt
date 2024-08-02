add_executable(redis-test redis.cpp)

target_link_libraries(redis-test gtest gtest_main)

# hiredis
# FetchContent_Declare(
#     hiredis
#     GIT_REPOSITORY https://github.com/redis/hiredis.git
#     GIT_TAG v1.2.0
#     DOWNLOAD_EXTRACT_TIMESTAMP TRUE
# )
# FetchContent_MakeAvailable(hiredis)

target_link_libraries(redis-test hiredis)