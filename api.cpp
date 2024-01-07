#include <iostream>
#include <curl/curl.h>

// Estructura para almacenar los datos de la respuesta
struct ResponseData {
    std::string data;
};

// Función callback para manejar los datos de la respuesta
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t real_size = size * nmemb;
    std::string* response = static_cast<std::string*>(userp);
    response->append(static_cast<char*>(contents), real_size);
    return real_size;
}

// Función para realizar la solicitud HTTP
bool makeRequest(const std::string& url, ResponseData& responseData) {
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        // Configurar la URL
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        // Configurar la función de callback para manejar los datos de la respuesta
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &(responseData.data));

        // Realizar la solicitud
        res = curl_easy_perform(curl);

        // Verificar errores
        if (res != CURLE_OK) {
            std::cerr << "Error en la solicitud: " << curl_easy_strerror(res) << std::endl;
            curl_easy_cleanup(curl);
            curl_global_cleanup();
            return false;
        }

        // Limpiar y cerrar
        curl_easy_cleanup(curl);
        curl_global_cleanup();
        return true;
    }

    return false;
}

int main() {
    // URL de la API que deseas consultar
    std::string apiUrl = "https://jsonplaceholder.typicode.com/posts/1";

    // Estructura para almacenar los datos de la respuesta
    ResponseData responseData;

    // Realizar la solicitud HTTP
    if (makeRequest(apiUrl, responseData)) {
        // Mostrar los datos en la terminal
        std::cout << "Datos de la API:\n" << responseData.data << std::endl;
    }

    return 0;
}
