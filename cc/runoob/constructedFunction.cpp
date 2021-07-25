#include <iostream>
using namespace std;

class ConstRef {
public:
    ConstRef(int ii): i(ii), ci(ii), ri(i) {};
private:
    int i;
    const int ci;
    int &ri;
};
int main()
{
    int a = 0;
    ConstRef cr(a);
}