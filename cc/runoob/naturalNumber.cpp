#include <iostream>
using namespace std;

int main()
{
    int n,sum =0;
    cout << "Input a int number: " << endl;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        sum += i;
    }
    cout << "Sum = " << sum <<endl;
    return 0;
}