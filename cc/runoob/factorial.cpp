#include <iostream>
using namespace std;

int main()
{
    unsigned int n;
    unsigned long long factorial = 1;
    cout << "Input a int" << endl;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        factorial *= i;
    }
    cout << "factorial: 1*2*3*...*" << n << " = " << factorial <<endl;
    return 0;
}