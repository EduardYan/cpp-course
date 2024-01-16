#include <iostream>

using namespace std;

class Person
{
private:
  string course;

public:
  string name;
  int age;
  string hobbie;

  // default values
  Person()
  {
    name = "Default";
    age = 0;
    hobbie = "None";
  }

  Person(string person_name, int person_age, string person_hobbie, string person_course)
  {
    // cout << "Persona " << person_name << " created" << endl;
    name = person_name;
    age = person_age;
    hobbie = person_hobbie;
    defineCourse(person_course);
  }

  void defineCourse(string person_course)
  {
    if (person_course == "Math" || person_course == "Science" || person_course == "Programming" || person_course == "Fisics")
    {
      course = person_course;
    }
    else
    {
      course = "Incorrect course";
    }
  }

  string getCourse()
  {
    return course;
  }

  bool isChild()
  {
    if (age < 15)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

int main()
{
  // cout << person1.name << person1.age << person1.hobbie << endl;

  Person person1("Ana", 12, "Swin", "Math");
  Person person2("Juan", 20, "Cook", "Other");
  Person person3("Pablo", 15, "Walk", "Science");

  cout << person1.getCourse() << endl;
  cout << person2.getCourse() << endl;
  cout << person3.getCourse() << endl;

  return 0;
}