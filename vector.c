#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_SIZE 2

typedef struct {
    void *data;         // блок памяти под элементы
    size_t size;        // сколько элементов лежит
    size_t elem_size;   // размер одного элемента в байтах
    size_t capacity;    // на сколько элементов выделена память
} Vector;

// size_t = 8 байт. Что это?
// Q: почему data указатель? что это дает?

Vector *vectorCreate(size_t elem_size) {
    if (elem_size == 0) return ...;

    // Q: почему функция это указатель? что нужно использовать внутри sizeof?
    Vector *vector = malloc(sizeof(...));
    
    if (!vector) return ...;

    // TODO: выделить data под MIN_SIZE элементов
    //       не вышло -> освободить vector и вернуть NULL
    // Q: почему MIN_SIZE такой? какое значение допустимо? 

    // TODO: заполнить size, elem_size, capacity
    return vector;
}

void *vectorGet(Vector *vector, size_t index) {
    if (!vector || index >= vector ... size) return NULL;
    return NULL;    // TODO: адрес элемента index
}

int vectorSet(Vector *vector, int index, void *value) {
    // TODO условия, когда значения нельзя выставить
    // TODO: скопировать elem_size байт из value в элемент index
    memcpy()
    return 0;
}

int vectorAppend(Vector *vector, void *el) {
    if (!vector || !el) return -1;

    if (vector->size == vector->capacity) {
        // TODO: увеличить capacity в 2 раза через realloc
        //Q: почему результат realloc записываются в новую переменную?
    }

    // TODO: скопировать el в конец и увеличить size
    return 0;
}

// удаляет элемент index и возвращает его копию
void *vectorRemove(Vector *vector, size_t index) {
    void *item = vectorGet(vector, index);
    if (!item) return NULL;

    // TODO обнулить значение по index
    void *copy = NULL;

    for (size_t i = index; i < vector->size - 1; i++) {
        // TODO: сдвинуть элемент i + 1 на место i
    }
    // TODO
    return copy;
}

void vectorFree(Vector *vector) {
    if (!vector) return;
    // TODO: освободить память
    // Q: в каком порядке?
}

void printInts(Vector *vector) {
    printf("  [");
    for (size_t i = 0; i < vector->size; i++) {
        printf(i ? ", %d" : "%d", *(int *)vectorGet(vector, i));
    }
    printf("]  size=%zu capacity=%zu\n", vector->size, vector->capacity);
}

static void removeAndShow(Vector *vector, size_t index) {
    int *removed = vectorRemove(vector, index);
    if (removed) {
        printf("  remove(%zu) -> %d\n", index, *removed);
        free(removed);
    } else {
        printf("  remove(%zu) -> NULL\n", index);
    }
    printInts(vector);
}

int main(void) {

    // TODO создать список, но с фиксированного размера
    int arr... = ...;
    printf("arr[0] = %d\n", ...);
    printf("arr[1] = %d\n", ...);
    printf("&arr[0] = %p, &arr[1] = %p  (diff = %td bytes)\n",
           (void *)&arr[0], (void *)&arr[1],
           (char *)&arr[1] - (char *)&arr[0]);
    

    char ... = "hi";
    printf("sizeof=%zu strlen=%zu\n", sizeof c, strlen(c));
    for (int i = 0; i < 5; i++){
        printf("\nc[%d]=%d %c\n", ..., ..., ...);
    }

    printf("\n=== createVector ===\n");
    // TODO вектор размера 0
    printf("  vectorCreate(0) -> %s\n", zeroElVector ? "not NULL" : "NULL");

    // TODO вектор с типом int
    printf("  vectorCreate(sizeof(int)) -> %s\n", v ? "ok" : "NULL");
    printInts(v);
    // TODO обратиться к созданному массиву 
    printf("%p %d", ..., ...);

    printf("\n=== vectorAppend ===\n");
    for (int x = 10; x <= 50; x += 10) {
        int rc = vectorAppend(...);
        printf("  append %d -> returned %d\n", ..., ...);
        printInts(v);
    }

    printf("  append NULL -> returned %d (expected -1)\n", vectorAppend(v, NULL));
    printInts(v);

    printf("\n=== vectorGet ===\n");
    printf("  get(0) = %d\n", ...);
    printf("  get(4) = %d\n", ...);
    printf("  get(5) = %s (out of range)\n", ... ? "not NULL" : "NULL");
    printf("  get on NULL vector = %s\n", ... ? "not NULL" : "NULL");
    printInts(v);

    printf("\n=== vectorSet ===\n");
    int value = 99;
    printf("  set(0, 99) -> returned %d\n", vectorSet(v, 0, &value));
    printInts(v);
    printf("  set(5, 99) -> returned %d (expected -1)\n", vectorSet(v, 5, &value));
    printf("  set(-1, 99) -> returned %d (expected -1)\n", vectorSet(v, -1, &value));
    printf("  set(1, NULL) -> returned %d (expected -1)\n", vectorSet(v, 1, NULL));
    printInts(v);

    printf("\n=== vectorRemove ===\n");
    ...

    printf("\n=== vectorFree ===\n");
    // vectorFree(v);
    // v = NULL;
    // vectorFree(NULL);

    // Vector *d = vectorCreate(sizeof(double));
    // for (double x = 1.5; x <= 3.0; x += 0.5) {
    //     vectorAppend(d, &x);
    // }
    // for (size_t i = 0; i < d->size; i++) {
    //     printf("  d[%zu] = %.2f\n", i, *(double *)vectorGet(d, i));
    // }
    // printf("  size=%zu capacity=%zu\n", d->size, d->capacity);
    // vectorFree(d);
}