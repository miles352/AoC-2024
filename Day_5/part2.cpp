#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>


int main() {
    std::ifstream file("../Day_5/input.txt");
    std::string str;

    std::unordered_map<int, std::vector<int>> rules;
    // get rules
    while (std::getline(file, str)) {
        if (str.empty()) break;
        int num1 = std::stoi(str.substr(0, 2));
        int num2 = std::stoi(str.substr(3));
        rules[num1].push_back(num2);
    }

    int total = 0;

    // do updates
    while (std::getline(file, str)) {
        std::vector<int> update;
        // construct the update
        for (int i = 0; i < str.length(); i+=3) {
            update.push_back(std::stoi(str.substr(i, 2)));
        }

        // find incorrect ones
        bool correct = true;
        for (int i = 0; i < update.size(); i++) {
            for (int page : rules[update[i]]) {
                if (std::find(update.begin(), update.end(), page) - update.begin() < i) correct = false;
            }
        }

        // sort them
        // this sorts them backwards lol but the problem only cares about middle so whatever
        if (!correct) {
            for (int i = 0; i < update.size(); i++) {
                for (int j = 0; j < update.size(); j++) {
                   for (int page : rules[update[i]]) {
                       int index = std::find(update.begin(), update.end(), page) - update.begin();
                       if (index != update.size() && index > i) std::swap(update[index], update[i]);
                   }
                }
            }
            total += update[update.size() / 2];
        }

    }

    std::cout << total;
}
