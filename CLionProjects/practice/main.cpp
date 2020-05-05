#include <iostream>
#include "Console.h"
int main() {
    DynamicVector<Team> teams;
    Repository repository{};
    Service service{repository};
    service.add("t1", "t2", 0);
    service.add("t2", "t2", 0);
    service.add("t3", "t2", 0);
    service.add("t4", "t2", 0);

    Console console{service};
    console.run_menu();
    return 0;
}