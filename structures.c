#include <stdio.h> 
#include <stdlib.h> // malloc, free, exit
#include <string.h> // strlen, memcpy, strcpy, memset

int demo_stack_vs_heap_vars() {
    printf("--- 1. Стек vs Куча (переменные) ---\n");
    
    int n = 123;         // выделили 4 байта под переменную (стек)
    int a_arr[20];       // выделили 4*20 = 80 байт под массив (стек)
    int *k = &n;         // выделили 8 байт под указатель k (стек)
    int *m = a_arr;      // выделили 8 байт под указатель m (стек)

    printf("Стек: n = %d, адрес k = %p, *k = %d\n", n, (void*)k, *k);

    // Выделяем память на куче
    int *n_heap = (int*)malloc(sizeof(int)); // 4 байта
    *n_heap = 123;  
    
    int *a_heap = (int*)malloc(20 * sizeof(int)); // 80 байт
    for (size_t i = 0; i < 20; ++i) {  // заполняем нулями
        a_heap[i] = 0;
    }
    printf("Куча: *n_heap = %d, a_heap[0] = %d\n", *n_heap, a_heap[0]);

    // Указатели на указатели
    int **k_ptr = (int **)malloc(sizeof(int*));  
    int **m_ptr = (int **)malloc(sizeof(int*));  
    *k_ptr = n_heap;
    *m_ptr = a_heap;
    printf("Указатель на указатель: **k_ptr = %d\n", **k_ptr);

    // Освобождаем память
    free(n_heap); 
    free(a_heap);
    free(k_ptr);
    free(m_ptr);
    printf("Память успешно освобождена.\n\n");
    return 0;
}

int demo_arrays_and_pointers() {
    printf("--- 2. Массивы и арифметика указателей ---\n");
    
    int a[10] = {0};  // массив на стеке, заполнен нулями
    int *b = (int*)malloc(10 * sizeof(int));  // массив на куче (мусор)

    for (size_t i = 0; i < 10; ++i) {
        a[i] = i;
        b[i] = i;
    }

    printf("a - это указатель на нулевой элемент.\n");
    printf("*a      = %d (нулевой элемент)\n", *a);
    printf("a[3]    = %d (третий по индексу)\n", a[3]);
    printf("*(a+3)  = %d (равносильно a[3])\n", *(a+3));

    // printf("a[1000] = %d (читаем мусор из памяти по адресу a + 1000*sizeof(int))\n", a[1000]);

    free(b);
    printf("Память b освобождена.\n\n");
    return 0;
}

int demo_strings_readonly_vs_heap() {
    printf("--- 3. Строки: Read-Only vs Куча ---\n");
    
    char *a = "abcdefghijklmnopqrstu"; // Строковый литерал (Read-Only)
    printf("Литерал: a[0]=%c, a[3]=%c, a[21]=%d (символ конца строки '\\0')\n", a[0], a[3], a[21]);
    
    // a[3] = 'g'; // Segmentation Fault!

    // Выделяем память на куче для изменяемой копии
    size_t len = strlen(a) + 1; // +1 для '\0'
    char *b = (char*)malloc(len * sizeof(char));
    
    // Копируем строку a в b
    memcpy(b, a, len);
    printf("Копия на куче создана. Теперь её можно менять.\n");
    
    b[3] = 'b';  // Мы меняем свою копию в куче
    printf("Измененная копия: b[0]=%c, b[2]=%c, b[3]=%c, b[21]=%d\n", b[0], b[2], b[3], b[21]);

    free(b);
    printf("Память b освобождена.\n\n");
    return 0;
}

int get_length_from_user() {  
    int res;
    printf("Введите длину строки (например, 10): ");
    scanf("%d", &res);
    return res;
}

char *allocate_string(size_t len) { 
    char *res = (char *)malloc(len * sizeof(char));
    if (!res) {
        printf("unable to allocate enough memory!\n");
        exit(-1);
    }
    // Инициализируем, чтобы не было мусора
    memset(res, 0, len); 
    return res;
}

int demo_functions_returning_pointers() {
    printf("--- 4. Функции и динамическая память ---\n");
    
    int len = 10; // = get_length_from_user();
    printf("Запрошена длина: %d\n", len);
    
    char *asd = allocate_string(len);  
    strcpy(asd, "TestStr"); // Записываем тестовые данные
    printf("Успешно выделено и записано: %s\n", asd);

    free(asd);
    printf("Память asd освобождена.\n\n");
    return 0;
}

int main() {
    printf("=== ЗАПУСК ДЕМО-СКРИПТА УКАЗАТЕЛЕЙ ===\n\n");

    demo_stack_vs_heap_vars();
    demo_arrays_and_pointers();
    demo_strings_readonly_vs_heap();
    demo_functions_returning_pointers();

    printf("--- 5. Демонстрация 'Ниндзя-бага' (из лекции) ---\n");
    char str_val_array[] = "Hello";
    char str_val_array2[] = "world";

    printf("До изменения:\n");
    printf("str_val_array  = '%s' (адрес: %p)\n", str_val_array, (void*)str_val_array);
    printf("str_val_array2 = '%s' (адрес: %p)\n", str_val_array2, (void*)str_val_array2);

    str_val_array[0] = 'w'; // Безопасно: меняем 'H' на 'w' внутри своего массива
    
    // выход за массив
    str_val_array[10] = 'W'; 

    printf("\nПосле изменения (включая выход за границы str_val_array[10] = 'W'):\n");
    printf("str_val_array  = '%s'\n", str_val_array);
    printf("str_val_array2 = '%s' <--- Обратите внимание, изменилась ли эта строка?\n", str_val_array2);
    
    return 0;
}