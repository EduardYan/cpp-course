#include <iostream>

using namespace std;

int main()
{
  int number;
  cout << "How many cars do you have ? ";
  cin >> number;
  cin.ignore();

  // pointer
  string *pCars = new string[number];

  for (int i = 0; i < number; i++)
  {
    cout << "Enter car #" << i + 1 << " ";
    getline(cin, pCars[i]);
  }

  cout << "\nHere is your garage!\n";
  cout << "----------------------\n";

  for (int i = 0; i < number; i++)
  {
    cout << "Parking spot #" << i + 1 << " " << pCars[i] << endl;
  }

  cout << endl;
  return 0;
}