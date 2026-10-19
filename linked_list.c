#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    void *data; // содержимое узла
    struct Node *next; // указатель на следующий узел
} Node;

typedef struct {
    Node *head;
    size_t elem_size; // типичный размер элементов в байтах
    size_t size; // количество элементов в списке
} GenericList;

// функция создания (выделения памяти, обновление параметров) структуры GenericList
GenericList *createList(size_t elem_size) {
    if (elem_size == 0) return NULL;

    GenericList *list = malloc(sizeof(GenericList));
    if (!list) return NULL;
    // {
        // fprintf(stderr, "Memory allocation failed\n");
        // exit(EXIT_FAILURE); // EXIT_FAILURE = 1
    // }

    // TODO: пустой список — чему равен head?
    list->elem_size = elem_size;
    return list;
}

// добавление нового элемента
// в идеальном код нужно сделать еще createListNode.
// Нужно будет предусмотреть, что память не выделится и сделать аналогичную обработку как
// в createList с использованием EXIT_FAILURE
void appendItem(GenericList *list, void *data) {
    if (!list || !data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE); // EXIT_FAILURE = 1
    }

    // TODO выделяем память под узел
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE); // EXIT_FAILURE = 1
    }

    new_node->data = malloc(list->elem_size);
    if (!new_node->data) {
        // TODO вывести ошибку и что-то еще сделать
    }
    // TODO скопировать data в new_node->data
    // https://en.cppreference.com/c/string/byte/memcpy
    // TODO задать значение параметра next

    // случай (1) наш список пустой. что делать?
    if (list->head == NULL) {
        list->head = new_node;
        list->size++;
        return;
    }
    // случай (2) наш список не пустой. что делать?
    Node *current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    list->size++;
    // почему не нужно пустого return?
    // почему void тип функции?
}

// findItem: находит индекс первого элемента, равного заданному значению.
// Возвращает:
// - Индекс найденного элемента (начиная с 0),
// - или -1, если элемент не найден или список пуст.
// EqualsFunc функции сравнения
typedef int (*EqualsFunc)(const void *a, const void *b);
// пример такой функции
int intEquals(const void *a, const void *b) {
    return *(int *)a == *(int *)b;
}

int findItem(GenericList *list, void *value, EqualsFunc cmp)
{
    // TODO условия для -1
    // TODO ищем содержимое в списке
    // step 1 - найти начало списка
    // step 2 - начать итерацию по списку
    // step 3 - проверка нашей функцией
    // step 4 - тело цикла
    // step 5 - если не получилось, то нужно что-то вернуть
}

// удаляем узел с индексом index и возвращает его содержимое
// Возвращает:
// - Указатель на копию данных (память выделена внутри функции — нужно освободить),
// - NULL — если индекс вне диапазона или список пуст.

void *popItem(GenericList *list, size_t index) {
    // TODO условия

    // TODO обозначим узлы (current, previous)

    // TODO поиск элемента с индексом index

    // TODO создать место для удаляемого значения

    // TODO Удаление узла

    // TODO освобождаем память

    // TODO обновляем размер и возвращаем удаляемое значение
}

void freeNode(Node *node)
{
    if (!node) return;

    free(node->data);
    free(node);
}

void freeList(GenericList *list)
{
    if (!list)
        return;

    // TODO надо обойти лист и удалять узлы
    // начинаем с головы
    // создаем вспомогательный узел next
    free(list);
}

// функция обновления значений
// Возвращает:
// - если выполнилось без ошибок то 0,
// - или -1, если элемент не найден или список пуст.
// int setItem(GenericList *list, void *data, size_t index)
// какие шаги?

// функция возвращения содержимого узла
// void* getItem(GenericList *list, size_t index)
// какие шаги?

// вспомогательные функции
unsigned int listLength(GenericList *list)
{
    if (!list)
        return 0;

    return list->size;
}

void printList(GenericList *list) {
    printf("  ");
    for (Node *current = list->head; current; current = current->next) {
        printf("%d -> ", *(int *)current->data);
    }
    printf("NULL  (length=%u)\n", listLength(list));
}

int main(void) {
    setbuf(stdout, NULL);
    // TODO создаем список для int

    printf("append:\n");
    for (int x = 10; x <= 30; x += 10) {    
        // TODO заполняем список значениями 10, 20, 30
    }
    printList(list);

    printf("find:\n");
    int a = 10, b = 30, c = 99;
    // TODO поиск первого элемента: 10
    // TODO поиск последнего элемента: 30
    // TODO поиск отсутствующего элемента: 99

    printf("pop:\n");
    // TODO удаляем из середины: индекс 1
    // TODO удаляем хвост: индекс 1
    // TODO удаляем по несуществующему индексу: 5
    // TODO удаляем голову: индекс 0
    printList(list);

    printf("empty list:\n");
    // TODO удаляем из пустого списка: индекс 0
    // TODO поиск в пустом списке: 10
    // TODO добавляем в список 10-ку
    printList(list);

    freeList(list);
}
