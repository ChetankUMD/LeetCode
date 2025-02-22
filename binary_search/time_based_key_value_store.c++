#include <iostream>
#include <map>
#include <vector>

using namespace std;

class TimeMap {
public:
    map<string, vector<pair<string, int>>> key_value;
    
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        key_value[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (key_value.find(key) == key_value.end()) return "";
        return search(key_value[key], timestamp);
    }

private:
    string search(vector<pair<string, int>>& list, int timestamp) {
        int n = list.size();
        int l = 0, h = n - 1, mid = 0;
        
        while (l <= h) {
            mid = l + (h - l) / 2;
            if (timestamp == list[mid].second) {
                return list[mid].first;
            }
            if (list[mid].second > timestamp) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return h >= 0 ? list[h].first : "";
    }
};

// Main function to test the TimeMap class
int main() {
    TimeMap* obj = new TimeMap();
    
    // Setting values
    obj->set("foo", "bar1", 1);
    obj->set("foo", "bar2", 3);
    obj->set("foo", "bar3", 5);
    
    // Getting values at different timestamps
    cout << obj->get("foo", 3) << endl;  // Expected output: "bar2"
    cout << obj->get("foo", 4) << endl;  // Expected output: "bar2"
    cout << obj->get("foo", 5) << endl;  // Expected output: "bar3"
    cout << obj->get("foo", 2) << endl;  // Expected output: "bar1"
    cout << obj->get("foo", 0) << endl;  // Expected output: ""

    delete obj;  // Clean up allocated memory
    return 0;
}