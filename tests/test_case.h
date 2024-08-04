#pragma once

#include <string>

class TestCase
{
protected:
    std::string case_name;
    int run_result{0};

public:
    virtual void run() = 0;

    int get_run_result() const
    {
        return run_result;
    }

    std::string get_case_name() const
    {
        return case_name;
    }
};