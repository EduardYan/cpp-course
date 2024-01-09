#include <iostream>
using namespace std;

double add(double n1, double n2)
{
  return n1 + n2;
}

int main()
{

  int myNumber = 12;
  myNumber = myNumber * 100;

  double myNumber2 = 56.7;
  float myNumber3 = 78.287;
  string name = "Daniel";
  char letter = 'A';
  int ages[] = {12, 32, 45, 67};
  string names[] = {"Daniel", "Oscar", "Pablo", "Juan"};
  string cars[] = {"Corvette", "Tesla", "Ferrari", "Audi"};

  cout << myNumber << endl;
  cout << myNumber2 << endl;
  cout << myNumber3 << endl;
  cout << name << endl;
  cout << letter << endl;
  cout << add(456.6, 78.1) << endl;
  cout << ages[2] << endl;
  cout << names[2] << endl;

  for (int i = 0; i < size(cars); i++)
  {
    cout << "Car: " << cars[i] << endl;
  }

  return 0;
}