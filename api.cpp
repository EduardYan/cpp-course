#include "httplib.h"
#include <iostream>

int main() {
  // URL de la API de ejemplo
  const char *api_url = "https://jsonplaceholder.typicode.com/posts/1";

  // Inicializar el cliente HTTP
  httplib::Client client(api_url);

  // Realizar la solicitud GET
  auto res = client.Get("/");

  // Verificar si la solicitud fue exitosa (código de estado 200)
  if (res && res->status == 200) {
    // Imprimir el contenido de la respuesta
    std::cout << "Contenido de la respuesta:\n" << res->body << std::endl;
  } else {
    std::cerr << "Error al realizar la solicitud. Detalles: "
              << (res ? std::to_string(res->status)
                      : "No se pudo establecer conexión")
              << std::endl;
  }

  return 0;
}
