#include <unordered_set>
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
        unordered_set<char> unordSet;
        int ans = 0, i = 0, j = 0;
        while (i < len && j < len) {
            if (! (unordSet.find(s[j]) != unordSet.end())) {
                unordSet.insert(s[j++]);
                ans = max( ans, j - i);
            } else {
                unordSet.erase(s[i++]);
            }
        }
        return ans;
    }
};

int main() {
    unordered_set<char> subString;
    string word;
    cout << "Input a word: " << endl;
    cin >> word;
    Solution sl(word);
    int count = 0;
    count = sl.lengthOfLongestSubstring();
    cout << "count: " << count << endl;
}