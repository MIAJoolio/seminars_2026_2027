#include <stdio.h>
#include <stdlib.h>

// "-": x - копия, меняем копию
void increment_wrong(int x) {
    x = x + 1;
}

// "+": px - адрес, *px - сама переменная
void increment(int *px) {
    *px = *px + 1;
}

// "-": parr - копия указателя, arr в main не изменится
void create_array_wrong(int *parr, int n) {
    parr = (int *)malloc(n * sizeof(int));
}

// "+": parr - адрес указателя, *parr - сам указатель arr из main
void create_array(int **parr, int n) {
    *parr = (int *)malloc(n * sizeof(int));
}

int main() {
    printf("--- 1. Без указателя и с указателем ---\n");
    int x = 5;
    increment_wrong(x);
    printf("increment_wrong(x): x = %d (не изменился)\n", x);
    increment(&x);
    printf("increment(&x):      x = %d (изменился)\n", x);

    printf("\n--- 2. Указатель на указатель ---\n");
    int *arr = NULL;
    create_array_wrong(arr, 3);
    printf("create_array_wrong(arr, 3): arr = %p (не изменился)\n", (void *)arr);
    create_array(&arr, 3);
    printf("create_array(&arr, 3):      arr = %p (изменился)\n", (void *)arr);

    int **parr = &arr;
    printf("\n&arr  = %p - где лежит указатель arr\n", (void *)&arr);
    printf("parr  = %p - то же самое\n", (void *)parr);
    printf("*parr = %p - куда указывает arr\n", (void *)*parr);

    free(arr);
    return 0;
}
