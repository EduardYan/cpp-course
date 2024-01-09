#include <iostream>
#include <curl/curl.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *output)
{
  size_t totalSize = size * nmemb;
  output->append((char *)contents, totalSize);
  return totalSize;
}

int main()
{
  // Inicializar cURL
  curl_global_init(CURL_GLOBAL_DEFAULT);

  // Crear un objeto cURL
  CURL *curl = curl_easy_init();

  if (curl)
  {
    // Configurar la URL de la solicitud GET
    curl_easy_setopt(curl, CURLOPT_URL, "https://jsonplaceholder.typicode.com/todos/1");

    // Establecer la función de escritura de datos
    std::string responseData;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseData);

    // Realizar la solicitud
    CURLcode res = curl_easy_perform(curl);

    // Verificar errores
    if (res != CURLE_OK)
    {
      std::cerr << "Error en la solicitud cURL: " << curl_easy_strerror(res) << std::endl;
    }
    else
    {
      std::cout << "Respuesta recibida:\n"
                << responseData << std::endl;
    }

    // Limpiar y cerrar cURL
    curl_easy_cleanup(curl);
  }

  // Limpiar cURL global
  curl_global_cleanup();

  return 0;
}
