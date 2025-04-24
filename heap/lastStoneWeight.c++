#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxheap;

        // Push all stones into the max heap
        for (auto st : stones) {
            maxheap.push(st);
        }

        int res;
        // While more than one stone remains
        while (maxheap.size() > 1) {
            int st1 = maxheap.top(); maxheap.pop();
            int st2 = maxheap.top(); maxheap.pop();
            res = abs(st1 - st2);

            // If not equal, push the result back into the heap
            if (res != 0) {
                maxheap.push(res);
            }
        }

        // If the heap is empty, return 0; otherwise, return the remaining stone
        return maxheap.empty() ? 0 : maxheap.top();
    }
};

int main() {
    vector<int> stones = {2, 7, 4, 1, 8, 1};

    Solution sol;
    int result = sol.lastStoneWeight(stones);

    cout << "Last stone weight is: " << result << endl;

    return 0;
}