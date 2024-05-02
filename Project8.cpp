#include <iostream>
#include <httplib.h>

void makeApiRequest(const std::string& url) {
    // ������� ������ ������� ��� ������ � HTTP ���������
    httplib::Client client("https://swapi.dev");

    // ��������� GET ������ �� ���������� URL
    auto response = client.Get(url.c_str());

}

int main() {
    int choice;

    do {
        // ����������� ������������ ������� ��������
        std::cout << "�������� �������� (1 - �������� ���������� � ���������, 2 - �������� ���������� � �������, 3 - �������� ���������� � ������, 4 - �����): ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            int characterId;
            std::cout << "������� ����� ��������� (�� 1 �� 68): ";
            std::cin >> characterId;
            makeApiRequest("https://swapi.dev/api/people/" + std::to_string(characterId) + "/");
            break;
        case 2:
            int planetId;
            std::cout << "������� ����� ������� (�� 1 �� 83): ";
            std::cin >> planetId;
            makeApiRequest("https://swapi.dev/api/planets/" + std::to_string(planetId) + "/");
            break;
        case 3:
            int filmId;
            std::cout << "������� ����� ������ (�� 1 �� 6): ";
            std::cin >> filmId;
            makeApiRequest("https://swapi.dev/api/films/" + std::to_string(filmId) + "/");
            break;
        case 4:
            std::cout << "����� �� ���������.\n";
            break;
        default:
            std::cout << "������������ �����.\n";
        }

    } while (choice != 4);

    return 0;
}