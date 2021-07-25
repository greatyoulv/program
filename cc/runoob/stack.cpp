#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    stack<int> S;
    S.push(3);
    S.push(10);
    S.push(100);
 
    cout<<S.size()<<endl;
    S.pop();
    cout<<S.top()<<endl;;
    if(!S.empty())
        cout<<"yes"<<endl;
 
    return 0;
}
