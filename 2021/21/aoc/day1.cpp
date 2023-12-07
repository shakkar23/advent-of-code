#include <iostream>
#include <fstream>
#include <string>
#include <ranges>
std::array<std::string, 9> digits = {{"one",
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
    std::ifstream file("input.txt");

    int sum = 0;
    std::string line;
    while (std::getline(file, line))
    {
        auto pred = [](char c)
        {
            bool isdig = isdigit(c);

            if (!isdig)
            {
                //isdig = std::equal(digits.begin(), digits.end(), c);
            }

            return isdig;
        };

        auto iter = std::find_if(line.begin(), line.end(), pred);

        if (iter != line.end())
        {
            int num = std::stoi(std::string(iter, iter + 1));
            sum += num * 10;
            // std::cout << "found: " << num;
        }
        // now find the last digit
        auto last_digit = std::find_if(line.rbegin(), line.rend(), pred);
        if (last_digit != line.rend())
        {
            int num = std::stoi(std::string(last_digit, last_digit + 1));
            sum += num * 1;
            // std::cout << num << std::endl;
        }
    }

    std::cout << "sum: " << sum << std::endl;
    return 0;
}