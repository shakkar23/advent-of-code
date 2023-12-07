#include <iostream>

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
    std::string source = "aoc/day.cpp";
    char *year_num = nob_shift_args(&argc, &argv);
    char *day_num = nob_shift_args(&argc, &argv);
    source.insert(0, year_num);
    source.insert(11, day_num);
    std::string binary = "./.out";
    binary.insert(2, day_num);
    Nob_Cmd cmd;

    if (nob_file_exists(source.c_str()))
    {
        if (nob_needs_rebuild1(binary.c_str(), source.c_str()))
        {
            nob_cmd_append(cmd, "g++", "-ggdb", "-o", binary.c_str(), source.c_str(), NOB_CPPSTD_STR);
            system(("rm " + binary).c_str());
            nob_cmd_run_sync(cmd);
            cmd.clear();
        }
    }
    else
    {
        std::cout << "Day " << day_num << " not implemented yet." << std::endl;
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