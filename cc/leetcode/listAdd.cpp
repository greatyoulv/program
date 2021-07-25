#include <list>
#include <iostream>
using namespace std;

class Solution {
public:
    int carry = 0;
    list<int> lst1, lst2, result;
    Solution(list<int> l1, list<int> l2): lst1(l1), lst2(l2) {};
    /*
    Solution(list<int> l1, list<int> l2){
        lst1 = l1;
        lst2 = l2;
    }
    */
    list<int> addTwoNumbers()
    {
        list<int>::iterator it_l1;
        cout << "lst1: " << endl;
        for(it_l1 = lst1.begin(); it_l1 != lst1.end(); ++it_l1)
        {
            cout << *it_l1 << " ";
        }
        list<int>::iterator it_l2;
        cout << endl << "lst2: " << endl;
        for(it_l2 = lst2.begin(); it_l2 != lst2.end(); ++it_l2)
        {
            cout << *it_l2 << " ";
        }
        for(it_l1 = lst1.begin(),it_l2 = lst2.begin(); it_l1 != lst1.end(),it_l2 != lst2.end(); ++it_l1,++it_l2)
        {
            int sum = carry + *it_l1 + *it_l2;
            carry = sum /10;
            result.push_back(sum % 10);
        }
        if(carry != 0)
            result.push_back(carry);
        return result;
    }
};

int main()
{
    int cin_a[3],cin_b[3];
    list<int> lst1;
    list<int> lst2;
    list<int> result;
    cout << "Input 3 number: " << endl;
    for(int i = 0; i < 3; ++i)
    {
        cin >> cin_a[i];
        lst1.push_back(cin_a[i]);
    }
    cout << "Input 3 number: " << endl;
    for(int i = 0; i < 3; ++i)
    {
        cin >> cin_b[i];
        lst2.push_back(cin_b[i]);
    }
    
    Solution sl1(lst1,lst2);
    result = sl1.addTwoNumbers();
    cout << endl << "result: " << endl;
    for(auto &i : result)
        cout << i << " ";
    cout << endl;

}