#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    string myStr;
    Solution(string str) : myStr(str) {};
    string longestPalindrome() {
        cout << "myStr: " << myStr << endl;
        if ( myStr.empty() ) cout << "empty" << endl;
        int start = 0, end= 0;
        for (int i = 0; i < myStr.size(); ++i) {
            int len1 = expandAroundCenter(myStr, i, i);
            int len2 = expandAroundCenter(myStr, i, i + 1);
            int len = max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len /2;
            }
        }
        string result;
        for (int i = start; i <= end; ++i) {
            result += myStr[i];
        }
        return result;
    }
    int expandAroundCenter(string s, int left, int right) {
        int L = left, R = right;
        while (L >= 0 && R < s.size() && s.at(L) == s.at(R)) {
            --L;
            ++R;
        }
        return R - L -1;
    }
};

int main() {
    string str1;
    cout << "intput str1: " << endl;
    cin >> str1;
    Solution sl1(str1);
    string result = sl1.longestPalindrome();
    cout << "result: " << result << endl;
}