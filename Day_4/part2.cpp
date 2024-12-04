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

    // for each A, check 4 corners, 2 are Xmas return true


    for (int i = 0; i < ws.size(); i++) {
        for (int j = 0; j < ws.size(); j++) {

            if (ws[i][j] == 'A') {
                // (-1, -1), (-1, 1), (1, -1), (1, 1)
                int directionX[] = { -1, -1, 1, 1 };
                int directionY[] = { -1, 1, -1, 1 };

                int mas = 0;
                for (int k = 0; k < 4; k++) {
                    if (word_search(0, ws, "MAS", i + directionX[k], j + directionY[k], -directionX[k], -directionY[k])) {
                        mas++;
                    }
                }
                if (mas == 2) total++;
            }

        }
    }


    std::cout << total;
}
