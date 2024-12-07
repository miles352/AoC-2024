#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>

bool calibrate(long long target, std::vector<long long> values, long long total) {
    if (values.empty()) return target == total;

    // if + or * or mashing them together is true, return true
    std::vector<long long> new_values(values.begin() + 1, values.end());
    if (calibrate(target, new_values, total + values[0]) ||
        calibrate(target, new_values, total * values[0]) ||
        calibrate(target, new_values, std::stoll(std::to_string(total) + std::to_string(values[0])))) return true;
    return false;
}

int main() {
    std::ifstream file("../Day_7/input.txt");
    std::string str;

    long long total = 0;

    while (std::getline(file, str)) {
        int seperator = str.find(':');
        long long target = std::stoll(str);
        std::vector<long long> values;
        std::string temp = "";
        for (int i = seperator + 2; i < str.length(); i++) {
            if (str[i] == ' ') {
                values.push_back(std::stoll(temp));
                temp = "";
            } else {
                temp += str[i];
            }
        }
        values.push_back(std::stoll(temp));

        std::vector<long long> new_values(values.begin() + 1, values.end());
        if (calibrate(target, new_values, values[0])) total += target;
    }

    std::cout << total << std::endl;

}
