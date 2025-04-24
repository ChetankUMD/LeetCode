#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max heap: stores pair<distance, point>
        priority_queue<pair<double, vector<int>>> distance;
        vector<vector<int>> res;

        for(int i = 0; i < points.size(); i++){
            double dis = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            distance.push({dis, points[i]});

            if(distance.size() > k) {
                distance.pop(); // Remove farthest if heap grows beyond k
            }
        }

        // Extract k closest points
        while (!distance.empty()) {
            res.push_back(distance.top().second);
            distance.pop();
        }

        return res;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<vector<int>> points = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int k = 2;

    vector<vector<int>> result = sol.kClosest(points, k);

    cout << "The " << k << " closest points to the origin are:" << endl;
    for (const auto& point : result) {
        cout << "[" << point[0] << ", " << point[1] << "]" << endl;
    }

    return 0;
}