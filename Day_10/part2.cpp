#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
#include <fstream>

constexpr int directions[4][2]  = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int trailheadScore(std::vector<std::string> map, int i, int j, int dirX, int dirY) {
    if (i + dirY >= map.size() || j + dirX >= map[0].size() || i + dirY < 0 || j + dirX < 0) return 0;
    if (map[i][j] - '0' == map[i + dirY][j + dirX] - '0' - 1) {
        if (map[i + dirY][j + dirX] - '0' == 9) {
            return 1;
        }
        int total = 0;
        for (int k = 0; k < 4; k++) {
            total += trailheadScore(map, i + dirY, j + dirX, directions[k][0], directions[k][1]);
        }
        return total;
    }
    return 0;
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
            if (map[i][j] - '0' == 0) {
                for (int k = 0; k < 4; k++) {
                    total += trailheadScore(map, i, j, directions[k][0], directions[k][1]);
                }
            }
        }
    }

    std::cout << total;
}
