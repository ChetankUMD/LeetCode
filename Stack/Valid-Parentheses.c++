#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        if(s[0] == ')' || s[0] == ']' || s[0] == '}') return false;
        for(auto st :s ){
            if(st == '(' || st == '[' || st == '{'){ // push the open brackets
                sta.push(st);
            }else{
                if(sta.empty()) {
                    return false;
                }
                char re = sta.top(); // check for chosing brakets
                if(st == ')' && re == '('){
                    sta.pop();
                    continue;
                }
                else if(st == ']' && re == '['){
                    sta.pop();
                    continue;
                }
                else if(st == '}' && re == '{'){
                    sta.pop();
                }
                else return false;
            }
        }
        if(sta.empty()){
            return true;
        }
        return false;
    }
};

int main() {
    Solution solution;

    // Test cases
    string test1 = "()[]{}";
    cout << "Test 1: " << solution.isValid(test1) << endl; // Output: 1 (true)

    string test2 = "(]";
    cout << "Test 2: " << solution.isValid(test2) << endl; // Output: 0 (false)

    string test3 = "([)]";
    cout << "Test 3: " << solution.isValid(test3) << endl; // Output: 0 (false)

    string test4 = "{[]}";
    cout << "Test 4: " << solution.isValid(test4) << endl; // Output: 1 (true)

    string test5 = "[";
    cout << "Test 5: " << solution.isValid(test5) << endl; // Output: 0 (false)

    return 0;
}
