#include <regex>
#include <iostream>
using namespace std;

void out (bool b)
{
  cout << ( b ? "found" : "not found") << endl;
}

int main()
{
  regex reg1("^[+-]?[[:digit:]]+[^[:digit:]]?");
  bool found = regex_match("+123a",    //data
			   reg1);    //regular expression
  out(found);
}
