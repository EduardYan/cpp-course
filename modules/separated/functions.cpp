#include <iostream>

using namespace std;

void sayHello(string name)
{
  cout << "Hello " << name << "!" << endl;
}

void showFormatString(string toFormat)
{
  const int length = toFormat.length();
  cout << "String -> " << toFormat << " Length -> " << length << endl;
}
