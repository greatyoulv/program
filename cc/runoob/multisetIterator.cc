#include <set>
#include <iostream>
using namespace std;

int main() {
    multiset<int> c1({1,2,3,3,4,5});
    int count = 0;
    auto it = c1.begin();
    for(; it != c1.end(); ++it) {
        ++count;
    }
    cout << "c1 count: " << c1.size() << endl;
    it = c1.begin();
    for(int i = 0; i < 3; ++i){
        it++;
    }
    cout << "c1[3]: " << *it << endl;
}