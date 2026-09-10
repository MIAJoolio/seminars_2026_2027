#include <stdio.h>
#include <math.h>

int main() {
    // abs, fabs, pow, sqrt
    double a = 0.1111; // float
    double b = 0.1112; 
    int x = 3;
    int y = 9;
    
    if (fabs(a - b) < 1e-3){
        printf("Числа равны (с точностью до 3 знаков) дробный модуль %f %f, целочисленный модуль %d %d\n", fabs(a - b), a - b, abs(x - y), x - y);
    }
    
    // a * a * a

    printf("квадрат %f, double возведение в квадрат %f, корень %f\n", pow(x, 2), pow(a, b), sqrt(y));

    return 0;
}