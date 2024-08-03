#include <iostream>

template <int N>
struct sum_integers
{
    static const int value = N + sum_integers<N - 1>::value;
};

template <>
struct sum_integers<0>
{
    static const int value = 0;
};

int main()
{
    std::cout << sum_integers<10>::value << std::endl;
    return 0;
}