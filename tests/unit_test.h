#pragma once

#include <vector>
#include <iostream>
#include "test_case.h"

class UnitTest
{
private:
    std::vector<TestCase *> _tests;
    TestCase *currentTest{nullptr};

public:
    int totalCount{0};
    int successCount{0};
    int failCount{0};

private:
    UnitTest() = default;
    UnitTest(const UnitTest &) = delete;
    UnitTest(UnitTest &&) = delete;
    UnitTest &operator=(const UnitTest &) = delete;
    UnitTest &operator=(UnitTest &&) = delete;

public:
    ~UnitTest() = default;

    static UnitTest &getInstance()
    {
        static UnitTest instance;
        return instance;
    }

    // 注册单元测试案例
    void registerTest(TestCase *test);

    // 运行所有单元测试案例
    int run();
};

#define TAST_CASE_NAME(name) name##_TEST

#define UNIT_TEST(name)                                               \
    class TAST_CASE_NAME(name) : public TestCase                      \
    {                                                                 \
    public:                                                           \
        TAST_CASE_NAME(name)                                          \
        (const char *case_name)                                       \
        {                                                             \
            this->case_name = case_name;                              \
            UnitTest::getInstance().registerTest(this);               \
        }                                                             \
        void run() override;                                          \
        static const TAST_CASE_NAME(name) * t;                        \
    };                                                                \
    TAST_CASE_NAME(name)                                              \
    const *TAST_CASE_NAME(name)::t = new TAST_CASE_NAME(name)(#name); \
    void TAST_CASE_NAME(name)::run()

#define EXPECT_EQ(x, y)                           \
    UnitTest::getInstance().totalCount++;         \
    if ((x) != (y))                               \
    {                                             \
        UnitTest::getInstance().failCount++;      \
        std::cout << "Failed" << std::endl;       \
        std::cout << "Expect:" << x << std::endl; \
        std::cout << "Actual:" << y << std::endl; \
    }                                             \
    else                                          \
    {                                             \
        UnitTest::getInstance().successCount++;    \
        std::cout << "Success" << std::endl;      \
    }

#define RUN_ALL_TESTS() UnitTest::getInstance().run()