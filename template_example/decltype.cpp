#include <iostream>

template <typename T>
auto autoResult(T &arg) -> decltype(T(arg))
{
    return T(arg);
}

int main()
{
    int a = 10;
    auto result = autoResult(a);
    std::cout << "result=" << result << std::endl;
    return 0;
}