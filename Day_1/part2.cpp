#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>

int main() {
    std::ifstream file("../Day_1/input.txt");
    std::string str;

    std::vector<int> list1 = std::vector<int>();
    std::unordered_map<int, int> count;
    while (std::getline(file, str)) {
        list1.push_back(std::stoi(str.substr(0,str.find("   "))));
        int num2 = std::stoi(str.substr(str.find("   ") + 3));
        count[num2]++;
    }
    int total = 0;
    for (int num : list1) {
        total += num * count[num];
    }
    std::cout << total << std::endl;
}
