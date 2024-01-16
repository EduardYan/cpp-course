#include <iostream>

using namespace std;

int main()
{

  double num1 = 5.0;
  double num2 = 7.0;

  char operation = '+';

  switch (operation)
  {
  case '*':
    cout << num1 << " * " << num2 << " is " << (num1 * num2) << endl;
    break;
  case '+':
    cout << num1 << " + " << num2 << " is " << (num1 + num2) << endl;
    break;
  case '-':
    cout << num1 << " - " << num2 << " is " << (num1 - num2) << endl;
    break;
  case '/':
    cout << num1 << " / " << num2 << " is " << (num1 / num2) << endl;
    break;
  default:
    cout << "Incorrect operation" << endl;
    break;
  }

  return 0;
}