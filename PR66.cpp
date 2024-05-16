#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <windows.h>
#include <lmcons.h>

class Person {
public:
    std::string name;
    std::string profession;
    int salary;
    std::string job;

    Person(std::string name, std::string profession, int salary, std::string job) {
        this->name = name;
        this->profession = profession;
        this->salary = salary;
        this->job = job;
    }

    void showPersonInfo() {
        std::cout << "Введенный сотрудник\n";
        std::cout << "Имя: " << name << "\n";
        std::cout << "Профессия: " << profession << "\n";
        std::cout << "ЗП: " << salary << "\n";
    }

    void changePerson() {
        int newAnswer;
        std::string newName, newProfession, newJob;
        int newSalary;

        std::cout << "1. Изменить имя\n";
        std::cout << "2. Изменить профессию\n";
        std::cout << "3. Изменить ЗП\n";
        std::cout << "4. Изменить работу\n";
        std::cin >> newAnswer;
        switch (newAnswer) {
        case 1:
            std::cout << "Введите новое имя: ";
            std::cin >> newName;
            name = newName;
            break;
        case 2:
            std::cout << "Введите новую профессию: ";
            std::cin >> newProfession;
            profession = newProfession;
            break;
        case 3:
            std::cout << "Введите новую ЗП: ";
            std::cin >> newSalary;
            salary = newSalary;
            break;
        case 4:
            std::cout << "Введите новую работу: ";
            std::cin >> newJob;
            job = newJob;
            break;
        }
    }
};

class Factory {
public:
    std::vector<Person> persons;

    void addPerson() {
        std::string name, profession, job;
        int salary;
        std::cout << "Введите имя сотрудника: ";
        std::cin >> name;
        std::cout << "Введите должность сотрудника: ";
        std::cin >> profession;
        std::cout << "Введите ЗП сотрудника: ";
        std::cin >> salary;
        std::cout << "Введите работу для сотрудника: ";
        std::cin >> job;

        Person newPerson(name, profession, salary, job);
        persons.push_back(newPerson);
        std::cout << "Сотрудник успешно добавлен\n";
    }

    void showPersons() {
        for (int i = 0; i < persons.size(); i++) {
            std::cout << "Сотрудник " << i + 1 << "\n";
            persons[i].showPersonInfo();   
        }       
    }

    void updatePerson() {
        int personIndex;
        std::cout << "Введите индекс(от 1): ";
        std::cin >> personIndex;
        persons[personIndex - 1].changePerson();
    }
};

class MainClass {
public:
    void openingInfo() {
        std::cout << "Добро пожаловать на завод №52.\n"
            << "Если вы хотите получать зарплату ниже прожиточного минимума и уходить с больной спиной, то вы по адресу!\n"
            << "Приветствуется полное отсутствие стажа и мозгов.\n"
            << "Заинтересовались? Тогда приступим)\n\n";
    }

    void showIsOpen() {
        tm* currentTime = new tm();
        time_t now = time(0);
        localtime_s(currentTime, &now);
        int hour = currentTime->tm_hour;

        if (hour > 21 || hour < 6) {
            std::cout << "Завод закрыт.\n";
            exit(0);
        }
        else {
            std::cout << "Завод открыт.\n\n";
        }
    }

    void showOwner() {
        
        TCHAR username[UNLEN + 1];
        DWORD username_len = UNLEN + 1;

        GetUserName((TCHAR*)username, &username_len);

        std::wcout << L"Хозяин завода: " << username << "\n\n" << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "rus");

    MainClass mainClass;
    Factory factory;

    mainClass.showIsOpen();
    mainClass.openingInfo();
    mainClass.showOwner();

    while (true) {
        std::cout << "Что хотите сделать? \n1. Добавить сотрудника \n2. Просмотреть сотрудника\n3. Изменить данные пользователя\n4. Выход" << std::endl;
        int answer;
        std::cin >> answer;
        switch (answer) {
        case 1:
            factory.addPerson();
            break;
        case 2:
            factory.showPersons();
            break;
        case 3:
            factory.updatePerson();
            break;
        case 4:
            exit(0);
            break;
        default:
            std::cout << "Вы ввели неверную операцию\n";
            break;
        }
    }
    return 0;
}