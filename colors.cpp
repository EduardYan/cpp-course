#include <iostream>
#include <string>

using namespace std;

// colors
#define RESET "\x1b[0m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"

int main()
{
    cout << RED << "RED" << RESET << endl;
    cout << GREEN << "GREEN" << RESET << endl;
    cout << YELLOW << "YELLOW" << RESET << endl;
    cout << BLUE << "BLUE" << RESET << endl;
    cout << MAGENTA << "MAGENTA" << RESET << endl;
    cout << CYAN << "CYAN" << RESET << endl;
    cout << WHITE << "WHITE" << RESET << endl;

    return 0;
}
