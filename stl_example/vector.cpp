#include <iostream>
#include "vector.h"

int main()
{
    Vector<int> v;
    for (size_t i = 0; i < 100; i++)
    {
        v.push_back(i);
    }
    std::cout << v.size() << std::endl;

    Vector<int> v2{1, 2, 3, 4, 5};
    std::cout << v2.size() << std::endl;
    return 0;
}