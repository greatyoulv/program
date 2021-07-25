#include <iostream>
using namespace std;

int main()
{
    float n1,n2,n3;
    cout << "Input 3 numbers" << endl;
    cin >> n1 >> n2 >> n3;
    if((n1 >= n2) && (n1 >= n3))
        cout << "max: " << n1 << endl;
    else if((n2 >= n1) && (n2 >= n3))
        cout << "max: " << n2 << endl;
    else
    {
        cout << "max: " << n3 << endl;
    }
    
    return 0;
}