#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <vector>
#include <span>

enum expansion : char
{
    star = '#',
    vertical = '|',
    horizontal = '-',
    both = '+',
    none = '.'
};

void part1()
{
    std::ifstream file("2023/inputs/day11.txt");
    std::string line;
    std::vector<std::string> universe;
    while (std::getline(file, line))
    {
        universe.push_back(line);
    }
    // manually expand everything

    for (auto &row : universe)
    {
        // if all are ., then expand all to |

        bool all_none = true;
        for (auto &c : row)
        {
            if (c != none)
            {
                all_none = false;
                break;
            }
        }
        if (all_none)
        {
            for (auto &c : row)
            {
                c = horizontal;
            }
        }
    }

    // calculate the vertical ones
    for (int x = 0; x < universe.size(); x++)
    {
        bool all_none = true;
        for (int y = 0; y < universe[x].size(); y++)
        {
            if (universe[y][x] != none && universe[y][x] != horizontal)
            {
                all_none = false;
                break;
            }
        }

        if (all_none)
        {
            for (int y = 0; y < universe[x].size(); y++)
            {
                if (universe[y][x] == horizontal)
                    universe[y][x] = both;
                else
                    universe[y][x] = vertical;
            }
        }
    }

    // find all #'s and find all sum of length to each pair
    std::vector<std::pair<int, int>> star_locations;

    for (int y = 0; y < universe.size(); y++)
    {
        for (int x = 0; x < universe[y].size(); x++)
        {
            if (universe[y][x] == star)
            {
                star_locations.push_back({x, y});
            }
        }
    }
    //std::cout << "universe size: " << universe.size() << std::endl;
    //std::cout << "star loc size: " << star_locations.size() << std::endl;

    int total_sum = 0;

    for (int i = 0; i < star_locations.size(); i++)
    {
        for (int j = i + 1; j < star_locations.size(); j++)
        {
            int sum = 0;
            // iterate through the space, and give + a weight of 3, | a weight of 2, and - a weight of 2, and . a weight of 1
            int x1 = star_locations[i].first;
            int y1 = star_locations[i].second;
            const int x2 = star_locations[j].first;
            const int y2 = star_locations[j].second;
            // always going to go from 1->2
            //std::cout << "star: " << x1 << "," << y1 << " to " << x2 << "," << y2 << std::endl;
            while (x1 != x2 || y1 != y2)
            {
                //std::cout << "  checking: " << x1 << "," << y1 << std::endl;

                int weight = 0;
                if (universe[y1][x1] == star)
                    weight += 1;
                else if (universe[y1][x1] == vertical)
                    weight += 2;
                else if (universe[y1][x1] == horizontal)
                    weight += 2;
                else if (universe[y1][x1] == both)
                    weight += 3;
                else if (universe[y1][x1] == none)
                    weight += 1;

                sum += weight;
                //std::cout << "    weight: " << weight << std::endl;

                int dx = 0;
                int dy = 0;

                if (x1 != x2)
                {
                    if (x1 < x2)
                        dx++;
                    else
                        dx--;
                }
                else
                {
                    if (y1 < y2)
                        dy++;
                    else
                        dy--;
                }
                x1 += dx;
                y1 += dy;
            }

            //std::cout << "  the sum of pair, " << star_locations[i].first << "," << star_locations[i].second << " and " << star_locations[j].first << "," << star_locations[j].second << " is " << sum << std::endl;
            total_sum += sum;
        }
    }

    std::cout << total_sum << std::endl;

    //for (auto &row : universe)
    //{
        //std::cout << row << std::endl;
    //}
}

void part2()
{std::ifstream file("2023/inputs/day11.txt");
    std::string line;
    std::vector<std::string> universe;
    while (std::getline(file, line))
    {
        universe.push_back(line);
    }
    // manually expand everything

    for (auto &row : universe)
    {
        // if all are ., then expand all to |

        bool all_none = true;
        for (auto &c : row)
        {
            if (c != none)
            {
                all_none = false;
                break;
            }
        }
        if (all_none)
        {
            for (auto &c : row)
            {
                c = horizontal;
            }
        }
    }

    // calculate the vertical ones
    for (int x = 0; x < universe.size(); x++)
    {
        bool all_none = true;
        for (int y = 0; y < universe[x].size(); y++)
        {
            if (universe[y][x] != none && universe[y][x] != horizontal)
            {
                all_none = false;
                break;
            }
        }

        if (all_none)
        {
            for (int y = 0; y < universe[x].size(); y++)
            {
                if (universe[y][x] == horizontal)
                    universe[y][x] = both;
                else
                    universe[y][x] = vertical;
            }
        }
    }

    // find all #'s and find all sum of length to each pair
    std::vector<std::pair<int, int>> star_locations;

    for (int y = 0; y < universe.size(); y++)
    {
        for (int x = 0; x < universe[y].size(); x++)
        {
            if (universe[y][x] == star)
            {
                star_locations.push_back({x, y});
            }
        }
    }
    //std::cout << "universe size: " << universe.size() << std::endl;
    //std::cout << "star loc size: " << star_locations.size() << std::endl;

    unsigned long long total_sum = 0;

    for (int i = 0; i < star_locations.size(); i++)
    {
        for (int j = i + 1; j < star_locations.size(); j++)
        {
            int sum = 0;
            // iterate through the space, and give + a weight of 3, | a weight of 2, and - a weight of 2, and . a weight of 1
            int x1 = star_locations[i].first;
            int y1 = star_locations[i].second;
            const int x2 = star_locations[j].first;
            const int y2 = star_locations[j].second;
            // always going to go from 1->2
            //std::cout << "star: " << x1 << "," << y1 << " to " << x2 << "," << y2 << std::endl;
            while (x1 != x2 || y1 != y2)
            {
                //std::cout << "  checking: " << x1 << "," << y1 << std::endl;

                int weight = 0;
                if (universe[y1][x1] == star)
                    weight += 1;
                else if (universe[y1][x1] == vertical)
                    weight += 1000000;
                else if (universe[y1][x1] == horizontal)
                    weight += 1000000;
                else if (universe[y1][x1] == both)
                    weight += 1000000 * 2 -1;
                else if (universe[y1][x1] == none)
                    weight += 1;

                sum += weight;
                //std::cout << "    weight: " << weight << std::endl;

                int dx = 0;
                int dy = 0;

                if (x1 != x2)
                {
                    if (x1 < x2)
                        dx++;
                    else
                        dx--;
                }
                else
                {
                    if (y1 < y2)
                        dy++;
                    else
                        dy--;
                }
                x1 += dx;
                y1 += dy;
            }

            //std::cout << "  the sum of pair, " << star_locations[i].first << "," << star_locations[i].second << " and " << star_locations[j].first << "," << star_locations[j].second << " is " << sum << std::endl;
            total_sum += sum;
        }
    }

    std::cout << total_sum << std::endl;

}

int main(int argc, char **argv)
{
    std::span<char *> args(argv, argc);

    for (auto arg : args)
    {
        if (arg == std::string_view("1"))
            part1();
        else if (arg == std::string_view("2"))
            part2();
    }
    return 0;
}