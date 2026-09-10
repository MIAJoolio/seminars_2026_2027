#include <stdio.h>

int main() {
    int a = 5;
    int b = 3;
    int c = 6;

    // %d
    // %f

    printf("Сумма: %d %d\n", a + b, a + b, a + b);
    printf("Разность: %d\n", a - b);
    printf("Умножение: %d\n", a * b);
    
    printf("Деление: %d\n", a / b);
    printf("Деление: %d\n", c / b);
    
    printf("Деление с остатком: %d\n", a % b);
    printf("Деление с остатком: %d\n", c % b);

    return 0;
}