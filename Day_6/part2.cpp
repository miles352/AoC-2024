#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>

constexpr int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool isLooping(int guard_row, int guard_col, std::vector<std::string> map) {
    int curr_direction = 0;
    std::vector<std::array<int, 2>> visited_positions;
    std::vector<int> visited_directions;
    while (true) {
        for (int i = 0; i < visited_positions.size(); i++) {
            std::array<int, 2> currPos{guard_row, guard_col};
            if (visited_positions[i] == currPos && visited_directions[i] == curr_direction) return true;
        }
        int index1 = guard_row + directions[curr_direction][0];
        int index2 = guard_col + directions[curr_direction][1];
        if (index1 < 0 || index1 >= map.size() || index2 < 0 || index2 >= map[0].length()) return false;
        if (map[index1][index2] == '#') {
            visited_positions.push_back({guard_row, guard_col});
            visited_directions.push_back(curr_direction);
            if (curr_direction == 3) {
                curr_direction = 0;
            } else {
                curr_direction++;
            }
        }
        guard_row += directions[curr_direction][0];
        guard_col += directions[curr_direction][1];
    }
}

int main() {
    std::ifstream file("../Day_6/input.txt");
    std::string str;

    std::vector<std::string> map;
    int guard_pos[2];
    int row = 0;
    while (std::getline(file, str)) {
        if (str.find('^') != std::string::npos) {
            guard_pos[0] = row;
            guard_pos[1] = str.find('^');
        }
        row++;
        map.push_back(str);
    }
    map[guard_pos[0]][guard_pos[1]] = '.';

    int total = 0;
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[0].length(); j++) {
            if (map[i][j] == '#' || (i == guard_pos[0] && j == guard_pos[1])) continue;
            std::vector<std::string> map_copy(map);
            map_copy[i][j] = '#';
            if (isLooping(guard_pos[0], guard_pos[1], map_copy)) {
                total++;
            }
        }
    }

    std::cout << total << std::endl;

}
