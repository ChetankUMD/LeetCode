#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        const int n = favorite.size();
        vector<int> deg(n, 0);

        // Compute in-degrees for each node
        for (int x : favorite)
            deg[x]++;
        
        // Kahn's Algorithm to find the longest chain
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) q.push(i); // Add leaf nodes to the queue
        }

        vector<int> chain(n, 1);
        for (int d = 1; !q.empty(); d++) {
            int qz = q.size();
            for (int a = 0; a < qz; a++) {
                int i = q.front();
                q.pop();
                int j = favorite[i];
                chain[j] = max(d + 1, chain[j]);
                if (--deg[j] == 0) q.push(j); // Add new leaf nodes to the queue
            }
        }

        // Find the longest cycle and chains combined by 2-cycle
        int maxCycle = 0, join2cycle = 0;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) continue; // Skip visited nodes
            int cycleLen = 0;
            for (int j = i; deg[j] != 0; j = favorite[j]) {
                deg[j] = 0; // Mark as visited
                cycleLen++;
            }
            if (cycleLen > 2) {
                maxCycle = max(maxCycle, cycleLen);
            } else {
                join2cycle += chain[i] + chain[favorite[i]];
            }
        }

        return max(maxCycle, join2cycle);
    }
};

int main() {
    Solution solution;

    vector<int> favorite = {2, 2, 1, 2};
    int result = solution.maximumInvitations(favorite);

    cout << "Maximum number of employees that can be invited: " << result << endl;

    return 0;
}
