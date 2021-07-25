#include <iostream>

using namespace std;

int main()

{ int i, count=0, sum=0;

double average;

int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

for( i=0; i<10; i++ )

{    if( a[i] % 2 == 0 )

        continue;

sum += a[ i ];

count++;

}

average = sum/count;

cout << "count = " <<count << '\t' << "sum = " <<sum << '\t' <<"average = " << average <<endl;

}
