#include "memory_pool.h"

void *Allocator::allocate(size_t size)
{
    obj *tmplink;
    if (this->free_posi == nullptr) // 果然当前没有空闲空间 则需要重新申请
    {
        size_t realsize = this->struct_count * size;
        this->free_posi = (obj *)malloc(realsize);
        if (!this->free_posi)
        {
            throw std::bad_alloc();
        }
        tmplink = this->free_posi;
        for (int i = 0; i < this->struct_count - 1; ++i)
        {
            tmplink->next = (obj *)((char *)tmplink + size);
            tmplink = tmplink->next;
        }
        tmplink->next = nullptr;
    }
    obj *p = this->free_posi;
    this->free_posi = this->free_posi->next;
    p->next = nullptr;
    return p;
}

void Allocator::deallocate(void *ptr)
{
    obj *p = (obj *)ptr;
    p->next = this->free_posi;
    this->free_posi = p;
}
