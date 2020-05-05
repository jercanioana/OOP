#include <iostream>
#include "SortedBag.h"
#include "ExtendedTest.h"
#include "ShortTest.h"


bool relationForTest(TComp r1, TComp r2) {
    return r1 <= r2;
}

int main() {
//    testAllExtended();
//    testAll();
    SortedBag sb = SortedBag(relationForTest);
    sb.add(10);
    sb.add(8);
    sb.add(8);
    sb.add(6);
    sb.add(5);
    sb.add(7);
    std::cout<<sb.uniqueCount();
    return 0;
}