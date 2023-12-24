#include <iostream>

// Definición de códigos de escape ANSI para colores
#define RESET   "\x1b[0m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1b[37m"

int main() {
    // Mensajes en colores
    std::cout << RED << "Este es un mensaje en rojo." << RESET << std::endl;
    std::cout << GREEN << "Este es un mensaje en verde." << RESET << std::endl;
    std::cout << YELLOW << "Este es un mensaje en amarillo." << RESET << std::endl;
    std::cout << BLUE << "Este es un mensaje en azul." << RESET << std::endl;
    std::cout << MAGENTA << "Este es un mensaje en magenta." << RESET << std::endl;
    std::cout << CYAN << "Este es un mensaje en cian." << RESET << std::endl;
    std::cout << WHITE << "Este es un mensaje en blanco." << RESET << std::endl;

    return 0;
}
