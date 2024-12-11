#include <iostream>
#include "all_functions1.h"

int main() {
    while(askToRunProgram()==1) {
        userMenu();
        int size = GetSize();

        char* strArray = new char[size + 1];

        InputString(size, strArray);

        int groupCount = Count(strArray);
        std::cout << "Вы ввели: " << strArray << std::endl;
        std::cout << "Количество групп из 5 элементов: " << groupCount << std::endl;

        delete[] strArray;
    }
    return 0;
}
