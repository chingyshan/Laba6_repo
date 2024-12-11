#include <iostream>
#include "all_functions.h"

int main() {
    while (askToRunProgram()==1) {
        userMenu();
        int rows = get_rows();
        const int cols = 150;
        char** matrix = new char*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new char[cols];
        }

        input_matrix(matrix, rows,cols);

        print(matrix, rows);

        free_matrix(matrix, rows);
    }
    return 0;
}
