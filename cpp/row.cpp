#include<iostream>
using namespace std;
int main()
{
  constexpr size_t rowCnt = 3, colCnt = 4;
  int ia[rowCnt][colCnt];
  for (size_t i = 0; i != rowCnt; ++i)
    {
      for (size_t j = 0; j != colCnt; ++j)
	{
	  ia[i][j] = i* colCnt + j;
          cout<<ia[i][j]<<",";    
	}
      cout<<endl;    
    }
  return 0;
}
