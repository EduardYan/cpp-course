#include <iostream>
using namespace std;

int main()
{
  // normal while
  /*
  int i = 0;
  while (i < 10)
  {
    cout << "Hola" << endl;
    i++;
  };

  */

  // do while
  /*
  int i = 0;
  do
  {
    cout << "Hola" << endl;
    i++;
  } while (i < 10);

  */

  // for loop
  /*
  string names[] = {"Pablo", "Marcos", "Juan", "Pedro"};
  for (int i = 0; i < size(names); i++)
  {
    cout << names[i] << endl;
  }

  */

  // 2d loop
  int numbers[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  int i, j;
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 4; j++)
    {
      cout << numbers[i][j] << endl;
    }
  }

  return 0;
}