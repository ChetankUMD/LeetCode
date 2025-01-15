#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> res(n, 0); // Initialize the result vector with all 0s
        stack<int> stk; // Monotonic decreasing stack to store indices

        for (int i = 0; i < n; i++) {
            // Process the stack while current temperature is greater than the temperature at the index on the stack top
            while (!stk.empty() && temp[i] > temp[stk.top()]) {
                int prevDay = stk.top(); // Get the index of the previous day
                stk.pop(); // Remove the index from the stack
                res[prevDay] = i - prevDay; // Calculate the number of days to a warmer temperature
            }
            stk.push(i); // Push the current index onto the stack
        }

        return res; // Return the result vector
        // int count = 0;
        // int n = temp.size();
        // vector<int> res(n, 0);

        // for(int i=0;i<n;i++){
        //     for(int j = i+1; j<n; j++){
        //         if(temp[i] < temp[j]){
        //             count = j - i;
        //             break;
        //         }
        //     }
        //     res[i] = count;
        //     count = 0;
        // }
        // return res;
    }
};

// Helper function to display the result
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = solution.dailyTemperatures(temperatures);

    cout << "Daily Temperatures Result: ";
    printVector(result);

    return 0;
}