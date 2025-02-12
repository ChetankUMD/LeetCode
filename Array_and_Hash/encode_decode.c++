#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Codec {
public:
        string encode(vector<string>& strs) {
       string res;

       for(auto s : strs){
            int size = s.length();
            string str_size = to_string(size);
            res.append(str_size+'#'+s);
       }
       return res;
    }

    vector<string> decode(string s) {
        string str;
        vector<string> res;
        int i =0;
        while(i<s.size()){
            int hash = s.find('#',i);
            int length = stoi(s.substr(i , hash - i));
            string str = s.substr(hash + 1,length);
            res.push_back(str);
            i = hash + 1 + length;
        }
        return res;

        // int count = 0;
        // for(int i=0; i<s.length();i++){
        //     if(s[i]=='#' && isdigit(s[i-1])){

        //         count = s[i-1] - '0';
        //         cout << count;
        //         for(;count+1>0;++i, count--){
        //             str += s[i];
        //         }
        //     }
        //     str.erase(0, 1);
        //     res.push_back(str);
        //     str = "";
        // }
        // res.erase(res.begin());
        // return res;

        // for(int i = 0; i< s.length();i++){
            
        //     if(s[i] == '#'){
        //         if (!str.empty() && str[0] == '#') {
        //         str.erase(0, 1);
        //     }
        //     res.push_back(str);
        //     str = "";
        //     }
        //     str += s[i];
        // }
        // return res;
    }
};

int main() {
    Codec codec;

    vector<string> input1 = {"neet", "code", "love", "you"};
    string encoded1 = codec.encode(input1);
    vector<string> decoded1 = codec.decode(encoded1);
    cout << "Encoded: " << encoded1 << endl;
    cout << "Decoded: ";
    for (const string& str : decoded1) {
        cout << str << " ";
    }
    cout << endl;

    vector<string> input2 = {"we", "say", ":", "yes"};
    string encoded2 = codec.encode(input2);
    vector<string> decoded2 = codec.decode(encoded2);
    cout << "Encoded: " << encoded2 << endl;
    cout << "Decoded: ";
    for (const string& str : decoded2) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}
