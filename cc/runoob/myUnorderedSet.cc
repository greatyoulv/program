#include <unordered_set>
#include <string>
#include <iostream>
using namespace std;

int main() {
    unordered_multiset<char> subString {'a', 'a', 'b'};
    for(const auto& elem : subString) {
        cout << "elem: " << elem << endl;
    }
    cout << endl;
    subString.insert({'a', 'e', 'h', 'o'});
    for(const auto& elem : subString) {
        cout << "elem: " << elem << endl;
    }
    cout << endl;
    char s = 'h';
    cout << "subString.find(s) " << *subString.find(s) << endl;
    if (subString.find(s) != subString.end()) {
        cout << "find " << s << endl;
    } else { 
        cout << "not find " << s << endl;
    };
}