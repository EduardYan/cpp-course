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

class Student
{
public:
  string name;
  int age;
  string course;
  double note;

  Student(string name_student, int age_student, string course_student, double note_student)
  {
    name = name_student;
    age = age_student;
    setCourse(course_student);
    setNote(note_student);
  }

  void setCourse(string course_student)
  {
    const string options[] = {"Math", "Languaje", "Science", "Fisics", "English", "Programming", "Marketing", "Cook"};

    if (course_student == options[0] || course_student == options[1] || course_student == options[2] || course_student == options[3] || course_student == options[4] || course_student == options[5] || course_student == options[6] || course_student == options[7])
    {
      course = course_student;
    }
    else
    {
      course = "Incorrect course";
    }
  }

  void setNote(double note_course)
  {
    if (note_course <= 10.0 && note_course >= 0.0)
    {
      note = note_course;
    }
    else
    {
      note = 0.0;
    }
  }

  bool isAprovate()
  {
    if (note >= 8.0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

const Student students[] = {
    Student("Oscar", 15, "Math", 9.8),
    Student("Pablo", 16, "Science", 7.6),
    Student("Karla", 15, "Fisics", 5.8),
    Student("Pedro", 19, "Cook", 0.0)};

int main()
{

  /*
  for (int i = 0; i < size(students); i++)
    {
      cout << "Name => " << students[i].name << endl;
      cout << "Age => " << students[i].age << endl;
      cout << "Course => " << students[i].course << endl;
      cout << "Note => " << students[i].note << "\n"
           << endl;
    }
  */

  // cout << person1.name << person1.age << person1.hobbie << endl;

  Person person1("Ana", 12, "Swin", "Math");
  Person person2("Juan", 20, "Cook", "Other");
  Person person3("Pablo", 15, "Walk", "Science");

  cout << person1.getCourse() << endl;
  cout << person2.getCourse() << endl;
  cout << person3.getCourse() << endl;

  return 0;
}