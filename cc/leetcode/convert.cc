#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    string myStr;
    int myNumRows = 0;
    Solution(string str,int numRows) : myStr(str),myNumRows(numRows) {};
    string convert() {
        cout << "myStr: " << myStr << endl;
        cout << "myStr: " << myStr.size() << endl;
        cout << "myNumRows: " << myNumRows << endl;
    
        if (myNumRows == 1) return myStr;
        int n = myStr.size();
        n = min(myNumRows, n);
        vector<string> rows(n);
        int curRow = 0;
        bool goingDown = false;
        for (int i = 0; i < myStr.size(); ++i) {
            rows.at(curRow) += myStr.at(i);
            if (curRow == 0 || curRow == myNumRows -1) {
                goingDown = !goingDown;
            }
            curRow += goingDown ? 1 : -1;
        }  //converted to z
        string result;
        for (auto &elem: rows) {
            cout << "elem: " << elem << " ";
            result += elem;
        }
        cout << endl;
        return result;
    }
};

int main() {
    string str("LEETCODEISHIRING");
    cout << "input a string: " << endl;
    cin >> str;
    int numRows = 3;
    cout << "input a int(numRows): " << endl;
    cin >> numRows;
    Solution sl1(str,numRows);
    string result = sl1.convert();
    cout << "result: " << result << endl;
}