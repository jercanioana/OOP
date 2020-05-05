#include <iostream>
#include "UI.h"
int main() {

    Controller controller;
    UI ui{controller};

    ui.RunMenu();

    return 0;
}