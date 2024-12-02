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
        bool correct = true;
        for (int i = 0; i < report.size(); i++) {
            correct = true;
            std::vector<int> new_report(report);
            new_report.erase(new_report.begin() + i);
            bool increasing = new_report[0] < new_report[1];
            int last_num = new_report[0];

            for (int j = 1; j < new_report.size(); j++) {
                if (increasing && new_report[j] <= last_num) {
                    correct = false;
                } else if (!increasing && new_report[j] >= last_num) {
                    correct = false;
                }
                int diff = abs(new_report[j] - last_num);
                if (diff < 1 || diff > 3) {
                    correct = false;
                }
                last_num = new_report[j];
            }
            if (correct) break;
        }
        if (correct) {
            total++;
        }
    }
    std::cout << total << std::endl;
}
