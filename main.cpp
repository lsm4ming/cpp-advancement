#include <iostream>
#include <boost/filesystem.hpp>

int main()
{
    std::cout << "Hello, World!" << std::endl;

    boost::filesystem::path current_dir(".");

    if (boost::filesystem::exists(current_dir) &&
        boost::filesystem::is_directory(current_dir))
    {
        std::cout << "Current directory contents:\n";
        for (const auto& entry : boost::filesystem::directory_iterator(current_dir))
        {
            std::cout << entry.path().filename().string() << std::endl;
        }
    } else
    {
        std::cerr << "Invalid directory!" << std::endl;
    }
    return 0;
}