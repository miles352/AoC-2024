#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>

int main() {
    std::ifstream file("../Day_1/input.txt");
    std::string str;

    std::vector<int> list1 = std::vector<int>();
    std::vector<int> list2 = std::vector<int>();
    while (std::getline(file, str)) {
        // parse into two lists
        list1.push_back(std::stoi(str.substr(0,str.find("   "))));
        list2.push_back(std::stoi(str.substr(str.find("   ") + 3)));
    }
    // sort both lists
    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());
    // loop lists and add differences to total
    int total = 0;
    for (int i = 0; i < list1.size(); i++) {
        total += abs(list1[i] - list2[i]);
    }
    std::cout << total << std::endl;
}
