#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void perm(char* s, int p) {
    if (p == strlen(s)) {
        printf("%s\n", s);
        return;
    }

    char* t = malloc(sizeof(s));
    char* u = malloc(sizeof(s));
    strcpy(t, s);
    strcpy(u, s);
    t[p] = toupper(t[p]);
    u[p] = tolower(u[p]);
    perm(t, p + 1);
    perm(u, p + 1);
}

int main() {
    char* s = "abc";
    perm(s, 0);

    return 0;
}
