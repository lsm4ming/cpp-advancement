#include "vector.h"

template <typename T, class Alloc>
inline void Vector<T, Alloc>::check_index(size_t index)
{
    if (index < 0 || index >= this->size_)
    {
        throw std::out_of_range("Index out of range");
    }
}

template <typename T, class Alloc>
inline void Vector<T, Alloc>::check_reserve()
{
    if (this->data_ == nullptr)
    {
        this->data_ = m_alloc.allocate(this->capacity_);
    }
    else if (this->size_ == this->capacity_)
    {
        this->reserve(this->capacity_ * 2);
    }
}

template <typename T, class Alloc>
inline void Vector<T, Alloc>::copy_data(T *new_data, int index)
{
    // 是否支持移动语义
    if constexpr (std::is_move_constructible_v<T>)
    {
        new_data[index] = std::move(this->data_[index]);
    }
    else
    {
        new_data[index] = this->data_[index];
    }
}

template <typename T, class Alloc>
void Vector<T, Alloc>::reserve(size_t new_capacity)
{
    if (new_capacity > this->capacity_)
    {
        T *new_data = new T[new_capacity];
        for (size_t i = 0; i < this->size_; ++i)
        {
            this->copy_data(new_data, i);
        }
        delete[] this->data_;
        this->data_ = new_data;
        this->capacity_ = new_capacity;
    }
}

template <typename T, class Alloc>
inline void Vector<T, Alloc>::push_back(int value)
{
    check_reserve();
    this->data_[this->size_++] = value;
}

template <typename T, class Alloc>
inline size_t Vector<T, Alloc>::size() const
{
    return this->size_;
}

template <typename T, class Alloc>
inline bool Vector<T, Alloc>::empty() const
{
    return this->size_ == 0;
}

template <typename T, class Alloc>
inline T Vector<T, Alloc>::at(size_t index) const
{
    check_index(index);
    return this->data_[index];
}