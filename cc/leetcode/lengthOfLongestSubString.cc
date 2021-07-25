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
        int ans = 0;
        for (int i =0; i < len; ++i)
            for (int j = i + 1; j <= len; ++j)
                if (allUnique(s, i, j)) ans = max (ans, j - i);
        return ans;
    }
    
    bool allUnique(string str, int start, int end) {
        unordered_set<char> unordSet;
        for (int i = start; i < end; ++i) {
            char ch = str[i];
            if (unordSet.find(ch) != unordSet.end())
                return false;
            unordSet.insert(ch);
        }
        return true;
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