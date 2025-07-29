#include "wwwutils.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <filesystem>

std::string WwwUtils::wwwPath = "";

/**
 * @brief Загружает содержимое HTML-файла из указанного пути.
 * @param filePath Путь к HTML-файлу.
 * @return Содержимое HTML-файла в виде строки.
 * @throws std::runtime_error Если файл не найден или не может быть открыт.
 */
std::string WwwUtils::loadHtmlTemplate(const std::string& filePath) {
  std::ifstream fileStream(filePath);
  if (!fileStream.is_open()) {
    throw std::runtime_error("Failed to open HTML template: " + filePath);
  }
  std::stringstream buffer;
  buffer << fileStream.rdbuf();
  return buffer.str();
}

/**
 * @brief Вставляет данные в HTML-шаблон.
 * @param htmlTemplate HTML-шаблон.
 * @param data Карта ключ-значение для замены в шаблоне.
 * @return HTML-страница с вставленными данными.
 */
std::string WwwUtils::injectDataIntoTemplate(const std::string& htmlTemplate, const std::map<std::string, std::string>& data) {
  std::string result = htmlTemplate;
  for (const auto& pair : data) {
    std::string placeholder = "{{" + pair.first + "}}";
    size_t pos = result.find(placeholder);
    while (pos != std::string::npos) {
      result.replace(pos, placeholder.length(), pair.second);
      pos = result.find(placeholder, pos + pair.second.length());
    }
  }
  return result;
}

/**
 * @brief Устанавливает базовый путь к папке www.
 * @param path Путь к папке www.
 */
void WwwUtils::setWwwPath(const std::string& path) {
  WwwUtils::wwwPath = path;
}

/**
 * @brief Возвращает полный путь к файлу в папке www.
 * @param fileName Имя файла.
 * @return Полный путь к файлу.
 */
std::string WwwUtils::getFullPath(const std::string& fileName) {
  if (WwwUtils::wwwPath.empty()) {
    // Если wwwPath не установлен, ищем рядом с исполняемым файлом
    std::filesystem::path currentPath = std::filesystem::current_path();
    std::filesystem::path defaultWwwPath = currentPath / "www";
    return (defaultWwwPath / fileName).string();
  }
  return (std::filesystem::path(WwwUtils::wwwPath) / fileName).string();
}

