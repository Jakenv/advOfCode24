#include <fstream>
#include <iostream>
#include <sstream>

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
        std::vector<int> v;
        while (iss >> n)
            v.push_back(n);

        int size = (int)v.size();
        bool inc = true;
        bool dec = true;
        bool is_ok = true;
        for (int i = 0; i < size - 1; i++)
        {
            int diff = v[i + 1] - v[i];
            if (diff > 0)
                dec = false;
            if (diff < 0)
                inc = false;
            if (!(1 <= abs(diff) && abs(diff) <= 3))
                is_ok = false;
        }
        if (is_ok && (inc || dec))
            answer++;
    }
    std::cout << answer << "\n";
}
