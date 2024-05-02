#include <iostream>
#include <httplib.h>

void makeApiRequest(const std::string& url) {
    // Создаем объект клиента для работы с HTTP запросами
    httplib::Client client("https://swapi.dev");

    // Выполняем GET запрос по указанному URL
    auto response = client.Get(url.c_str());

}

int main() {
    int choice;

    do {
        // Предложение пользователю выбрать действие
        std::cout << "Выберите действие (1 - Получить информацию о персонаже, 2 - Получить информацию о планете, 3 - Получить информацию о фильме, 4 - Выход): ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            int characterId;
            std::cout << "Введите номер персонажа (от 1 до 68): ";
            std::cin >> characterId;
            makeApiRequest("https://swapi.dev/api/people/" + std::to_string(characterId) + "/");
            break;
        case 2:
            int planetId;
            std::cout << "Введите номер планеты (от 1 до 83): ";
            std::cin >> planetId;
            makeApiRequest("https://swapi.dev/api/planets/" + std::to_string(planetId) + "/");
            break;
        case 3:
            int filmId;
            std::cout << "Введите номер фильма (от 1 до 6): ";
            std::cin >> filmId;
            makeApiRequest("https://swapi.dev/api/films/" + std::to_string(filmId) + "/");
            break;
        case 4:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Некорректный выбор.\n";
        }

    } while (choice != 4);

    return 0;
}