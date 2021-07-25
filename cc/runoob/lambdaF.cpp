#include <iostream>
using namespace std;

int main()
{
    auto f = [] (int i) { return i + 42; };
    cout << f(10) << endl;
    return 0;
}