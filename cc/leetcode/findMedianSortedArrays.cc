#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> myVec1,myVec2;
    Solution(vector<int> vec1,vector<int> vec2) : myVec1(vec1),myVec2(vec2) {};
    void findMedianSortedArrays() {
        //vector<int>::iterator it = myVec.begin();
        for (auto &elem : myVec1) {
            cout << "vec1 elem: " << elem << endl;
        }
        for (auto &elem : myVec2) {
            cout << "vec2 elem: " << elem << endl;
        }
        multiset<int> c1;
        for (auto &elem : myVec1) {
            c1.insert(elem);
        }
        for (auto &elem : myVec2) {
            c1.insert(elem);
        }
        for (auto &elem : c1) {
            cout << "c1 elem: " << elem << endl;
        }
        //multiset<int>::iterator it = c1.begin();
        auto it = c1.begin();
        int count = c1.size();
        double middle = 0;
        if (count % 2 == 0) {
            count /= 2;
            for (int i = 0; i < count -1; ++i) {
                ++it;
            }
            middle += *it;
            it = c1.begin();
            for (int i = 0; i < count; ++i) {
                ++it;
            }
            middle += *it;
            middle /= 2;
            //middle = (*(it + count - 1) + *(it + count)) / 2;
        } else {
            count /= 2;
            for (int i = 0; i < count; ++i) {
                it++;
            }
            middle = *it;
        }
        cout << "middle: " << middle << endl;
    }
};
void myInput(vector<int>& vec) {
    int temp;
    cout << "input numbers('1 2 3'): " << endl;
    while (cin >> temp)
    {
        /* code */
        vec.push_back(temp);
    }
}
int main() {
    vector<int> vec1,vec2;
    myInput(vec1);
    cin.clear();
    cin.ignore();
    myInput(vec2);
    //myInput(vec1);
    Solution sl1(vec1,vec2);
    sl1.findMedianSortedArrays();

}
