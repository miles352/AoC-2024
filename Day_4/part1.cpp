#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
// yeah i wrote this after looking at the geeksforgeeks page

bool valid_coord(std::vector<std::string> ws, int row, int col) {
    return (row >= 0 && row < ws.size() && col >= 0 && col < ws.size());
}

bool word_search(int count, std::vector<std::string>& ws, std::string word, int row, int col, int rowDir, int colDir) {
    if (count == word.length()) return true;

    if (valid_coord(ws, row, col) &&  ws[row][col] == word[count]) {
        return word_search(count + 1, ws, word, row + rowDir, col + colDir, rowDir, colDir);
    }
    return false;
}

int main() {
    std::ifstream file("../Day_4/input.txt");
    std::string str;

    std::vector<std::string> ws;
    while (std::getline(file, str)) {
        ws.push_back(str);
    }

    int total = 0;


    for (int i = 0; i < ws.size(); i++) {
        for (int j = 0; j < ws.size(); j++) {
            // (-1, -1), (-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1)
            int directionX[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
            int directionY[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

            for (int k = 0; k < 8; k++) {
                if (word_search(0, ws, "XMAS", i, j, directionX[k], directionY[k])) total++;
            }
        }
    }


    std::cout << total;
}
