#include <iostream>
#define NOB_IMPLEMENTATION
#include "../nob.hpp"
#include <span>

int main(int argc, char *argv[])
{
    argc--;
    argv++;
    std::span args(argv, argc);

    for (auto &arg : args)
    {
        int sum = 0;
        for(int c = 0; arg[c] != '\0'; c++)
        {
            sum += arg[c];
        }
        std::cout << arg << ": ";
        std::cout << sum << std::endl;
    }

    return 0;
}