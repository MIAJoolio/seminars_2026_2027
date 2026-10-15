#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_SIZE 2

// *p, &p
// int, char, void - int *p - 8 байт
// (void *)p, (int *)p, (char *)p - конвертация к типу

typedef struct {
    void *data;         // блок памяти под элементы
    size_t size;        // сколько элементов лежит
    size_t elem_size;   // размер одного элемента в байтах
    size_t capacity;    // на сколько элементов выделена память
} Vector;
 

// size_t = 8 байт. Что это?
// Q: почему data указатель? что это дает?

Vector *vectorCreate(size_t elem_size) {
    if (elem_size == 0) return NULL;

    // Q: почему функция это указатель? что нужно использовать внутри sizeof?
    Vector *vector = malloc(sizeof(Vector));
    
    if (!vector) return NULL;

    // TODO: выделить data под MIN_SIZE элементов
    //       не вышло -> освободить vector и вернуть NULL
    // a[b] - []
    // *p - "*"
    // &p - 
    // Vector.size - "."
    // "->" vector->size
    vector->data = malloc(MIN_SIZE * elem_size);
    // Q: почему MIN_SIZE такой? какое значение допустимо?
    if (!vector->data) {
        free(vector);
        return NULL;
    }

    // TODO: заполнить size, elem_size, capacity
    vector->size = 0;
    vector->elem_size = elem_size;
    vector->capacity = MIN_SIZE;
    return vector;
}

void *vectorGet(Vector *vector, size_t index) {
    // получить указатель значения по индексу
    if (!vector || index >= vector->size) return NULL;
    return (char *)vector->data + index * vector->elem_size;    // TODO: адрес элемента index
}

// arr[0] = 10
int vectorSet(Vector *vector, int index, void *value) {
    // TODO условия, когда значения нельзя выставить
    if (!vector || !value || index < 0 || (size_t)index >= vector->size) return -1;
    // TODO: скопировать elem_size байт из value в элемент index
    memcpy(vectorGet(vector, index), value, vector->elem_size);
    // memcpy(*p_старое_значение, *p_новое_значение, размер элемента)
    return 0;
}

int vectorAppend(Vector *vector, void *el) {
    if (!vector || !el) return -1;

    if (vector->size == vector->capacity) {
        // TODO: увеличить capacity в 2 раза через realloc
        size_t new_capacity = vector->capacity * 2;
        void *new_data = realloc(vector->data, new_capacity * vector->elem_size);
        // 16 p1o1o2o3o4_p2o5o6 
        if (!new_data) return -1;
        vector->data = new_data;
        vector->capacity = new_capacity;
        // realloc(*p_структуры, новый размер) 
        //Q: почему результат realloc записываются в новую переменную?
    }

    // TODO: скопировать el в конец и увеличить size
    memcpy((char *)vector->data + vector->size * vector->elem_size, el, vector->elem_size);
    vector->size++;
    return 0;
}

// удаляет элемент index и возвращает его копию
void *vectorRemove(Vector *vector, size_t index) {
    void *item = vectorGet(vector, index);
    if (!item) return NULL;

    // TODO обнулить значение по index
    void *copy = malloc(vector->elem_size);
    if (!copy) return NULL;
    memcpy(copy, item, vector->elem_size);

    for (size_t i = index; i < vector->size - 1; i++) {
        // TODO: сдвинуть элемент i + 1 на место i
        vectorSet(vector, i, vectorGet(vector, i+1));
        // [1,2,3,4] 2->3 , 3->4
    }
    // TODO
    vector->size--;
    return copy;
}

void vectorFree(Vector *vector) {
    if (!vector) return;
    free(vector->data);
    free(vector);
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

    // printf("hello");
    // TODO создать список, но с фиксированного размера
    // int arr[4] = {10, 20, 30, 40};
    // printf("arr[0] = %d\n", arr[0]);
    // printf("arr[1] = %d\n", arr[6]);
    // printf("&arr[0] = %p, &arr[1] = %p  (diff = %td bytes)\n",
    //        (void *)&arr[0], (void *)&arr[1],
    //        (char *)&arr[1] - (char *)&arr[0]);
    
    // char c[10] = "hi";
    // printf("sizeof=%zu strlen=%zu\n", sizeof(c), strlen(c));
    // for (int i = 0; i < 5; i++){
    //     printf("\nc[%d]=%d %c\n", i, c[i], c[i]);
    // }

    printf("\n=== createVector ===\n");
    // TODO вектор размера 0
    Vector *zeroElVector = vectorCreate(0);
    printf("  vectorCreate(0) -> %s\n", zeroElVector ? "not NULL" : "NULL");

    // TODO вектор с типом int
    Vector *v = vectorCreate(sizeof(int));
    printf("  vectorCreate(sizeof(int)) -> %s\n", v ? "ok" : "NULL");
    // printInts(v);
    // TODO обратиться к созданному массиву
    // *p -> *(void *) -> *(int *)(void *) 
    printf("%p %d", v->data, *(int *)v->data);

    printf("\n=== vectorAppend ===\n");
    for (int x = 10; x <= 50; x += 10) {
        int rc = vectorAppend(v, &x);
        printf("  append %d -> returned %d\n", x, rc);
        printInts(v);
    }

    printf("  append NULL -> returned %d (expected -1)\n", vectorAppend(v, NULL));
    printInts(v);

    printf("\n=== vectorGet ===\n");
    printf("  get(0) = %d\n", *(int *)vectorGet(v, 0));
    printf("  get(4) = %d\n", *(int *)vectorGet(v, 4));
    printf("  get(5) = %s (out of range)\n", vectorGet(v, 5) ? "not NULL" : "NULL");
    printf("  get on NULL vector = %s\n", vectorGet(NULL, 0) ? "not NULL" : "NULL");
    // printInts(v);

    printf("\n=== vectorSet ===\n");
    int value = 99;
    printf("  set(0, 99) -> returned %d\n", vectorSet(v, 0, &value));
    printInts(v);
    printf("  set(5, 99) -> returned %d (expected -1)\n", vectorSet(v, 5, &value));
    printf("  set(-1, 99) -> returned %d (expected -1)\n", vectorSet(v, -1, &value));
    printf("  set(1, NULL) -> returned %d (expected -1)\n", vectorSet(v, 1, NULL));
    printInts(v);

    printf("\n=== vectorRemove ===\n");
    removeAndShow(v, 2);
    removeAndShow(v, 10); 
    removeAndShow(v, v->size-1);     

    printf("\n=== vectorFree ===\n");
    vectorFree(v);
    v = NULL;
    vectorFree(NULL);

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