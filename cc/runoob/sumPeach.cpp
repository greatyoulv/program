#include <iostream>
using namespace std;

int sumPeach(int day)
{
    if (day == 10)
        return 1;
    else
        return 2 * sumPeach(day + 1) + 2;
}
int main()
{
    int sum;
    for(int i = 1; i <= 10; ++i)
    {
        sum=sumPeach(i);
        cout << i << " " << sum << endl;
    }

    return 0;
}