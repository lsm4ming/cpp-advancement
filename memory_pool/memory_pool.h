#pragma once

#include <memory>

class Allocator
{
public:
    void *allocate(size_t size);

    void deallocate(void *ptr);

private:
    struct obj // 嵌入式指针，只是声明并没有实例化，所以不参与内存占用大小计算
    {
        struct obj *next;
    };

    int struct_count{5}; // 一次分配该内存的5倍作为内存池的容量

    obj *free_posi{nullptr}; // 内存池的头指针
};

#define DECLARE_POOL_ALLOCATOR()           \
    static Allocator pool;                 \
    static void *operator new(size_t size) \
    {                                      \
        return pool.allocate(size);        \
    }                                      \
    static void operator delete(void *ptr) \
    {                                      \
        pool.deallocate(ptr);              \
    }

#define IMPLEMENT_POOL_ALLOCATOR(classname) Allocator classname::pool;