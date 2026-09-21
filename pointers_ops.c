#include <stdio.h> 
#include <math.h>


int pointers_show() {
    // создаём и инициализируем переменные различных типов
    char symbol = 'A'; // 1
    int num = 5; // 4
    double real = 3.1415926; // 8
    
    // выводим адреса переменных на экран
    printf("Variable symbol address: %p\n\n", &symbol);
    printf("Variable num address: %p\n\n", &num);
    printf("Variable real address: %p\n\n", &real);

    return 0;
}

int pointers_operations() {
    int x, y;
    int *px; // указатель содержит адресс на для обращения к другой переменной

    x = 42;
    px = &x; // & - амперсант

    y = *px;
    // y = x
    // y = x;

    printf("%d %p %d\n", x, px, y);

    // y = *px + 10;
    // printf("%d %p %d\n", x, px, y);
    
    // double c;
    // c = sqrt((double)*px);
    // printf("%f %f\n", c, (double)*px);

    *px = 0;
    printf("%d %p\n", *px, (void*)px);

    *px += 1;
    printf("%d %p\n", *px, (void*)px);

    (*px)++;
    printf("%d %p\n", *px, (void*)px);

    int *py;
    py = px;
    printf("%p %p\n", (void*)px, (void*)py);

    // нельзя задавать выражения типа &(x+1)
    // нельзя задавать выражения типа &3
    y = *(px + 10);
    printf("%d %p %d\n", x, px, y);
}

int age_fun() {
        int age = 0;
        int *p_age; // объявляем p_age — указатель на int
        p_age = &age; // адрес переменной age сохраняем в указатель p_age
                      // теперь указатель p_age хранит адрес переменной age
        
        printf("Variable age address: %p\n\n", p_age);

        printf("Enter your age:\n");
        scanf("%d", p_age); // передаём адрес переменной age, 
                            // используя указатель p_age
        // scanf("%d", age);

        printf("Age: %d\n", age);
        
        return 0;
}

void try_to_change_value(int x) {
    // функция пытается изменить переменную, передавая её по значению (копией)
    printf("Внутри функции ДО: x = %d\n", x);
    x = 100;
    printf("Внутри функции ПОСЛЕ: x = %d\n", x);
}

void change_with_pointer(int *p_x) {
    printf("Внутри функции ДО: *p_x = %d\n", *p_x);
    // функция изменяет переменную, принимая указатель (адрес оригинала)
    *p_x = 100; 
    printf("Внутри функции ПОСЛЕ: *p_x = %d\n", *p_x);
}


int main() {
    
    pointers_show();
    pointers_operations();
    age_fun();

    int age = 0; 
    try_to_change_value(age);
    printf("В main после вызова: age = %d (НЕ ИЗМЕНИЛСЯ!)\n\n", age);
    
    change_with_pointer(&age); // Передаем адрес!
    printf("В main после вызова: age = %d (ИЗМЕНИЛСЯ!)\n", age);
    
}