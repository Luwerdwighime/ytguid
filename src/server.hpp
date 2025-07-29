#ifndef YT_GUID_SERVER_HPP
#define YT_GUID_SERVER_HPP

#include "crow.h"
#include <string>

/**
 * @brief Класс, реализующий HTTP-сервер для ytguid.
 */
class YtGuidServer {
public:
  /**
   * @brief Конструктор YtGuidServer.
   */
  YtGuidServer();

  /**
   * @brief Запускает HTTP-сервер на указанном порту.
   * @param port Порт для прослушивания.
   */
  void run(uint16_t port);

private:
  crow::SimpleApp app; /**< @brief Экземпляр Crow приложения. */

  /**
   * @brief Обрабатывает запрос для корневого пути.
   * @return HTTP-ответ с "Hello world" страницей.
   */
  crow::response handleHello();

  /**
   * @brief Обрабатывает запрос для режимов работы.
   * @param mode Номер режима.
   * @return HTTP-ответ с информацией о режиме.
   */
  crow::response handleRunMode(int mode);

  /**
   * @brief Обрабатывает запрос для опций режимов.
   * @param option Номер опции.
   * @return HTTP-ответ с информацией об опции.
   */
  crow::response handleOption(int option);
};

#endif // YT_GUID_SERVER_HPP

