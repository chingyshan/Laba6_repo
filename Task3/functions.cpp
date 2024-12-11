#include <iostream>
#include "all_functions.h"
void userMenu() {
    std::cout << "\nПрограмма подсчитывает сумму кодов символов каждого слова и, если сумма оказалась четной, разворачивает зеркально это слово в строке.\n";
    std::cout << "Задание №3(вар.1), Агейчик Влад гр. 453502\n";
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

int calculate_sum(const char* str) {
    int sum = 0;
    int j = 0;
    while (str[j] != '\0') {
        unsigned char ch = static_cast<unsigned char>(str[j]);

        if (single_byte(ch)) {
            sum += static_cast<int>(ch);
            j++;
        } else if (two_byte(ch) && str[j + 1] != '\0') {
            sum += static_cast<int>(ch) + static_cast<int>(static_cast<unsigned char>(str[j + 1]));
            j += 2;
        } else {
            j++;
        }
    }
    return sum;
}

void free_matrix(char** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int get_rows() {
    int rows;
    std::cout << "Введите количество строк" << std::endl;
    while (true) {
        std::cin >> rows;
        if (std::cin.fail() || rows < 0 || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(1000000, '\n');
            std::cout << "Неверный ввод. Введите целое неотрицательное число." << std::endl;
            continue;
        }
        std::cin.ignore(1000000, '\n');
        break;
    }
    return rows;
}
void input_matrix(char** matrix, int rows,int MAX_COLS) {
    std::cout << "Введите строки (по одной строке на ввод):" << std::endl;
    for (int i = 0; i < rows; i++) {
        int j = 0;
        char ch;
        while (j < MAX_COLS - 1) {
            ch = getchar();
            if (ch == '\n' || ch == EOF) {
                break;
            }
            matrix[i][j++] = ch;
        }
        matrix[i][j] = '\0';
    }
}
void print(char** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        std::cout << "___________________________________________________________________________________________________________________" << std::endl;
        std::cout << "Исходная строка: " << matrix[i] << std::endl;

        int sum = calculate_sum(matrix[i]);
        std::cout << "Сумма кодов символов строки: " << sum << std::endl;

        if (sum % 2 == 0) {
            std::cout << "Сумма чётная." << std::endl;

            int new_size = 0;
            int j = 0;
            while (matrix[i][j] != '\0') {
                unsigned char ch = static_cast<unsigned char>(matrix[i][j]);
                if (single_byte(ch)) {
                    new_size += 1;
                    j++;
                } else if (two_byte(ch) && matrix[i][j + 1] != '\0') {
                    new_size += 2;
                    j += 2;
                }
            }

            char* new_str = new char[new_size + 1];
            j = 0;
            int new_idx = 0;
            while (matrix[i][j] != '\0') {
                unsigned char ch = static_cast<unsigned char>(matrix[i][j]);
                if (single_byte(ch)) {
                    new_str[new_idx++] = matrix[i][j++];
                } else if (two_byte(ch) && matrix[i][j + 1] != '\0') {
                    new_str[new_idx++] = matrix[i][j++];
                    new_str[new_idx++] = matrix[i][j++];
                }
            }
            new_str[new_idx] = '\0';

            delete[] matrix[i];
            matrix[i] = new_str;

            char* reversed_str = zerkalo(matrix[i], new_size);
            std::cout << "Зеркальная строка: " << reversed_str << std::endl;

            delete[] reversed_str;
        }
    }
}
bool single_byte(unsigned char ch) {
    return ch <= 0x7F;
}
bool two_byte(unsigned char ch) {
    return ch >= 0xC0 && ch <= 0xDF;
}
char* zerkalo(const char* str, int size) {
    char* reversed_str = new char[size + 1];
    int reverse_idx = 0;
    for (int k = size - 1; k >= 0;) {
        unsigned char ch = static_cast<unsigned char>(str[k]);
        if (single_byte(ch)) {
            reversed_str[reverse_idx++] = str[k--];
        } else if (k > 0 && two_byte(static_cast<unsigned char>(str[k - 1]))) {
            reversed_str[reverse_idx++] = str[k - 1];
            reversed_str[reverse_idx++] = str[k];
            k -= 2;
        } else {
            k--;
        }
    }
    reversed_str[reverse_idx] = '\0';
    return reversed_str;
}

