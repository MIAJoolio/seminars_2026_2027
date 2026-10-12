// Запуск: gcc -DMUT=1 mutations.c test_lab2_blank.c -o mut; ./mut
#include "seminar.h"
#include <stdlib.h>
#include <stdio.h>

int gcd(int a, int b) {
#if MUT == 1
    // забыли модуль
#else
    if (a < 0) a = -a;
    if (b < 0) b = -b;
#endif
#if MUT == 2
    // перебор вместо Евклида
    int g = a < b ? a : b;
    if (g == 0) return a + b;
    while (a % g != 0 || b % g != 0) g--;
    return g;
#else
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
#endif
}

int reduce_fraction(int *pnum, int *pden) {
#if MUT == 3
    if (*pden == 0) {
        return 1;
    }
    printf("%d, %d\n", *pnum, *pden);
#elif MUT == 4
    printf("%d, %d\n", *pnum, *pden);
    // нет проверки на 0
#else
    if (*pden == 0) {
        return 0;
    }
#endif
    int g = gcd(*pnum, *pden);
    *pnum = *pnum / g;
    *pden = *pden / g;
#if MUT == 5
    if (*pden < 0) {
        *pden = -*pden;
    }
#elif MUT == 6
    if (*pden <= 0) {
        *pnum = -*pnum;
        *pden = -*pden;
    }
#else
    if (*pden < 0) {
        *pnum = -*pnum;
        *pden = -*pden;
    }
#endif
    return 1;
}

int primes_up_to(int n, int **pprimes) {
#if MUT == 7
    if (n <= 2) {
#else
    if (n < 2) {
#endif
        return 0;
    }
    char *crossed = (char *)calloc(n + 1, sizeof(char));
    if (crossed == NULL) {
        return 0;
    }
    int count = 0;
#if MUT == 8
    for (int i = 2; i < n; i++) {
#else
    for (int i = 2; i <= n; i++) {
#endif
        if (crossed[i] == 0) {
            count++;
            for (int j = 2 * i; j <= n; j += i) {
                crossed[j] = 1;
            }
        }
    }

    int *primes = (int *)malloc(count * sizeof(int));
    if (primes == NULL) {
        free(crossed);
        return 0;
    }
    int k = 0;
#if MUT == 8
    for (int i = 2; i < n; i++) {
#else
    for (int i = 2; i <= n; i++) {
#endif
        if (crossed[i] == 0) {
            primes[k] = i;
            k++;
        }
    }
#if MUT == 9
    // забыли free(crossed)
#else
    free(crossed);
#endif

#if MUT == 10
    pprimes = &primes;
#else
    *pprimes = primes;
#endif
    return count;
}
