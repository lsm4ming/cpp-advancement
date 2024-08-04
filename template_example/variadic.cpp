#include <iostream>

template <typename... T>
void sayHello(T... args)
{
    std::cout << "参数数量=" << sizeof...(args) << std::endl;
    std::cout << "参数数量=" << sizeof...(T) << std::endl;
}

void sayHello2()
{
    // 递归终止
}

// 这种方式比较容易展开
template <typename T, typename... U>
void sayHello2(const T &frist, const U&... otherargs) 
{
    std::cout << "收到的参数值=" << frist << std::endl;
    // 递归展开
    sayHello2(otherargs...);
}

int main()
{
    std::cout << "123" << std::endl;
    sayHello<>();
    sayHello2<int, double, float>(1, 1.2, 1.3f);
    return 0;
}