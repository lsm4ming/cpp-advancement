#include <iostream>
#include "unit_test.h"

template <typename T>
int add(T a, T b)
{
    return a + b;
}

UNIT_TEST(Base_add)
{
    EXPECT_EQ(1, add(1, 0));
}

int main()
{
    return RUN_ALL_TESTS();
}