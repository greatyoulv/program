#include <iostream>
#include <cmath>

int main()
{
  using namespace std;
  double area;
  cout << "Enter the floor area, in square feet, of your home: ";
  cin >> area;
  double side;
  side = sqrt(area);
  cout << "That's the equivalent of a square " << side << endl;
  cout << "How fascinatinf!" << endl;
  return 0;
}
