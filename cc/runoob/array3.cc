#include <array>
#include <iostream>
using namespace std;

int main() {
    array<int, 5> c1 = {1,2,3,4,5};
    array<int> c2 = {};
    cout << "size: " << c1.size() << endl;
    for(auto& elem : c1) {
        cout << elem << endl;
    }
    cout << "c1[3]: " << c1[3] << endl;
    cout << "c1.at(3): " << c1.at(3) << endl;
}