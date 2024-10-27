#include <iostream>
#include <regex>
#include <fstream>

int main()
{
    std::ifstream file("index.html");

    if (!file)
    {
        std::cerr << "无法打开文件!" << std::endl;
        return 1;
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string html = buffer.str();
    file.close();

    std::regex pattern(
            R"delimiter(<li[^>]*class="news-meta-item clearfix"[^>]*>\s*<a[^>]*href="([^"]*)"[^>]*>.*?<!--\d+-->.*?<!--\d+--><span[^>]*>([^<]*)</span>.*?</a>\s*</li>)delimiter");

    // 匹配所有结果
    auto begin = std::sregex_iterator(html.begin(), html.end(), pattern);
    auto end = std::sregex_iterator();

    std::cout << "找到的匹配项数量: " << std::distance(begin, end) << std::endl;

    // 遍历所有匹配
    for (std::sregex_iterator i = begin; i != end; ++i)
    {
        const std::smatch &match = *i;
        std::string href = match[1].str();
        std::string text = match[2].str();

        std::cout << "Href: " << href << std::endl;
        std::cout << "Text: " << text << std::endl;
    }
    return 0;
}