#include "server.hpp"
#include "wwwutils.hpp"
#include <map>
#include <string>

/**
 * @brief Конструктор YtGuidServer.
 * Инициализирует маршруты для Crow приложения.
 */
YtGuidServer::YtGuidServer() {
  CROW_ROUTE(app, "/hello")([this]() {
    return handleHello();
  });

  CROW_ROUTE(app, "/run/<int>")([this](int mode) {
    return handleRunMode(mode);
  });

  CROW_ROUTE(app, "/opt/<int>")([this](int option) {
    return handleOption(option);
  });
}

/**
 * @brief Запускает HTTP-сервер на указанном порту.
 * @param port Порт для прослушивания.
 */
void YtGuidServer::run(uint16_t port) {
  app.port(port).multithreaded().run();
}

/**
 * @brief Обрабатывает запрос для корневого пути.
 * @return HTTP-ответ с "Hello world" страницей.
 */
crow::response YtGuidServer::handleHello() {
  try {
    std::string htmlTemplate = WwwUtils::loadHtmlTemplate(WwwUtils::getFullPath("hello.html"));
    std::map<std::string, std::string> data;
    data["message"] = "Hello from ytguid demon!";
    std::string renderedHtml = WwwUtils::injectDataIntoTemplate(htmlTemplate, data);
    return crow::response(200, "text/html", renderedHtml);
  } catch (const std::runtime_error& e) {
    return crow::response(500, "text/plain", "Error loading hello.html: " + std::string(e.what()));
  }
}

/**
 * @brief Обрабатывает запрос для режимов работы.
 * @param mode Номер режима.
 * @return HTTP-ответ с информацией о режиме.
 */
crow::response YtGuidServer::handleRunMode(int mode) {
  if (mode < 1 || mode > 4) {
    return crow::response(400, "text/plain", "Invalid run mode. Must be between 1 and 4.");
  }
  try {
    std::string htmlTemplate = WwwUtils::loadHtmlTemplate(WwwUtils::getFullPath("run.html"));
    std::map<std::string, std::string> data;
    data["mode_number"] = std::to_string(mode);
    std::string renderedHtml = WwwUtils::injectDataIntoTemplate(htmlTemplate, data);
    return crow::response(200, "text/html", renderedHtml);
  } catch (const std::runtime_error& e) {
    return crow::response(500, "text/plain", "Error loading run.html: " + std::string(e.what()));
  }
}

/**
 * @brief Обрабатывает запрос для опций режимов.
 * @param option Номер опции.
 * @return HTTP-ответ с информацией об опции.
 */
crow::response YtGuidServer::handleOption(int option) {
  if (option < 1 || option > 4) {
    return crow::response(400, "text/plain", "Invalid option. Must be between 1 and 4.");
  }
  try {
    std::string htmlTemplate = WwwUtils::loadHtmlTemplate(WwwUtils::getFullPath("opt.html"));
    std::map<std::string, std::string> data;
    data["option_number"] = std::to_string(option);
    std::string renderedHtml = WwwUtils::injectDataIntoTemplate(htmlTemplate, data);
    return crow::response(200, "text/html", renderedHtml);
  } catch (const std::runtime_error& e) {
    return crow::response(500, "text/plain", "Error loading opt.html: " + std::string(e.what()));
  }
}

