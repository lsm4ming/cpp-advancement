#include <iostream>
#include <vector>

/**
输入一个字符串，打印出该字符串中字符的所有排列。
你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
*/

using String = std::string;
using Vector = std::vector<String>;

Vector stringArrange(const String &str)
{
    Vector result;
    if (str.empty())
    {
        return result;
    } else if (str.length() == 1)
    {
        return Vector{str};
    } else
    {
        for (int i = 0; i < str.length(); ++i)
        {
            auto list = stringArrange(str.substr(0, i) + str.substr(i + 1));
            for (const auto &s: list)
            {
                result.push_back(str[i] + s);
            }
        }
        return result;
    }
}

int main()
{
    auto list = stringArrange("abc");
    for (const auto &s: list)
    {
        std::cout << s << std::endl;
    }
    return 0;
}