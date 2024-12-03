#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>

int main() {
    std::ifstream file("../Day_3/input.txt");
    std::string str;

    int total = 0;
    bool mult_enabled = true;
    std::string full_text = "";
    while (std::getline(file, str)) {
        full_text += str;
    }

    for (int i = full_text.find("mul("); i < full_text.length(); i = full_text.find("mul(", i + 1)) {
        int do_command = full_text.substr(0, i).rfind("do()");
        int dont_command = full_text.substr(0, i).rfind("don't()");
        if (do_command != std::string::npos && dont_command != std::string::npos) {
            mult_enabled = (do_command > dont_command);
        } else if (do_command == std::string::npos && dont_command != std::string::npos) {
            mult_enabled = false;
        }

        if (!mult_enabled) continue;
        std::string num1 = "";
        std::string num2 = "";
        int num2_start = 0;
        for (int j = i + 4; j < full_text.length(); j++) {
            if (full_text[j] == ',' && num1.length() > 0) {
                num2_start = j + 1;
                break;
            }
            if (std::isdigit(full_text[j])) {
                num1 += full_text[j];
            } else {
                break;
            }
        }
        bool failed = true;
        if (num2_start != 0) {
            for (int j = num2_start; j < full_text.length(); j++) {
                if (full_text[j] == ')' && num2.length() > 0) {
                    failed = false;
                    break;
                }
                if (std::isdigit(full_text[j])) {
                    num2 += full_text[j];
                } else {
                    break;
                }
            }
        }
        if (!failed && (num1.length() <= 3 && num2.length() <= 3)) {
            total += std::stoi(num1) * std::stoi(num2);
        }
    }
    std::cout << total;
}
