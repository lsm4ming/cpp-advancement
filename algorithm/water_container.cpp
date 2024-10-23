#include <iostream>
#include <vector>

using Vector = std::vector<int>;

int getWaterWithPoint(int x, int y, const Vector &containers)
{
    return std::min(containers[x], containers[y]) * std::abs(x - y);
}

int getMaxWaterWithContainer(const Vector &containers)
{
    int max = 0;
    int i = 0;
    int j = (int) containers.size() - 1;
    while (i < j)
    {
        int temp = getWaterWithPoint(i, j, containers);
        if (temp > max)
        {
            max = temp;
        }
        if (containers[i] < containers[j])
        {
            i++;
        } else
        {
            j--;
        }
    }
    return max;
}

int main()
{
    std::cout << getMaxWaterWithContainer(Vector{1, 8, 6, 2, 5, 4, 8, 3, 7}) << std::endl;
    return 0;
}