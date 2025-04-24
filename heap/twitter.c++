#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Twitter {
public:
    int count;
    unordered_map<int, vector<pair<int, int>>> tweets; // userId -> [{timestamp, tweetId}]
    unordered_map<int, set<int>> users; // followerId -> {followeeIds}

    Twitter() {
        count = 0; // we use decreasing count to simulate latest timestamps
    }

    // Post a tweet
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({count, tweetId});
        if (tweets[userId].size() > 10) {
            tweets[userId].erase(tweets[userId].begin()); // optional optimization: keep only 10 tweets
        }
        count--; // newer tweets have smaller timestamp
    }

    // Get 10 most recent tweet ids in the user's news feed
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        users[userId].insert(userId); // make sure the user follows themselves

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        // Optimization: if user follows 10 or more, pre-filter tweets using a maxHeap
        if (users[userId].size() >= 10) {
            priority_queue<vector<int>> maxHeap;

            for (auto f : users[userId]) {
                if (!tweets.count(f)) continue;

                int idx = tweets[f].size() - 1;
                auto& p = tweets[f][idx];
                maxHeap.push({-p.first, p.second, f, idx - 1});
                if (maxHeap.size() > 10) maxHeap.pop();
            }

            // Transfer to minHeap for final result construction
            while (!maxHeap.empty()) {
                auto t = maxHeap.top(); maxHeap.pop();
                minHeap.push({-t[0], t[1], t[2], t[3]});
            }

        } else {
            // Small number of followees — directly push latest tweets into minHeap
            for (auto f : users[userId]) {
                if (!tweets.count(f)) continue;

                int idx = tweets[f].size() - 1;
                auto& p = tweets[f][idx];
                minHeap.push({p.first, p.second, f, idx - 1});
            }
        }

        // K-way merge of tweets (max 10)
        while (!minHeap.empty() && res.size() < 10) {
            auto t = minHeap.top(); minHeap.pop();
            res.push_back(t[1]); // tweetId

            int idx = t[3];
            if (idx >= 0) {
                auto& p = tweets[t[2]][idx];
                minHeap.push({p.first, p.second, t[2], idx - 1});
            }
        }

        return res;
    }

    // Follow another user
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            users[followerId].insert(followeeId);
        }
    }

    // Unfollow a user
    void unfollow(int followerId, int followeeId) {
        if (users[followerId].count(followeeId)) {
            users[followerId].erase(followeeId);
        }
    }
};

int main() {
    Twitter twitter;

    twitter.postTweet(1, 5);                     // User 1 posts tweet 5
    vector<int> feed1 = twitter.getNewsFeed(1);  // User 1's news feed should return [5]

    twitter.follow(1, 2);                        // User 1 follows user 2
    twitter.postTweet(2, 6);                     // User 2 posts tweet 6

    vector<int> feed2 = twitter.getNewsFeed(1);  // Should return [6, 5]

    twitter.unfollow(1, 2);                      // User 1 unfollows user 2

    vector<int> feed3 = twitter.getNewsFeed(1);  // Should return [5]

    // Display feeds
    cout << "Feed 1: ";
    for (int id : feed1) cout << id << " ";
    cout << endl;

    cout << "Feed 2: ";
    for (int id : feed2) cout << id << " ";
    cout << endl;

    cout << "Feed 3: ";
    for (int id : feed3) cout << id << " ";
    cout << endl;

    return 0;
}