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

    int hight = 140;
    std::vector<std::string> vec(hight);
    for (std::string &row : vec)
    {
        file >> row;
    }
    int width = (int)vec[0].length();

    auto check = [&](int row, int col) { return 0 <= row && row < hight && 0 <= col && col < width; };

    std::string const XMAS = "XMAS";

    int answer = 0;
    for (int row = 0; row < hight; row++)
    {
        for (int col = 0; col < width; col++)
        {
            if (vec[row][col] == 'X')
            {
                for (int drow = -1; drow <= 1; drow++)
                {
                    for (int dcol = -1; dcol <= 1; dcol++)
                    {
                        if (drow == 0 && dcol == 0)
                            continue;
                        bool ok = true;
                        for (int i = 0; i < 4; i++)
                        {
                            int row2 = row + drow * i;
                            int col2 = col + dcol * i;
                            if (check(row2, col2) && vec[row2][col2] == XMAS[i])
                            {
                            }
                            else
                            {
                                ok = false;
                                break;
                            }
                        }
                        answer += ok;
                    }
                }
            }
        }
    }
    std::cout << answer << "\n";
}
