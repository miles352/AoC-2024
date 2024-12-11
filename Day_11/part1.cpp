#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
#include <fstream>

std::vector<std::string> blink(std::vector<std::string> stones) {
    std::vector<std::string> newStones;
    for (long long i = 0; i < stones.size(); i++) {
        long long stoneVal = std::stoll(stones[i]);
        if (stoneVal == 0) {
            newStones.push_back("1");
        } else if (stones[i].length() % 2 == 0) {
            std::string stoneHalf = stones[i].substr(0, stones[i].length() / 2);
            std::string otherHalf = stones[i].substr(stones[i].length() / 2);
            while (otherHalf[0] - '0' == 0) {
                if (otherHalf.size() == 1) break;
                otherHalf = otherHalf.substr(1);
            }
            newStones.push_back(stoneHalf);
            newStones.push_back(otherHalf);
        } else {
            newStones.push_back(std::to_string(std::stoll(stones[i]) * 2024));
        }
    }
    return newStones;
}

int main() {
    std::ifstream file("../Day_11/input.txt");
    std::string str;

    std::vector<std::string> stones;

    std::getline(file, str);

    std::string temp;
    for (long long i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            stones.push_back(temp);
            temp = "";
        } else {
            temp += str[i];
        }
    }
    stones.push_back(temp);

    for (long long i = 0; i < 75; i++) {
        stones = blink(stones);
    }

    std::cout << stones.size();

}