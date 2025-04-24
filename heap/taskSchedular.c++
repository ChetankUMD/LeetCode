#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        queue<pair<int, int>> q; // {remaining_count, ready_time}
        priority_queue<int> max_heap;
        unordered_map<char, int> map;
        int time = 0;

        // Count frequency of each task
        for (auto task : tasks) {
            map[task]++;
        }

        // Add all frequencies to max heap
        for (auto m : map) {
            if (m.second > 0) {
                max_heap.push(m.second);
            }
        }

        // Simulation loop
        while (!max_heap.empty() || !q.empty()) {
            time++;

            // If no tasks available, jump time to the next available one
            if (max_heap.empty()) {
                time = q.front().second;
            } else {
                int count = max_heap.top() - 1;
                max_heap.pop();
                if (count > 0) {
                    q.push({count, time + n});
                }
            }

            // Re-insert any tasks that are ready to come off cooldown
            if (!q.empty() && q.front().second == time) {
                max_heap.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;

    int result = sol.leastInterval(tasks, n);

    cout << "Least interval required to finish all tasks: " << result << endl;

    return 0;
}