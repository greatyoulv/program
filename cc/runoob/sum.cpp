#include <iostream>

using namespace std;
int func(int x)
{
    int countx = 0;
    while(x)
    {
        countx++;
	x=x&(x-1);
	cout << "x = " << x <<endl;
    }
    return countx;
}

int main()

{ 
int count=func(9999);
cout << "countx = " << count << endl;

}
