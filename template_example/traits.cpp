#include <iostream>

/**
 * 萃取实现
 */
template<typename T>
struct TypeTraits
{
    static const char *name()
    { return "Unknown"; }
};

template<>
struct TypeTraits<int>
{
    static const char *name()
    { return "int类型"; }
};

template<>
struct TypeTraits<float>
{
    static const char *name()
    { return "float类型"; }
};

template<typename T>
void process(const T &value)
{
    std::cout << TypeTraits<T>::name() << std::endl;
}

/**
 * 通过C++17提供的`if constexpr`和`std::is_same_v`更加简洁的实现
*/
template<typename T>
void traits_test(const T &arg)
{
    if constexpr (std::is_same_v<T, int>)
    {
        std::cout << "int类型" << std::endl;
    } else if constexpr (std::is_same_v<T, float>)
    {
        std::cout << "float类型" << std::endl;
    } else
    {
        std::cout << "Unknown" << std::endl;
    }
};

int main()
{
    std::cout << "Traits" << std::endl;
    traits_test(0);
    traits_test(3.14f);

    process(0);
    process(3.14f);
    process("hello");
    return 0;
}