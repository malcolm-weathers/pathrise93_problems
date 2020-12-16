#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node {
    int num;
    node* next;
};

node* newnode(int n, node* ll) {
    node* nn = malloc(sizeof(node));
    nn->num = n;
    nn->next = NULL;
    if (ll == NULL)
        return nn;
    while (ll->next != NULL)
        ll = ll->next;
    ll->next = nn;
    return nn;
}

void printll(node* ll) {
    printf("%d->", ll->num);
    while (ll->next != NULL) {
        ll = ll->next;
        printf("%d->", ll->num);
    }
    printf("\n");
}

node* rvrse(node* curr, node* prev) {
    if (curr == NULL)
        return prev;
    node* tmp = curr->next;
    curr->next = prev;
    rvrse(tmp, curr);
}

int main() {
    node* x = newnode(5, NULL);
    newnode(7, x);
    newnode(12, x);
    newnode(6, x);
    printll(x);

    node* y = rvrse(x, NULL);
    printll(y);
    return 0;
}
