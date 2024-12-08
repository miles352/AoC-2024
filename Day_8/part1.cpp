#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <unordered_map>

int main() {
    std::ifstream file("../Day_8/input.txt");
    std::string str;

    std::unordered_map<char, std::vector<std::array<int,2>>> frequencies;

    std::set<std::array<int,2>> antinodes;

    int row = 0;
    while (std::getline(file, str)) {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] != '.') {
                frequencies[str[i]].push_back({row, i});
            }
        }
        row++;
    }

    for (auto it = frequencies.begin(); it != frequencies.end(); it++) {
        std::vector<std::array<int,2>> nodes = it->second;
        for (int i = 0; i < nodes.size(); i++) {
            std::array<int, 2> point1 = nodes[i];
            for (int j = 0; j < nodes.size(); j++) {
                if (nodes[j] == point1) continue;
                std::array<int, 2> point2 = nodes[j];
                int dX = point2[0] - point1[0];
                int dY = point2[1] - point1[1];
                std::array<int, 2> antinode1 = {point1[0] + -dX, point1[1] + -dY};
                std::array<int, 2> antinode2 = {point2[0] + dX, point2[1] + dY};
                if (antinode1[0] >= 0 && antinode1[0] < row && antinode1[1] >= 0 && antinode1[1] < row) {
                    antinodes.insert(antinode1);
                }
                if (antinode2[0] >= 0 && antinode2[0] < row && antinode2[1] >= 0 && antinode2[1] < row) {
                    antinodes.insert(antinode2);
                }
            }
        }
    }

    std::cout << antinodes.size() << std::endl;


}
