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
    setbuf(stdout, NULL);

    puts("=== vectorCreate ===");
    Vector *bad = vectorCreate(0);
    printf("  vectorCreate(0) -> %s\n", bad ? "not NULL" : "NULL");

    Vector *v = vectorCreate(sizeof(int));
    printf("  vectorCreate(sizeof(int)) -> %s\n", v ? "ok" : "NULL");
    printInts(v);

    puts("\n=== vectorAppend ===");
    for (int x = 10; x <= 50; x += 10) {
        int rc = vectorAppend(v, &x);
        printf("  append %d -> returned %d\n", x, rc);
        printInts(v);
    }
    printf("  append NULL -> returned %d (expected -1)\n", vectorAppend(v, NULL));
    printInts(v);

    puts("\n=== vectorGet ===");
    printf("  get(0) = %d\n", *(int *)vectorGet(v, 0));
    printf("  get(4) = %d\n", *(int *)vectorGet(v, 4));
    printf("  get(5) = %s (out of range)\n", vectorGet(v, 5) ? "not NULL" : "NULL");
    printf("  get on NULL vector = %s\n", vectorGet(NULL, 0) ? "not NULL" : "NULL");
    printInts(v);

    puts("\n=== vectorSet ===");
    int value = 99;
    printf("  set(0, 99) -> returned %d\n", vectorSet(v, 0, &value));
    printInts(v);
    printf("  set(5, 99) -> returned %d (expected -1)\n", vectorSet(v, 5, &value));
    printf("  set(-1, 99) -> returned %d (expected -1)\n", vectorSet(v, -1, &value));
    printf("  set(1, NULL) -> returned %d (expected -1)\n", vectorSet(v, 1, NULL));
    printInts(v);

    puts("\n=== vectorRemove ===");
    removeAndShow(v, 2);               // remove from the middle
    removeAndShow(v, 0);               // remove the first item
    removeAndShow(v, v->size - 1);     // remove the last item
    removeAndShow(v, 10);              // out of range
    removeAndShow(v, 0);               // remove until empty
    removeAndShow(v, 0);
    removeAndShow(v, 0);               // remove from empty

    puts("\n=== vectorFree ===");
    vectorFree(v);
    v = NULL;
    puts("  freed v");
    vectorFree(NULL);
    puts("  vectorFree(NULL) is safe");

    puts("\n=== other type: double ===");
    Vector *d = vectorCreate(sizeof(double));
    for (double x = 1.5; x <= 3.0; x += 0.5) {
        vectorAppend(d, &x);
    }
    for (size_t i = 0; i < d->size; i++) {
        printf("  d[%zu] = %.2f\n", i, *(double *)vectorGet(d, i));
    }
    printf("  size=%zu capacity=%zu\n", d->size, d->capacity);
    vectorFree(d);
}