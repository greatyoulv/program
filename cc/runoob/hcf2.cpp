#include <iostream>
using namespace std;
int gcd(int a,int b)
{
    if(a % b == 0)
        return b;
    return gcd(b,a % b);
}
int main()
{
    int n1,n2,hcf,lcm;
    cout << "输入两个整数: " << endl;
    cin >> n1 >> n2;
    hcf= gcd(n1,n2);
    lcm = n1 * n2 / hcf;
    cout <<"HCF = "<< hcf << endl;
    cout <<"LCM = "<< lcm << endl;
    return 0;
}
