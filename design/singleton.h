#pragma once

#include <type_traits>

/**
 * 优雅的实现单例模式
 * 
 * 使用懒汉式，线程安全
*/

// 定义约束，不允许指针类型 和 引用类型
template <typename T>
concept SingletonType = !std::is_pointer_v<T> && !std::is_reference_v<T>;

template <SingletonType T>
class SingletonHelper
{
private:
    SingletonHelper() = default;

public:
    SingletonHelper(const SingletonHelper &) = delete;
    SingletonHelper &operator=(const SingletonHelper &) = delete;
    SingletonHelper(SingletonHelper &&) = delete;
    SingletonHelper &operator=(SingletonHelper &&) = delete;

    ~SingletonHelper() = default;

    static T &getInstance();
};

template <SingletonType T>
inline T &SingletonHelper<T>::getInstance()
{
    static T instance;
    return instance;
}
