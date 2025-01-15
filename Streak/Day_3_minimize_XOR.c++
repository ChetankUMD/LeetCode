#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int x_count = __builtin_popcount(num2); // Number of set bits in num2
        int x = 0;

        // First loop: Traverse from MSB to LSB, prioritize matching MSBs in num1
        for (int i = 31; i >= 0 && x_count > 0; --i) {
            if ((num1 & (1 << i)) != 0) { // If the i-th bit in num1 is set
                x |= (1 << i);           // Set the i-th bit in x
                --x_count;               // Decrease required set bits
            }
        }

        // Second loop: Fill remaining set bits in x from LSB upwards
        for (int i = 0; i < 32 && x_count > 0; ++i) {
            if ((x & (1 << i)) == 0) { // If the i-th bit in x is not set
                x |= (1 << i);        // Set the i-th bit in x
                --x_count;            // Decrease required set bits
            }
        }

        return x;
    }
};

int main() {
    Solution solution;

    // Test cases
    int num1_1 = 3, num2_1 = 5; // Expected output: 3
    int num1_2 = 1, num2_2 = 12; // Expected output: 3

    // Test Case 1
    std::cout << "Input: num1 = " << num1_1 << ", num2 = " << num2_1 << std::endl;
    std::cout << "Output: " << solution.minimizeXor(num1_1, num2_1) << std::endl;

    // Test Case 2
    std::cout << "Input: num1 = " << num1_2 << ", num2 = " << num2_2 << std::endl;
    std::cout << "Output: " << solution.minimizeXor(num1_2, num2_2) << std::endl;

    return 0;
}
