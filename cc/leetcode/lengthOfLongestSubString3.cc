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
        int ans = 0;
        for (int j =0, i = 0; j < len; ++j) {
            cout << "j: " << j << " ";
            auto result = unordMap.find(s[j]);
            if (result != unordMap.end()) {
                i = max (result->second, i);
                result->second = j + 1;
                cout << "i: " << i << " ";
            } else {
                unordMap.insert({s[j], j + 1});
            }
            ans = max (ans, j - i + 1);
            cout << "ans: " << ans << endl;
            for (auto &elem : unordMap) {
                cout << "key: " << elem.first << "\t"
                    << "value: " << elem.second << endl;
            }
            cout << "-----------" << endl;
        }
        return ans;
    }
};

int main() {
    string word;
    cout << "Input a word: " << endl;
    cin >> word;
    Solution sl(word);
    int count = 0;
    count = sl.lengthOfLongestSubstring();
    cout << "count: " << count << endl;
}