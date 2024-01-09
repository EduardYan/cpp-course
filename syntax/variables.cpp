#include <iostream>
using namespace std;

int main()
{

  string userName = "pablo_845";
  string userName2;
  userName2 = "oscar_999";
  int myage = 15;
  const double pi = 3.1416;
  char firstLetter = 'A';

  cout << userName << endl;
  cout << userName2 << endl;
  cout << myage << endl;
  cout << pi << endl;
  cout << firstLetter << endl;

  string names[] = {"Oscar", "Vargas", "Pablo", "Juan"};
  int ages[5] = {15, 16, 17, 19};

  for (int i = 0; i < size(names); i++)
  {
    cout << "Name => " << names[i] << endl;
  }
  for (int i = 0; i < size(ages); i++)
  {
    cout << "Age => " << ages[i] << endl;
  }

  bool isDriving = true;
  bool isEating = false;
  cout << isDriving << endl;
  cout << isEating << endl;

  return 0;
}