#include <list>
#include <iostream>
using namespace std;

int main()
{
    list<int> lst1 {2,4,3};
    list<int> lst2 {5,6,4};
    for(auto &i : lst1)
        cout << i << endl;
    list<int>::iterator it;
    for(it = lst2.begin(); it != lst2.end(); ++it)
        cout << *it << endl;
}