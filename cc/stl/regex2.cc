#include <string>
#include <regex>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string data = "XML tag: <tag-name>the value</tag-name>.";
    cout << "data: " << data << endl;
    smatch m;
    bool found = regex_search (data,
                                m,
                                regex("<(.*)>(.*)</(\\1)>"));
                            
    cout << "m.empty(): " << boolalpha << m.empty() << endl;
    cout << "m.size(): " << m.size() << endl;
    if (found) {
        cout << "m.str(): " << m.str() << endl;
        cout << "m.length(): " << m.length() << endl;
        cout << "m.position(): " << m.position() << endl;
        cout << "m.prefix().str(): " << m.prefix().str() << endl;
        cout << "m.suffix().str(): " << m.suffix().str() << endl;
        //cout << endl;
        
        for (auto &mstr: m) {
            cout << mstr << endl;
        }
        cout << "m[0].str(): " << m[0].str() << endl;
        cout << "m.str(0): " << m.str(0) << endl;
    }
}