#include <fstream>
#include <iostream>
#include <regex>

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

    std::regex pattern(R"(mul\((\d+),(\d+)\))");
    std::string line;
    int sum = 0;
    while (std::getline(file, line))
    {
        std::sregex_iterator it(line.begin(), line.end(), pattern);
        std::sregex_iterator end;
        while (it != end)
        {
            std::smatch match = *it;
            int n1 = std::stoi(match[1]);
            int n2 = std::stoi(match[2]);
            sum += n1 * n2;
            it++;
        }
    }
    std::cout << sum << "\n";
}
