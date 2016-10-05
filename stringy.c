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

char * stringconcat(char *s1, char *s2) {
    int s1len = stringlength(s1);
    int s2len = stringlength(s2);
    s1 += s1len;
    while (*s2) {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
    s1 -= (s1len + s2len);
    return s1;
}

int stringcomp(char *s1, char *s2) {
    int s1tot = 0;
    int s2tot = 0;
    while (*s1) {
        s1tot += *s1;
        s1++;
    }
    while (*s2) {
        s2tot += *s2;
        s2++;
    }
    return s1tot - s2tot;
}

char * stringchar(char *s, int c) {
    char ch = c;
    while (*s) {
        if (*s == ch) {
            return s;
        }
        s++;
    }
    return NULL;
}

int main() {
    printf("TESTING ALL METHODS\n");
    char s[] = "Hello";
    char s1[] = "Tester33 44Life";
    char cp1[] = "Top";
    char cp2[] = "Cat";
    char cat1[] = "Rat";
    char cat2[] = "Tat";
    printf("~~~~~~~~~~~~~~strlen~~~~~~~~~~~~~\n");
    printf("String 1: %s\n", s);
    printf("Length of String: %lu\n", stringlength(s));
    printf("String 2: %s\n", s1);
    printf("Length of String: %lu\n", stringlength(s1));
    printf("~~~~~~~~~~~~~~strcpy~~~~~~~~~~~~~\n");
    printf("Showing String 1: %s\n", cp1);
    printf("Showing String 2: %s\n", cp2);
    printf("String 1 after String Copy (strcpy): %s\n", stringcopy(cp1, cp2));
    printf("~~~~~~~~~~~~~~strcat~~~~~~~~~~~~~\n");
    printf("Showing String 1: %s\n", cat1);
    printf("Showing String 2: %s\n", cat2);
    char cat3[] = "Rat";
    char cat4[] = "Tat";
    printf("Showing new concatenated string: %s\n", stringconcat(cat3, cat4));
    printf("~~~~~~~~~~~~~~strcmp~~~~~~~~~~~~~\n");
    char cmp1[] = "abc";
    char cmp2[] = "abcdef";
    printf("Showing String 1: %s\n", cmp1);
    printf("Showing String 2: %s\n", cmp2);
    printf("Comparison Result 1 to 2: %d\n", stringcomp(cmp1, cmp2));
    printf("Comparison Result 2 to 1: %d\n", stringcomp(cmp2, cmp1));
    printf("Comparison Result 1 to 1: %d\n", stringcomp(cmp1, cmp1));
    printf("~~~~~~~~~~~~~~strchr~~~~~~~~~~~~~\n");
    printf("Showing string in question: %s\n", s);
    printf("Searching for |e|\n");
    printf("String after and including |e| is: %s\n", stringchar(s, 101));
    printf("Searching for |b|\n");
    printf("String after and including |b| is: %s\n", stringchar(s, 98));
    return 0;
}
