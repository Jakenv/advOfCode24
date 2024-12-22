#include <algorithm>
#include <fstream>
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Provide path to file" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::cerr << "Can' open file" << std::endl;
        return 1;
    }

    std::vector<int> v1, v2;
    int a, b;
    while (file >> a >> b)
    {
        v1.push_back(a);
        v2.push_back(b);
    }
    file.close();

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    int distance = 0;
    for (int i = 0; i < v1.size(); i++)
        distance += abs(v1[i] - v2[i]);
    std::cout << "Distance is: " << distance << "\n";

    std::unordered_map<int, int> freq;
    for (int n : v2)
        freq[n]++;

    int score = 0;
    for (int n : v1)
        score += freq[n] * n;
    std::cout << "Similarity score is: " << score << "\n";

    return 0;
}
