#pragma once

#include <initializer_list>
#include <iterator>
#include <memory>

template <typename T, class Alloc = std::allocator<T>>
class Vector
{
private:
    T *data_{nullptr};
    size_t size_{0};
    size_t capacity_{10};
    [[no_unique_address]] Alloc m_alloc;

public:
    Vector() noexcept
    {
        data_ = nullptr;
        size_ = 0;
        capacity_ = 10;
    }

    ~Vector() = default;

    Vector(std::initializer_list<T> ilist, Alloc const &alloc = Alloc())
        : Vector(ilist.begin(), ilist.end(), alloc) {}

    explicit Vector(size_t n, Alloc const &alloc = Alloc()) : m_alloc(alloc)
    {
        data_ = m_alloc.allocate(n);
        capacity_ = size_ = n;
        for (size_t i = 0; i != n; i++)
        {
            std::construct_at(&data_[i]);
        }
    }

    Vector(size_t n, T const &val, Alloc const &alloc = Alloc()) : m_alloc(alloc)
    {
        data_ = m_alloc.allocate(n);
        capacity_ = size_ = n;
        for (size_t i = 0; i != n; i++)
        {
            std::construct_at(&data_[i], val); // m_data[i] = val
        }
    }

    template <std::random_access_iterator InputIt>
    Vector(InputIt first, InputIt last, Alloc const &alloc = Alloc()) : m_alloc(alloc)
    {
        size_t n = last - first;
        data_ = m_alloc.allocate(n);
        capacity_ = size_ = n;
        for (size_t i = 0; i != n; i++)
        {
            std::construct_at(&data_[i], *first);
            ++first;
        }
    }

    void push_back(int value);

    T at(size_t index) const;

    size_t size() const;

    bool empty() const;

private:
    void check_index(size_t index);

    void check_reserve();

    void copy_data(T *new_data, int index);

    void reserve(size_t new_capacity);
};

#include "vector.hpp"