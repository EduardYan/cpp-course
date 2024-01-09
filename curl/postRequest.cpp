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
  curl_global_init(CURL_GLOBAL_DEFAULT);

  CURL *curl = curl_easy_init();

  if (curl)
  {
    // Configurar la URL de la solicitud POST
    curl_easy_setopt(curl, CURLOPT_URL, "https://www.example.com/post");

    // Configurar la solicitud como POST
    curl_easy_setopt(curl, CURLOPT_POST, 1L);

    // Datos a enviar en el cuerpo del POST
    const char *postData = "param1=value1&param2=value2";
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData);

    // Establecer la función de escritura de datos
    std::string responseData;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseData);

    // Realizar la solicitud
    CURLcode res = curl_easy_perform(curl);

    if (res != CURLE_OK)
    {
      std::cerr << "Error en la solicitud cURL: " << curl_easy_strerror(res) << std::endl;
    }
    else
    {
      std::cout << "Respuesta recibida:\n"
                << responseData << std::endl;
    }

    curl_easy_cleanup(curl);
  }

  curl_global_cleanup();

  return 0;
}
