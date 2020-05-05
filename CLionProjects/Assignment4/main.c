#include <stdio.h>
#include "UI.h"
#include <assert.h>
void testsRepository()
{
    Repository* repository = CreateRepository(2);
    if (repository == NULL)
        assert(0);

    assert(repository->capacity == 2);
    assert(repository->size == 0);

    Item* p1 = CreateItem(1, "t1", "tonics", 100);
    AddElement(repository, p1);
    assert(repository->size == 1);

    Item* p2 = CreateItem(2, "t2", "tonics", 100);
    AddElement(repository, p2);
    assert(repository->size == 2);

    Item* p3 = CreateItem(2, "t3", "tonics", 100);
    AddElement(repository, p3);
    assert(repository->size == 3);
    assert(repository->capacity == 4);


    DestroyRepository(repository);
}


int main() {


    Repository *repository = CreateRepository(2);
    Service service = {repository};
    UI ui = { service };
    run_menu(&ui);

    return 0;
}