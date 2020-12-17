#include <stdio.h>
#include <stdlib.h>

int maxsum(int* arr, int len, int p) {
    if (p >= len)
        return 0;
    if (p == len - 1)
        return arr[p];

    int o1 = maxsum(arr, len, p + 2);
    int o2 = maxsum(arr, len, p + 3);
    o1 += arr[p];
    o2 += arr[p + 1];
    if (o1 > o2)
        return o1;
    return o2;
}

int asize(int* arr) {
    if (arr == 0)
        return 0;
    int i = 0;
    while (arr[i] != -1)
        i++;
    return i;
}

int sum(int* arr) {
    if (arr == 0)
        return 0;
    int sum = 0;
    int i = 0;
    while (arr[i] != -1) {
        sum += arr[i];
        i++;
    }
    return sum;
}

void printa(int* arr) {
    int i = 0;
    printf("[ ");
    while (arr[i] != -1) {
        printf("%d ", arr[i]);
        i++;
    }
    printf("]\n");
}

int* maxslice(int* arr, int len, int p) {
    if (p >= len)
        return 0;
    else if (p == len - 1) {
        int* s = malloc(sizeof(int)*2);
        s[0] = arr[p];
        s[1] = -1;
        return s;
    } else if (p == len - 2) {
        int* s = malloc(sizeof(int)*2);
        if (arr[p] > arr[p+1])
            s[0] = arr[p];
        else
            s[0] = arr[p+1];
        s[1] = -1;
        return s;
    }

    int* o1 = maxslice(arr, len, p + 2);
    int* o2 = maxslice(arr, len, p + 3);

    int o1s = asize(o1);
    int o2s = asize(o2);

    int *r1 = malloc(sizeof(int) * (o1s+2));
    int *r2 = malloc(sizeof(int) * (o2s+2));

    r1[0] = arr[p];
    r2[0] = arr[p + 1];

    for (int i = 0; i < o1s; i++)
        r1[i + 1] = o1[i];
    for (int i = 0; i < o2s; i++)
        r2[i + 1] = o2[i];
    r1[o1s+1] = -1;
    r2[o2s+1] = -1;
    free(o1); free(o2);

    if (sum(r1) >= sum(r2))
        free(r2);
        return r1;
    free(r1);
    return r2;
}

int main() {
    int a1[3] = {1,2,3};
    int a2[4] = {5,1,2,6};
    int a3[6] = {5,1,2,6,20,2};
    printf("%d\n", maxsum(a1, 3, 0));
    printf("%d\n", maxsum(a2, 4, 0));
    printf("%d\n\n", maxsum(a3, 6, 0));

    printa(maxslice(a1, 3, 0));
    printa(maxslice(a2, 4, 0));
    printa(maxslice(a3, 6, 0));

    return 0;
}
