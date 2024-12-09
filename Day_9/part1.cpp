#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
#include <fstream>

int main() {
    std::ifstream file("../Day_9/input.txt");
    std::string str;

    std::vector<int> expanded;

    std::getline(file, str);

    for (int i = 0; i < str.size(); i+=2) {
        int fileCount = str[i] - '0';
        int freeSpaceCount = str[i+1] - '0';
        int id = i / 2;
        for (int j = 0; j < fileCount; j++) {
            expanded.push_back(id);
        }
        for (int j = 0; j < freeSpaceCount; j++) {
            expanded.push_back(-1);
        }
    }

    while (true) {
        int first = std::find(expanded.begin(), expanded.end(), -1) - expanded.begin();
        int last;
        for (int i = expanded.size() - 1; i >= 0; i--) {
            if (expanded[i] != -1) {
                last = i;
                break;
            }
        }
        if (first > last) break;
        std::swap(expanded[first], expanded[last]);
    }

    long long total = 0;
    for (int i = 0; i < expanded.size(); i++) {
        if (expanded[i] == -1) break;
        total += expanded[i] * i;
    }

    std::cout << total;

}
