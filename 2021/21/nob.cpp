#include <iostream>

#define NOB_IMPLEMENTATION
#include "nob.hpp"

int main(int argc, char **argv)
{
    NOB_GO_REBUILD_URSELF(argc, argv);

    char *program = nob_shift_args(&argc, &argv);
    std::string source = "aoc/day.cpp";
    char *day_num = nob_shift_args(&argc, &argv);
    source.insert(7, day_num);

    Nob_Cmd cmd;

    if (nob_needs_rebuild1("./a.out", source.c_str()))
    {
        nob_cmd_append(cmd, "g++", "-ggdb", "-o", "a.out", source.c_str(), NOB_CPPSTD_STR);
        system("rm ./a.out");
        nob_cmd_run_sync(cmd);
        cmd.clear();
    }

    nob_cmd_append(cmd, "./a.out");
    nob_cmd_run_sync(cmd);
    cmd.clear();

    return 0;
}