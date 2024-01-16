#include <iostream>
#include <fstream> // Necesario para trabajar con archivos

int main()
{
  // Nombre del archivo que deseas leer
  const char *nombreArchivo = "./file.txt";

  // Crear un objeto ifstream (entrada de flujo de archivo)
  std::ifstream archivo(nombreArchivo);

  // Verificar si el archivo se abrió correctamente
  if (!archivo.is_open())
  {
    std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
    return 1; // Terminar el programa con un código de error
  }

  // Leer el contenido del archivo línea por línea
  std::string linea;
  while (std::getline(archivo, linea))
  {
    std::cout << linea << std::endl;
  }

  // Cerrar el archivo después de usarlo
  archivo.close();

  return 0; // Terminar el programa con éxito
}
