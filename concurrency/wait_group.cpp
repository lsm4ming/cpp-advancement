#include <iostream>
#include <thread>
#include "wait_group.h"

int main()
{
    WaitGroup wg;
    for (size_t i = 0; i < 10; i++)
    {
        wg.add();
        std::thread t = std::thread([&wg]
                                    {
            std::cout << "Hello, World!" << std::endl;
            wg.done(); });
        t.detach();
    }
    wg.wait();
    std::cout << "执行结束" << std::endl;
    return 0;
}