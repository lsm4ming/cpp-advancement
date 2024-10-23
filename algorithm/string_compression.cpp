#include <iostream>

/**
字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串aabccccaaa会变为a2b1c5a3。若“压缩”后
的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母(a至z)。
 */

using String = std::string;

String stringCompression(const String &str)
{
    String result;
    for (int i = 0; i < str.length() - 1; ++i)
    {
        int count = 1;
        while (str[i] == str[i + 1])
        {
            count++;
            i++;
        }
        result += str[i];
        if (count > 1)
        {
            result += std::to_string(count);
        }
    }
    if (str.length() < result.length())
    {
        return str;
    }
    return result;
}

int main()
{
    std::cout << stringCompression("aabccccaaa") << std::endl;
    return 0;
}