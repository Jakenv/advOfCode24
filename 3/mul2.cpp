#include <fstream>
#include <iostream>
#include <regex>
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

    std::stringstream ss;
    ss << file.rdbuf();
    std::string lines = ss.str();

    std::regex full_patt(R"(mul\((\d+),(\d+)\))");
    std::regex disabled_patt(R"(don't\(\)[\s\S]*?do\(\))");

    lines = std::regex_replace(lines, disabled_patt, "");
    std::sregex_iterator full(lines.begin(), lines.end(), full_patt);
    std::sregex_iterator end;
    int sum = 0;
    for (auto it = full; it != end; ++it)
    {
        std::smatch match = *it;
        int n1 = std::stoi(match[1]);
        int n2 = std::stoi(match[2]);
        sum += n1 * n2;
    }
    std::cout << sum << "\n";
}
