#include <string>
#include <regex>
#include <iostream>
#include <limits>
#include <exception>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        string data;
        for (int i= str.find_first_not_of(" "); i < str.size(); ++i) {
            data += str[i];
        }
        cout << "data: " << data << endl;
        regex reg("^[+-]?[[:digit:]]+");
        smatch m;
        bool found = regex_search(data,m,reg);
        cout << "m.empty(): " << boolalpha << m.empty() << endl;
        cout << "m.size(): " << m.size() << endl;
        int result;
        if (found) {
            cout << "m.str(): " << m.str() << endl;
            cout << "m.str()[0]: " << m.str()[0] << endl;
            cout << "m.length(): " << m.length() << endl;
            cout << "m.position(): " << m.position() << endl;
            try
            {
                /* code */
                result = stoi(m.str());
                cout << "try result: " << result << endl;
                
            }
            catch(const std::exception& e)
            {
                cout << e.what() << endl;
                if (&m.str()[0] == "-") {
                    result = numeric_limits<int>::min();
                } else {
                    result = numeric_limits<int>::max();
                }
                cout << "catch result: " << result << endl;
            }
            return result;
        }
        return 0;
    };
};

int main()
{
    string myStr;
    cout << "input a string: " << endl;
    cin >> myStr;
    Solution sl1;
    cout << "result: " << sl1.myAtoi(myStr) << endl;
}