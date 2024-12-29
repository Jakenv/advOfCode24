#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

bool check(std::vector<int> v1)
{
    int size = (int)v1.size();
    bool inc = true;
    bool dec = true;
    bool is_ok = true;
    for (int j = 0; j < size - 1; j++)
    {
        int diff = v1[j + 1] - v1[j];
        if (diff > 0)
            dec = false;
        if (diff < 0)
            inc = false;
        if (!(1 <= abs(diff) && abs(diff) <= 3))
            is_ok = false;
    }
    return is_ok && (inc || dec);
}

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

    int answer = 0;
    std::string line;
    while (getline(file, line))
    {
        std::istringstream iss(line);
        int n;
        std::vector<int> v1;
        while (iss >> n)
            v1.push_back(n);
        bool correct = false;
        auto remove = [&](int i) {
            std::vector<int> v2 = v1;
            v2.erase(v2.begin() + i);
            if (check(v2))
                correct = true;
        };

        int v1size = (int)v1.size();
        remove(0);
        for (int i = 0; i < v1size - 1; i++)
        {
            int diff = v1[i + 1] - v1[i];
            if (abs(diff) < 1 || abs(diff) > 3)
            {
                remove(i);
                remove(i + 1);
                break;
            }
            if (i + 2 < v1size)
            {
                int diff2 = v1[i + 2] - v1[i + 1];
                if ((diff > 0) != (diff2 > 0))
                {
                    remove(i);
                    remove(i + 1);
                    remove(i + 2);
                    break;
                }
            }
        }
        if (correct)
            answer++;
    }
    std::cout << answer << "\n";
}
