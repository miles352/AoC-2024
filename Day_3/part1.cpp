#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>

int main() {
    std::ifstream file("../Day_3/input.txt");
    std::string str;

    int total = 0;
    while (std::getline(file, str)) {
        for (int i = str.find("mul("); i < str.length(); i = str.find("mul(", i + 1)) {
            std::string num1 = "";
            std::string num2 = "";
            int num2_start = 0;
            for (int j = i + 4; j < str.length(); j++) {
                if (str[j] == ',' && num1.length() > 0) {
                    num2_start = j + 1;
                    break;
                }
                if (std::isdigit(str[j])) {
                    num1 += str[j];
                } else {
                    break;
                }
            }
            bool failed = true;
            if (num2_start != 0) {
                for (int j = num2_start; j < str.length(); j++) {
                    if (str[j] == ')' && num2.length() > 0) {
                        failed = false;
                        break;
                    }
                    if (std::isdigit(str[j])) {
                        num2 += str[j];
                    } else {
                        break;
                    }
                }
            }
            if (!failed && (num1.length() <= 3 && num2.length() <= 3)) {
                total += std::stoi(num1) * std::stoi(num2);
            }
        }
    }
    std::cout << total;
}
