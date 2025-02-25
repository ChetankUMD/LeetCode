#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp = 0;  // Stores the maximum profit
        int minp = INT_MAX;  // Stores the minimum price seen so far

        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] > minp) {
                maxp = max(maxp, prices[i] - minp);
            }
            minp = min(minp, prices[i]);
        }

        return maxp;
    }
};

// **Main Function**
int main() {
    Solution sol;
    
    // Example test case
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // Calling maxProfit function
    int result = sol.maxProfit(prices);

    // Output the result
    cout << "Maximum Profit: " << result << endl;

    return 0;
}