#include <cstddef>
#include <fstream>
#include <iostream>
#include <numeric>

void bubbleSort(std::vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (v[j] > v[j + 1])
                std::swap(v[j], v[j + 1]);
}

int main(int argc, char *argv[])
{
    if (argv[1] == NULL)
    {
        std::cout << "Provide path to file\n";
        return 0;
    }
    std::ifstream file(argv[1]);
    std::vector<int> v;
    int number;

    if (file.is_open())
    {
        while (file >> number)
            v.push_back(number);
        file.close();
    }
    else
        std::cout << "Can' open file" << std::endl;

    std::vector<int> v1;
    std::vector<int> v2;

    for (size_t i = 0; i < (v.size() - 1); i += 2)
    {
        v1.push_back(v[i]);
        v2.push_back(v[i + 1]);
    }

    bubbleSort(v1);
    bubbleSort(v2);

    std::vector<int> v3;
    for (int i = 0; i < v1.size(); i++)
        v3.push_back(abs(v1[i] - v2[i]));

    int result = std::reduce(v3.begin(), v3.end());
    std::cout << result << std::endl;
}
