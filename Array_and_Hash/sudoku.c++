#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_map<char, int> row;
            unordered_map<char, int> col;
            unordered_map<char, int> box;

            for (int j = 0; j < 9; j++) {
                // Check rows
                if (board[i][j] != '.') {
                    if (++row[board[i][j]] > 1) {
                        return false;
                    }
                }

                // Check columns
                if (board[j][i] != '.') {
                    if (++col[board[j][i]] > 1) {
                        return false;
                    }
                }

                // Check 3x3 sub-boxes using the following formula
                int boxRow = 3 * (i / 3) + j / 3;
                int boxCol = 3 * (i % 3) + j % 3;
                if (board[boxRow][boxCol] != '.') {
                    if (++box[board[boxRow][boxCol]] > 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

// Example usage
int main() {
    Solution solution;
    vector<vector<char>> board = {
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    bool result = solution.isValidSudoku(board);
    if (result) {
        printf("The Sudoku board is valid.\n");
    } else {
        printf("The Sudoku board is invalid.\n");
    }

    return 0;
}
