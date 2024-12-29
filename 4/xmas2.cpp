#include <fstream>
#include <iostream>
#include <vector>

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

    int hight = 140;
    std::vector<std::string> vec(hight);
    for (std::string &row : vec)
        file >> row;

    int width = (int)vec[0].length();
    const std::vector<std::pair<int, int>> directions = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

    int answer = 0;
    for (int row = 1; row < hight - 1; row++)
    {
        for (int col = 1; col < width - 1; col++)
        {
            if (vec[row][col] == 'A')
            {
                std::string s;
                for (std::pair<int, int> direction : directions)
                    s += vec[row + direction.first][col + direction.second];
                if (s == "MMSS" || s == "MSSM" || s == "SMMS" || s == "SSMM")
                    answer++;
            }
        }
    }
    std::cout << answer << "\n";
}
