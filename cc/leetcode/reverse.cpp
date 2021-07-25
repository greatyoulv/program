#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        auto INT_MAX = (numeric_limits<int>::max)();
        auto INT_MIN = (numeric_limits<int>::min)();
        while(x != 0) {
            int pop = x % 10;
            x /= 10;
            if(rev > INT_MAX/10 || (rev == INT_MAX/10 && pop > 7))
                return 0;
            if(rev < INT_MIN/10 || (rev == INT_MIN/10 && pop < -8))
                return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

int main()
{
    cout << "int max: " << (numeric_limits<int>::max)() << endl;
    cout << "int min: " << (numeric_limits<int>::min)() << endl;
    Solution solution1;
    int x;
    cin >> x;
    cout << solution1.reverse(x) << endl;
    return 0;
}