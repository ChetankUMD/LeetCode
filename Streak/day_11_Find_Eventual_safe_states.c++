#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int n;
    vector<int> degreein;
    vector<vector<int>> rGraph;
    vector<int> ans;

    void init(vector<vector<int>>& G) {
        n = G.size();
        degreein = vector<int>(n, 0);
        rGraph.resize(n, vector<int>(0));

        for (int u = 0; u < n; u++) {
            for (int v : G[u]) {
                rGraph[v].push_back(u);
                degreein[u]++;
            }
        }
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        init(graph);
        queue<int> que;
        for (int i = 0; i < n; i++) {
            if (degreein[i] == 0) que.push(i);
        }
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            ans.push_back(u);
            for (int v : rGraph[u]) {
                degreein[v]--;
                if (degreein[v] == 0) que.push(v);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    // Example input
    vector<vector<int>> graph1 = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    vector<vector<int>> graph2 = {{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}};

    Solution sol;

    // Get safe nodes for the first graph
    vector<int> result1 = sol.eventualSafeNodes(graph1);
    cout << "Safe nodes for graph1: ";
    for (int node : result1) {
        cout << node << " ";
    }
    cout << endl;

    // Get safe nodes for the second graph
    vector<int> result2 = sol.eventualSafeNodes(graph2);
    cout << "Safe nodes for graph2: ";
    for (int node : result2) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
