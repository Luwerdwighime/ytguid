#include "crow.h"
#include <string>

using namespace std;
using namespace std::string_literals;

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/run/<int>")
    ([](int mode){
        if (mode != 1 && mode != 2)
            return crow::response(400, "Неверный режим"s);

        return crow::response(200, "Режим принят: "s + std::to_string(mode));
    });

    CROW_ROUTE(app, "/opt/<int>")
    ([](int opt){
        if (opt < 0 || opt > 10)
            return crow::response(400, "Неверная опция"s);

        return crow::response(200, "Выбрана опция: "s + std::to_string(opt));
    });

    app.port(8080).multithreaded().run();
}

