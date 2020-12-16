#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct h_entry h_entry;

struct h_entry {
    char* word;
    h_entry* next;
};

h_entry* hashmap[117];

void init() {
    for (int i = 0; i < 117; i++) {
        hashmap[i] = NULL;
    }
}

int hash(char* s) {
    int n = 7;
    for (int i = 0; i < strlen(s); i++)
        n += 7+(s[i]*5);
    return n % 117;
}

bool find(char* s) {
    int h = hash(s);
    h_entry* curr = hashmap[h];
    if (curr == NULL)
        return false;
    else {
        if (strcmp(curr->word, s) == 0)
            return true;
        while (curr->next != NULL) {
            curr = curr->next;
            if (strcmp(curr->word, s) == 0)
                return true;
        }
    }
    return false;
}

void add(char* s) {
    if (find(s) == true)
        return;

    int h = hash(s);
    h_entry* newentry = malloc(sizeof(h_entry));
    newentry->word = malloc(sizeof(s));
    newentry->next = NULL;
    strcpy(newentry->word, s);

    if (hashmap[h] == NULL)
        hashmap[h] = newentry;
    else {
        h_entry* curr = hashmap[h];
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = newentry;
    }
}

int main() {
    add("test");
    add("text");
    add("stevedore");
    printf("%d\n", hashmap[hash("text")]);
    printf("%d\n", hashmap[hash("asdfadsf")]);
    printf("text=%d otherword=%d\n", find("text"), find("otherword"));
    return 0;
}
