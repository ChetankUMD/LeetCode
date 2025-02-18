#include <iostream>
#include <vector>
#include <algorithm> // For max_element
#include <cmath>     // For ceil function

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, mid = 0;
        int hi = *max_element(piles.begin(), piles.end()); // Maximum pile size
        int res = hi;

        while (l <= hi) {
            mid = l + (hi - l) / 2; // Prevents overflow
            long long sum = 0;

            // Calculate total time needed for the given speed
            for (int pile : piles) {
                sum += ceil(static_cast<double>(pile) / mid);
            }

            // If we can finish within h hours, try lower speeds
            if (sum <= h) {
                res = mid;
                hi = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    int result = sol.minEatingSpeed(piles, h);
    cout << "Minimum eating speed: " << result << endl;

    return 0;
}