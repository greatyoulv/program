#include <iostream>
using namespace std;

int main()
{
    int **array;
    // 假定数组第一维长度为 m， 第二维长度为 n
    // 动态分配空间
    int m = 4, n= 8;
    array = new int *[m];
    for(int i = 0; i<m; i++){
        array[i] = new int[n];
    }
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            array[i][j] = j*i;
        }
    }
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
    //释放
    for(int i = 0; i<m; i++){
        delete [] array[i];
    }
    delete [] array;

    return 0;
}