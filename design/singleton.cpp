#include <iostream>
#include "singleton.h"

class SingletonTest
{
public:
    SingletonTest()
    {
        std::cout << "SingletonTest构造函数执行" << std::endl;
    }

    ~SingletonTest()
    {
        std::cout << "SingletonTest析构函数执行" << std::endl;
    }

    void sayHello()
    {
        std::cout << "Hello, World!" << std::endl;
    }
};

int main()
{
     std::cout << "开始执行" << std::endl;
    for (size_t i = 0; i < 10; i++)
    {
        SingletonTest &s1 = SingletonHelper<SingletonTest>::getInstance();
        s1.sayHello();
    }
    return 0;
}