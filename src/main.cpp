#include "server.hpp"
#include "wwwutils.hpp"
#include <iostream>
#include <string>
#include <unistd.h> // Для getopt
#include <cstdlib>  // Для exit

/**
 * @brief Основная функция приложения.
 * @param argc Количество аргументов командной строки.
 * @param argv Массив аргументов командной строки.
 * @return Код завершения.
 */
int main(int argc, char* argv[]) {
  uint16_t port = 27523; // Порт по умолчанию
  std::string wwwPathArg;
  int opt;

  // Парсинг аргументов командной строки
  while ((opt = getopt(argc, argv, "w:")) != -1) {
    switch (opt) {
      case 'w':
        wwwPathArg = optarg;
        break;
      default:
        std::cerr << "Usage: " << argv[0] << " [-w <www_path>]" << std::endl;
        return EXIT_FAILURE;
    }
  }

  // Устанавливаем путь к папке www
  if (!wwwPathArg.empty()) {
    WwwUtils::setWwwPath(wwwPathArg);
  }

  std::cout << "Starting ytguid demon on port " << port << std::endl;
  if (!wwwPathArg.empty()) {
    std::cout << "Using www path: " << wwwPathArg << std::endl;
  } else {
    std::cout << "Using default www path (relative to executable): " << WwwUtils::getFullPath("") << std::endl;
  }

  YtGuidServer server;
  try {
    server.run(port);
  } catch (const std::exception& e) {
    std::cerr << "Error running server: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

