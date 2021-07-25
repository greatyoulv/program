#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> myVec1,myVec2;
    Solution(vector<int> vec1,vector<int> vec2) : myVec1(vec1),myVec2(vec2) {};
    float findMedianSortedArrays() {
        int m = myVec1.size();
        int n = myVec2.size();
        cout << "m: " << m << " n: " << n << endl;
        //findMedian
        if (m > n) {
            swap(myVec1,myVec2);
        }
        m = myVec1.size();
        n = myVec2.size();
        cout << "m: " << m << " n: " << n << endl;
        int imin = 0, imax = m, halfLen = (m + n + 1) / 2;
        while (imin <= imax) 
        {
            /* code */
            int i = (imin + imax) / 2;
            int j = halfLen - i;
            if (i < imax && myVec2.at(j-1) > myVec1.at(i) ) {
                imin = i + 1;  // i is too small
            } else if (i > imin && myVec1.at(i -1) > myVec2.at(j) ) {
                imax = i - 1;  // i is too big
            } else {
                float maxLeft = 0;
                if ( i == 0 ) {
                    maxLeft = myVec2.at(j - 1);
                } else if ( j == 0 ) {
                    maxLeft = myVec1.at(i-1);
                } else {
                    maxLeft = max(myVec1.at(i - 1), myVec2.at(j - 1));
                }
                if ((m + n) % 2 == 1) {
                    return maxLeft;
                }

                float minRight = 0;
                if ( i == m) {
                    minRight = myVec2.at(j);
                } else if ( j == n ) {
                    minRight = myVec1.at(i);
                } else {
                    minRight = min(myVec1.at(i), myVec2.at(j));
                }
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0; 
    }
};

void myInput(multiset<int>& mulSet);

int main() {
    multiset<int> mulSet1,mulSet2;
    vector<int> vec1,vec2;
    myInput(mulSet1);
    myInput(mulSet2);
    for (auto& elem : mulSet1) {
        vec1.push_back(elem);
    }
    for (auto& elem : mulSet2) {
        vec2.push_back(elem);
    }
    Solution sl1(vec1,vec2);
    float median = 0;
    median = sl1.findMedianSortedArrays();
    cout << "median: " << median << endl;
}

void myInput(multiset<int>& mulSet) {
    int temp;
    cout << "input numbers('1 2 3'): " << endl;
    while (cin >> temp)
    {
        /* code */
        mulSet.insert(temp);
    }
    cin.clear();
    cin.ignore();
}