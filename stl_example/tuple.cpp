#include <iostream>
#include <tuple>
#include "tuple.h"

int main()
{
    std::tuple<int, double, std::string> t1(1, 1.2, "hello");
    std::cout << "第一个元素: " << std::get<0>(t1) << std::endl; // 输出：1

    Tuple<int, double, std::string, char> t2(42, 3.14, "Hello", 'A');
    std::cout << "第一个元素: " << get<0>(t2) << std::endl; // 输出：42
    std::cout << "第二个元素: " << get<1>(t2) << std::endl; // 输出：3.14
    std::cout << "第三个元素: " << get<2>(t2) << std::endl; // 输出：Hello
    std::cout << "第四个元素: " << get<3>(t2) << std::endl; // 输出：A
    return 0;
}