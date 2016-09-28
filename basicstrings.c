#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Input is pointer.
//Increases value of x and pointer each loop-through,
//until pointer points to the null terminator.
long stringlength(char *s) {
    int x = 0;
    while (*s) {
        x++;
        s++;
    }
    return x;
}

char * stringcopy(char *d, char *s) {
    int srcor = stringlength(s);
    while (*s) {
        *d = *s;
        d++;
        s++;
    }
    *d = '\0';
    d -= srcor;
    return d;
}

int main() {
    char s[] = "Hello";
    char cp1[] = "Top";
    char cp2[] = "Cat";
    printf("String being tested: Hello\n");
    printf("Running ACTUAL strlen: %lu\n", strlen(s));
    printf("Running Personal strlen: %lu\n", stringlength(s));
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("Running ACTUAL strcpy \n");
    printf("Running Personal strcpy: %s\n", stringcopy(cp1, cp2));
    return 0;
}
