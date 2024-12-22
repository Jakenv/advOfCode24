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

    std::vector<int> v;
    int n;
    while (file >> n)
        v.push_back(n);
    file.close();

    std::vector<int> v1, v2;
    for (int i = 0; i < v.size(); i++)
        (i % 2 == 0 ? v1 : v2).push_back(v[i]);

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
