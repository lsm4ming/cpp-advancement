# 通过循环获取此目录下所有的cpp文件
file(GLOB_RECURSE CPP_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# 通过迭代的方式将cpp文件添加到可执行文件中
foreach(CPP_FILE ${CPP_FILES})
    # 可执行目标名称为源文件名称去除后缀拼接_test
    get_filename_component(CPP_FILE_NAME ${CPP_FILE} NAME_WE)
    add_executable(${CPP_FILE_NAME}_test ${CPP_FILE})
    target_link_libraries(${CPP_FILE_NAME}_test gtest gtest_main)
endforeach()