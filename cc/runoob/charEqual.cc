#include <string>
#include <iostream>
using namespace std;

void preProcess(string s);

int main() {
    string s1("aaaa");
    if (s1.at(0) == s1.at(1)) cout << "equal" << endl;
    preProcess(s1);
}

void preProcess(string s) {
    cout << s << endl;
}