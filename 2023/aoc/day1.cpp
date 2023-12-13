#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <array>
#include <ranges>

const std::array<const std::string, 9> digits = {{"one",
                                                  "two",
                                                  "three",
                                                  "four",
                                                  "five",
                                                  "six",
                                                  "seven",
                                                  "eight",
                                                  "nine"}};

int main()
{
    std::ifstream file("inputs/day1.txt");

    int sum = 0;
    std::string line;
    int num{};
    while (std::getline(file, line))
    {
        int first = -1;
        int second = -1;
        for (int i = 0; i < line.size(); i++)
        {
            if (isdigit(line[i]))
            {
                num = atoi(std::string(&line[i], &line[i + 1]).c_str());

                if (first == -1)
                {
                    first = num * 10;
                    second = num;
                }
                else
                    second = num;
            }
            else
                for (int digit = 0; digit < digits.size(); digit++)
                {

                    std::string possible_num = std::string(line.begin() + i, std::min(line.begin() + i + digits[digit].size(), line.end()));
                    if (possible_num == digits[digit])
                    {
                        num = digit + 1;
                        if (first == -1)
                        {
                            first = num * 10;
                            second = num;
                        }
                        else
                            second = num;
                    }
                }
        }
        std::cout << line << ": " << first + second << std::endl;

        sum += first + second;
    }

    std::cout << "sum: " << sum << std::endl;
    return 0;
}