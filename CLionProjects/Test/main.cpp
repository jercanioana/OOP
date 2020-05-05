#include <iostream>
#include "Console.h"
#include "assert.h"
void tests(){
    Repository repository;
    Service service{repository};
    Console console{service};
    repository.add(PowerWord{"Wind", "w"});
    assert(repository.size() == 1);
    service.add("Storm1", "S");
    service.add("Storm2", "S");
    service.add("Storm3", "S");
    service.add("Storm3", "S");
    assert(service.size() == 4);
    assert(service.OccurencesOfAGivenRune("S") == 4);
}
int main() {
    tests();

    Repository repository;
    Service service{repository};
    Console console{service};
    console.run_menu();
    return 0;
}