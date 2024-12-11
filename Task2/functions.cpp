#include <iostream>
#include "all_functions.h"
void userMenu() {
    std::cout << "\nПрограмма печатает квитанцию об оплате за телеграмму, если известна стоимость одного слова.\n";
    std::cout << "Задание №2(вар.1), Агейчик Влад гр. 453502\n";
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

int countW(const char* str) {
    int count = 0;
    bool inword=false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            inword=false;
        }
        if (str[i] != ' ' && !inword) {
            inword=true;
            count++;
        }

    }
    return count;
}

char* create(int size) {
    char *text=new char[size];
    return text;
}
void DELETING(const char*text,int size){
    delete[] text;
}
void display(char *text, int size) {
    std::cout << "Введите стоимость одного слова (в зимбабвийских долларах)"<<"\n";
    int price;
    while (true) {
        std::cin >> price;
        if (std::cin.fail() || std::cin.peek() != '\n' || price<0) {
            std::cout << "Введите стоимость \n";
            std::cin.clear();
            std::cin.ignore(100000000, '\n');
            continue;
        }
        break;
    }

    std::cout<<"Можете начинать писать вашу телеграмму(одно слово -- "<<price<<" зимбабвийскийх $) "<<"\n";
    int i=0;
    std::cin.ignore(100000000, '\n');
    bool input_valid = false;

    char previous_char='\0';

    while (!input_valid) {
        input_valid = true;
        while (i < size) {
            char current_char = getchar();
            if (current_char == '\n' || current_char == EOF) {
                break;
            }
            if (current_char == ' ' && previous_char == ' ') {
                std::cout << "Некорректный ввод: два пробела подряд. Попробуйте снова.\n";
                input_valid = false;
                break;
            }
            text[i++] = current_char;
            previous_char = current_char;
        }
        if (i>size) {
            std::cout<<"Строка превышает размеры телеграммы.\n";
            input_valid = false;
            break;
        }

        if (input_valid) {
            text[i] = '\0';
        }
        else {
            break;
        }
    }
    if (input_valid) {
        std::cout << "Ваша телеграмма: " << std::endl;
        std::cout<<text<<'\n';
        std::cout<<"Стоимость вашей телеграммы : "<<countW(text)*price<<" зимбабвийских $"<<"\n";

    }
}