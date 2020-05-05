#include <stdio.h>

int main() {
    char InputString[100];
    printf("Enter something: ");
    scanf("%[^'\n']s",InputString);
    printf("%s", InputString);
    return 0;
}