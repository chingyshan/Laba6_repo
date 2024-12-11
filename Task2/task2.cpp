#include <iostream>
#include "all_functions.h"
#include "../Task1/all_functions1.h"

int main() {
    while (askToRunProgram()==1) {
        userMenu();
        int size=1000;
        display(create(size), size);

        DELETING(create(size), size);
    }
    return 0;
}

