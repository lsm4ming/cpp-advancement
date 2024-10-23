#include <iostream>
#include <vector>
#include <unordered_map>

using Vector = std::vector<int>;

Vector numberSum(const Vector &numbers, int target)
{
    Vector result;
    std::unordered_map<int, int> map;
    for (int i = 0; i < numbers.size(); ++i)
    {
        map[numbers[i]] = i;
        int gap = target - numbers[i];
        auto find = map.find(gap);
        if (find == map.end())
        {
            continue;
        }
        return Vector{find->second, i};
    }
    return result;
}

int main()
{
    Vector result = numberSum({2, 5, 6, 7, 8, 19}, 15);
    for (auto &item: result)
    {
        std::cout << item << std::endl;
    }
    return 0;
}