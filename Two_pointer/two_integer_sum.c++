#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0, j = n - 1;

        // Using two-pointer approach
        while(i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                // Return 1-based indices
                vector<int> temp;
                temp.push_back(i + 1);
                temp.push_back(j + 1);
                return temp;
            } else if (sum > target) {
                j--;
            } else {
                i++;
            }
        }

        // If no valid pair found, return empty
        return vector<int>();
    }
};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> numbers(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int target;
    cout << "Enter the target: ";
    cin >> target;

    Solution sol;
    vector<int> ans = sol.twoSum(numbers, target);

    if (!ans.empty()) {
        cout << "Indices are: " << ans[0] << " and " << ans[1] << endl;
    } else {
        cout << "No two numbers found that sum to the target.\n";
    }

    return 0;
}