#ifndef YT_GUID_WWW_UTILS_HPP
#define YT_GUID_WWW_UTILS_HPP

#include <string>
#include <map>

/**
 * @brief Класс для работы с HTML-шаблонами.
 */
class WwwUtils {
public:
  /**
   * @brief Загружает содержимое HTML-файла из указанного пути.
   * @param filePath Путь к HTML-файлу.
   * @return Содержимое HTML-файла в виде строки.
   */
  static std::string loadHtmlTemplate(const std::string& filePath);

  /**
   * @brief Вставляет данные в HTML-шаблон.
   * @param htmlTemplate HTML-шаблон.
   * @param data Карта ключ-значение для замены в шаблоне.
   * @return HTML-страница с вставленными данными.
   */
  static std::string injectDataIntoTemplate(const std::string& htmlTemplate, const std::map<std::string, std::string>& data);

  /**
   * @brief Устанавливает базовый путь к папке www.
   * @param path Путь к папке www.
   */
  static void setWwwPath(const std::string& path);

  /**
   * @brief Возвращает полный путь к файлу в папке www.
   * @param fileName Имя файла.
   * @return Полный путь к файлу.
   */
  static std::string getFullPath(const std::string& fileName);

private:
  static std::string wwwPath; /**< @brief Базовый путь к папке www. */
};

#endif // YT_GUID_WWW_UTILS_HPP
