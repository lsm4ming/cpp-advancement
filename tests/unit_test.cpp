#include "unit_test.h"

void UnitTest::registerTest(TestCase *test)
{
    getInstance()._tests.push_back(test);
}

int UnitTest::run()
{
    std::cout << "----------开始执行单元测试,共" << getInstance()._tests.size() << "个----------" << std::endl;
    for (auto t : getInstance()._tests)
    {
        std::cout << "----------开始执行第" << getInstance()._tests.size() << "个测试----------" << std::endl;
        getInstance().currentTest = t;
        t->run();
    }
    getInstance().currentTest = nullptr;
    std::cout << "----------单元测试结束----------" << std::endl;
    std::cout << "----------total=" << getInstance().totalCount << "----------" << std::endl;
    std::cout << "----------success=" << getInstance().successCount << "----------" << std::endl;
    std::cout << "----------fail=" << getInstance().failCount << "----------" << std::endl;
    return 0;
}
