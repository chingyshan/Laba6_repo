#include <iostream>
#include "all_functions1.h"
void userMenu() {
    std::cout << "\nВ строке, состоящей из групп нулей и единиц, разделенных пробелами, программа находит количество групп с пятью цифрами..\n";
    std::cout << "Задание №1(вар.1), Агейчик Влад гр. 453502\n";
    std::cout << "————————————————————————————————————————————————————\n";
}

int askToRunProgram() {

    char choice;
    std::cout << "\n";
    std::cout << "Хотите запустить программу? (y/n) " << "\n";
    while (true) {
        std::cin >> choice;
        if (std::cin.fail() || std::cin.peek() != '\n' || (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')) {
            std::cout << "Введите y/n.\n";
            std::cin.clear();
            std::cin.ignore(100000000, '\n');
            continue;
        }

        if (choice == 'n' || choice == 'N') {
            std::cout << "Спасибо за использование.\n";
            return 0;
        }

        if (choice == 'y' || choice == 'Y') {
            return 1;
        }
    }
}

int Count(const char* strArray) {
    int group_count = 0;
    int element_count = 0;

    for (int i = 0; strArray[i] != '\0'; i++) {
        if (strArray[i] == '1' || strArray[i] == '0') {
            element_count++;
        } else if (strArray[i] == ' ') {
            if (element_count == 5) {
                group_count++;
            }
            element_count = 0;
        }
    }


    if (element_count == 5) {
        group_count++;
    }

    return group_count;
}

int GetSize() {
    int size;
    std::cout << "Введите размер строки: ";
    while (true) {
        std::cin >> size;
        if (std::cin.fail()|| size <0 || std::cin.peek()!='\n'||size > 80) {
            std::cin.clear();
            std::cin.ignore(1000000, '\n');
            std::cout << "Неверный ввод.\n";
            std::cout <<"Введите размер строки (не более 80 символов): "<< "\n";
            continue;
        }
        std::cin.ignore(1000000, '\n');
        break;
    }

    return size;
}

void InputString(int size, char *strArray) {
    bool input_valid = false;
    int i = 0;

    while (!input_valid) {
        input_valid = true;

        std::cout << "Введите строку (только '0', '1' или пробел): ";

        i = 0;

        while (i < size) {
            char ch = getchar();

            if (ch == '\n' || ch == EOF) {
                break;
            }

            if (ch == '1' || ch == '0' || ch == ' ') {
                strArray[i] = ch;
                i++;
            } else {

                std::cout << "В вашей строке не только 0, 1 или пробел.\n";


                std::cin.ignore(10000, '\n');

                input_valid = false;
                break;
            }
        }

        if (input_valid) {
            strArray[i] = '\0';
        }
    }
}