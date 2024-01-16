#include <iostream>

using namespace std;

class Animal
{
public:
  void comer()
  {
    cout << "El animal come" << endl;
  }
  void dormir()
  {
    cout << "El animal duerme" << endl;
  }
};

// heredate
class Perro : public Animal
{
public:
  void ladrar()
  {
    cout << "El perro ladra" << endl;
  }
};

int main()
{

  // Animal animal1;
  // animal1.comer();
  // animal1.dormir();

  Perro perro1;
  perro1.comer();
  perro1.ladrar();

  return 0;
}