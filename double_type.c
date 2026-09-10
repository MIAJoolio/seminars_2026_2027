#include <stdio.h>

// float 

int main() {
    double a = 5.55551; // 5.5555555555555
    double d = 5.55552; // 5.
    double b = 3.0;
    double c = 6.2;

    printf("Сумма: %lf %lf\n", a + b, a + b);
    printf("Разность: %.2f\n", a - b);
    printf("Разность: %.4f\n", a - b);
    
    printf("Деление: %f\n", a / b);
    printf("Деление: %f\n", c / b);

    // не работает
    // printf("Деление с остатком: %f\n", a % b);
    // // printf("Сумма: %d", a + b);
    // printf("Деление с остатком: %f\n", c % b);

    // && - и
    // || - или
    // !(a==b) 
    // True или False = True
    // True и False = False

    if (a == d) {
        printf("Цисла равны\n");
    } else {
        printf("Цисла не равны\n");
    }
    
    if (a - d < 1e-3) {
        printf("Цисла равны\n");
    } else {
        printf("Цисла не равны\n");
    }
    
    return 0;
}