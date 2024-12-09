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

    // initiate loop hell
    for (int i = expanded.size() - 1; i >= 0; i--) {
        if (expanded[i] != -1) {
            int count = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (expanded[j] == expanded[i]) {
                    count++;
                } else break;
            }
            for (int j = 0; j < expanded.size(); j++) {
                if (i < j) break;
                if (expanded[j] == -1) {
                    int emptyCount = 1;
                    for (int k = j + 1; k < expanded.size(); k++) {
                        if (expanded[k] == -1) {
                            emptyCount++;
                        } else break;
                    }
                    if (emptyCount >= count) {
                        for (int k = 0; k < count; k++) {
                            std::swap(expanded[j+k], expanded[i-k]);
                        }
                        break;
                    }
                }
            }
            i -= count - 1;
        }
    }

    long long total = 0;
    for (int i = 0; i < expanded.size(); i++) {
        if (expanded[i] == -1) continue;
        total += expanded[i] * i;
    }

    std::cout << total;

}
