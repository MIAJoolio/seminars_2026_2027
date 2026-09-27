#include "seminar.h"
#include <stdlib.h>

// Задача 1 - НОД
// Логика: gcd(a, b) = gcd(b, a % b), пока b не станет 0
// 18, 12 -> 12, 6 -> 6, 0 -> ответ 6
int gcd(int a, int b) {
    return 0;
}

// Задача 2 - Сокращение дроби
// *pnum - числитель, *pden - знаменатель
int reduce_fraction(int *pnum, int *pden) {
    return 0;
}

// Задача 3 - Решето Эратосфена
int primes_up_to(int n, int **pprimes) {
    // TODO: если n < 2 - простых нет

    // вычёркиваем составные числа
    char *crossed = (char *)calloc(n + 1, sizeof(char));
    if (crossed == NULL) {
        return 0;
    }
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (crossed[i] == 0) {
            count++;
            for (int j = 2 * i; j <= n; j += i) {
                crossed[j] = 1;
            }
        }
    }

    // TODO: выделить память под count чисел (malloc)
    // TODO: переписать туда невычеркнутые числа от 2 до n
    // TODO: освободить crossed
    // TODO: записать адрес массива в *pprimes
    return 0;
}
