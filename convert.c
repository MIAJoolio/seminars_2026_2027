#include <stdio.h>

int main() {
    int total_sum = 22;
    int c = 3;

    double result = total_sum / c;
    printf("Резутат: %f\n", result); // 7.000000

    // (тип_данных)название_переменной
    double result1 = (double)total_sum / c; // 7.333333
    printf("Резутат: %f\n", result1);

    double pi = 3.1412;
    int whole_part = (int)pi;
    printf("Резутат: %d\n", whole_part);

    int a = 5;
    double b = 2.0;
    double result2 = a + b; // a автоматически станет 5.0, результат 7.0
    printf("Резутат: %.2f", result2);

    return 0;
}