#include <iostream>
#include <utility>

template <typename T>
void anotherFunction(T &x)
{
    std::cout << "左值" << x << std::endl;
}

template <typename T>
void anotherFunction(T &&x)
{
    std::cout << "右值" << x << std::endl;
}

template <typename T>
void wrapper(T &&arg)
{
    /**
     ...一些公共逻辑
     */

    // 将参数完美转发给另一个函数
    anotherFunction(std::forward<T>(arg));
}

int main()
{
    int a = 10;
    wrapper(a);  // 传入左值
    wrapper(20); // 传入右值
    return 0;
}