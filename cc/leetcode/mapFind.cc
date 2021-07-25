#include <unordered_map>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    string s;
    Solution(string str) : s(str) {};
    int lengthOfLongestSubstring() {
        int len = s.size();
        unordered_map<char,int> unordMap;
        int ans = 0, i = 0, j = 0;
        for (; j < len; ++j) {
            
            cout << "j: " << j << endl;
            unordMap.insert({s[j],j});
            for (auto &elem : unordMap) {
            cout << "key: " << elem.first << "\t"
                 << "value: " << elem.second << endl;
        }
            
            //cout << "result: " << result << endl;
        }
        // for (auto &elem : unordMap) {
        //     cout << "key: " << elem.first << "\t"
        //          << "value: " << elem.second << endl;
        // }
        auto result = unordMap.find(s[0]);
        cout << "result: " << result->first << " " << result->second << endl;
        return ans;
    }
};

int main() {
    //unordered_map<char,int> subString;
    string word;
    cout << "Input a word: " << endl;
    cin >> word;
    Solution sl(word);
    int count = 0;
    count = sl.lengthOfLongestSubstring();
    cout << "count: " << count << endl;
}