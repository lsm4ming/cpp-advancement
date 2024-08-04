#include <iostream>

/*
问题：如何调用类外的私有虚函数

通过直接访问虚函数表指针解决
*/

class A
{
public:
    virtual void f() = 0;
};

class B : public A
{
private:
    void f() override
    {
        std::cout << "虚函数执行" << std::endl;
    }
};

int main()
{
    B b;
    // 直接将b转为虚函数表指针
    long *vtbp = reinterpret_cast<long *>(&b);

    // 将虚函数表指针转为虚函数指针
    long *vtb = reinterpret_cast<long *>(*vtbp);

    // 调用虚函数
    auto f = reinterpret_cast<void (*)(void)> (*vtb);
    f();
    return 0;
}