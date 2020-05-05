#include <iostream>
#include "UI.h"
int main() {
    RealEstateAgency realEstateAgency;
    UI ui{realEstateAgency};
    ui.RunMenu();
    return 0;
}