#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>

int main() {
    std::ifstream file("../Day_2/input.txt");
    std::string str;

    int total = 0;

    while (std::getline(file, str)) {
        std::vector<int> report = std::vector<int>();
        int last_pos = 0;
        for (int i = str.find(' '); i < str.size(); i = str.find(' ', i + 1)) {
            int num = std::stoi(str.substr(last_pos, i));
            report.push_back(num);
            last_pos = i;
        }
        report.push_back(std::stoi(str.substr(last_pos)));

        bool increasing = report[0] < report[1];
        int last_num = report[0];
        bool correct = true;
        for (int i = 1; i < report.size(); i++) {
            if (increasing && report[i] <= last_num) {
                correct = false;
            } else if (!increasing && report[i] >= last_num) {
                correct = false;
            }
            int diff = abs(report[i] - last_num);
            if (diff < 1 || diff > 3) {
                correct = false;
            }
            last_num = report[i];
        }
        if (correct) {
            total++;
        }
    }
    std::cout << total << std::endl;
}
