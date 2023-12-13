#include <iostream>
#include <format>

#define NOB_IMPLEMENTATION
#include "nob.hpp"

int main(int argc, char **argv)
{
    NOB_GO_REBUILD_URSELF(argc, argv);

    char *program = nob_shift_args(&argc, &argv);
    if (argc != 3)
    {
        std::cout << "Usage: " << program << " <year> <day> <part>" << std::endl;
        return 1;
    }
    char *year_num = nob_shift_args(&argc, &argv);
    char *day_num = nob_shift_args(&argc, &argv);
    std::string source = std::format("./{}/aoc/day{}.cpp", year_num, day_num);
    std::string binary = std::format("./{}/aoc/day{}.out", year_num, day_num);
    Nob_Cmd cmd;

    if (nob_file_exists(source.c_str()))
    {
        if (nob_needs_rebuild1(binary.c_str(), source.c_str()))
        {
            nob_cmd_append(cmd, CXX_COMPILER, "-ggdb", "-o", binary.c_str(), source.c_str(), NOB_CPPSTD_STR);
            system(("rm " + binary).c_str());
            nob_cmd_run_sync(cmd);
            cmd.clear();
        }
    }
    else
    {
        std::cout << "Day " << day_num << " not implemented yet." << std::endl;
        std::cout << "Create " << source << " and try again." << std::endl;
        return 1;
    }

    nob_cmd_append(cmd, binary.c_str());
    while (argc > 0)
    {
        cmd.push_back(nob_shift_args(&argc, &argv));
    }
    nob_cmd_run_sync(cmd);
    cmd.clear();

    return 0;
}