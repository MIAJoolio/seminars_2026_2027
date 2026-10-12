#include <stdio.h>
#include <stdlib.h>

// "-": x - копия, меняем копию
void increment_wrong(int x) {
    // TODO
}

// "+": px - адрес, *px - сама переменная
void increment(int *px) {
    // TODO
}

// "-": parr - копия указателя, arr в main не изменится
void create_pointer_wrong(int *parr, int n) {
    // TODO
    printf("  inside: parr = %p\n", (void *)parr);
}

// "+": parr - адрес указателя, *parr - сам указатель arr из main
void create_pointer(int **parr, int n) {
    // TODO
}

int main() {
    printf("--- 1. Pointers to a variable ---\n");
    int x = 5;
    increment_wrong(x);
    printf("increment_wrong(x): x = %d\n", x);
    increment(&x);
    printf("increment(&x):      x = %d\n", x);

    printf("\n--- 2. Pointers to pointers ---\n");
    int *arr = NULL;
    create_pointer_wrong(arr, 3);
    // что такое void?
    printf("create_pointer_wrong(arr, 3): arr = %p\n\n", (void *)arr);
    
    create_pointer(&arr, 3);
    printf("create_pointer(&arr, 3):      arr = %p", (void *)arr);
    int **parr = &arr;
    printf("\n&arr  = %p - address of variable arr (stack)\n", (void *)&arr);
    printf("parr  = %p - same, parr stores &arr\n", (void *)parr);
    printf("arr   = %p - address of the array (heap)\n", (void *)arr);
    printf("*parr = %p - same, *parr is arr\n", (void *)*parr);
    // parr** что это?
    // & -  
    // * -

    free(arr);
    return 0;
}
