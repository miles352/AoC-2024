#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
#include <fstream>
#include <set>

constexpr int directions[4][2]  = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

std::set<std::array<int,2>> trailheadScore(std::vector<std::string> map, int i, int j, int dirX, int dirY, std::set<std::array<int,2>> matches) {
    if (i + dirY >= map.size() || j + dirX >= map[0].size() || i + dirY < 0 || j + dirX < 0) return matches;
    if (map[i][j] - '0' == map[i + dirY][j + dirX] - '0' - 1) {
        if (map[i + dirY][j + dirX] - '0' == 9) {
            matches.insert({i + dirY, j + dirX});
            return matches;
        }
        for (int k = 0; k < 4; k++) {
            std::set<std::array<int,2>> match = trailheadScore(map, i + dirY, j + dirX, directions[k][0], directions[k][1], matches);
            matches.insert(match.begin(), match.end());
        }
        return matches;
    }
    return matches;
}

int main() {
    std::ifstream file("../Day_10/input.txt");
    std::string str;

    std::vector<std::string> map;

    while (std::getline(file, str)) {
        map.push_back(str);
    }

    int total = 0;

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            std::set<std::array<int,2>> matches;
            if (map[i][j] - '0' == 0) {
                for (int k = 0; k < 4; k++) {
                    matches = trailheadScore(map, i, j, directions[k][0], directions[k][1], matches);
                }
                total += matches.size();
            }
        }
    }

    std::cout << total;
}