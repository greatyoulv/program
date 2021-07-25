#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x % 10 == 0 && x != 0)) {
            return false;
        } else {
            int reversedNumber = 0;
            while (x > reversedNumber) {
                reversedNumber = reversedNumber + x % 10;
                x /= 10;
            }
            if (x == reversedNumber || x == reversedNumber / 10)
                return true;
            else
                return false;
        }

    }
};

int main()
{
    int x = 0;
    cout << "input a num: " << endl;
    cin >> x;
    Solution sl1;
    cout <<"result: " << sl1.isPalindrome(x) << endl;
}