#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>


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
    int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int curr_direction = 0;
    while (guard_pos[0] >= 0 && guard_pos[0] < map.size() && guard_pos[1] >= 0 && guard_pos[1] < map[0].length()) {
        map[guard_pos[0]][guard_pos[1]] = 'a';
        int index1 = guard_pos[0] + directions[curr_direction][0];
        int index2 = guard_pos[1] + directions[curr_direction][1];
        if (index1 < 0 || index1 >= map.size() || index2 < 0 || index2 >= map[0].length()) break;
        if (map[index1][index2] == '#') {
            if (curr_direction == 3) {
                curr_direction = 0;
            } else {
                curr_direction++;
            }
        }
        guard_pos[0] += directions[curr_direction][0];
        guard_pos[1] += directions[curr_direction][1];
    }

    int total = 0;
    for (std::string str : map) {
        for (char c : str) {
            if (c == 'a') total++;
        }
    }
    std::cout << total << std::endl;

}
