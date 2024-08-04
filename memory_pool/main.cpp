#include <iostream>
#include <string>
#include <vector>
#include "memory_pool.h"

class MemoryTest
{
public:
    DECLARE_POOL_ALLOCATOR()
    int age;
    std::string name;
};

IMPLEMENT_POOL_ALLOCATOR(MemoryTest);

int main()
{
    std::vector<MemoryTest *> list;
    for (size_t i = 0; i < 12; ++i)
    {
        auto *p = new MemoryTest();
        list.push_back(p);
        printf("%p\n", list[i]);
    }
    for (size_t i = 0; i < 12; ++i)
    {
        delete list[i];
    }
    std::cout << "--------------------------" << std::endl;
    std::vector<MemoryTest *> list2;
    for (size_t i = 0; i < 12; ++i)
    {
        auto *p = new MemoryTest();
        list.push_back(p);
        printf("%p\n", list[i]);
    }
    return 0;
}