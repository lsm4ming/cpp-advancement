#include <iostream>

/*
问题：如何不使用final关键字，实现一个无法被继承的类

通过虚继承 + 友元类实现
*/

class Wapper
{
private:
    Wapper() = default;

    friend class CannotExtends;
};

class CannotExtends : virtual public Wapper
{
public:
    CannotExtends() = default;
};

// 编译不通过
// class MyExtends : public CannotExtends
// {
// public:
// };

int main()
{
    CannotExtends extends;
    return 0;
}