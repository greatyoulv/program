#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    string Str;
    Solution(string str) : Str(str) {};
    // 马拉车算法
    string longestPalindrome() {
        cout << "Str: " << Str << endl;
        string myStr = preProcess(Str);
        cout << "myStr: " << myStr << endl;
        int n = myStr.size();
        vector<int> P(n,0);
        int C = 0, R = 0; //center, edge Of right
        int maxLen = 0, centerIndex =0;
        for (int i = 1; i < n -1; ++i) {
            int i_mirror = 2 * C - i;
            cout << "i: " << i << " ";
            cout << "i_mirror: " << i_mirror << endl;
            //P[i] = R > i ? min(R - i, P[i_mirror]) : 0;
            if (i < R) {
                //P[i] = min(R - i, P.at(i_mirror));
                if(P.at(i_mirror) < R-i) {
                    P.at(i) = P.at(i_mirror);
                } else {
                    P.at(i) = R -i;
                }            
            } else {
                P.at(i) = 0;
            }
            
            cout << "P.at(" << i << "):" << P[i] << endl;
            // 碰到之前讲的三种情况时候，需要利用中心扩展法
            while(myStr.at(i - P[i] -1) == myStr.at(i + P[i] +1)) {     //not longest
                ++P[i];
            }

            // 判断是否需要更新 R
            if (R < i + P[i]) {  //edge Of right over R
                C = i;
                R = i + P[i];
            }

            if (maxLen < P[i]) {
                maxLen = P[i];
                centerIndex = i;
            }
            
        }
        int start = (centerIndex - maxLen) / 2;
        return Str.substr(start,start + maxLen);
    }
private:
    string preProcess(string s) {
        if (s.empty()) {
            cout << "empty: " << endl;
            return "^$";
        }
        string ret("^");
        for (auto& elem : s) {
            ret += "#";
            ret += elem;
        }
        ret += "$";
        return ret;
    }
};

string preProcess(string s);

int main() {
    string str1("baba");
    cout << "Input a string" << endl;
    cin >> str1;
    Solution sl1(str1);
    string result = sl1.longestPalindrome();
    cout << "result: " << result << endl;
}