#ifndef SEMINAR_H
#define SEMINAR_H
#define TIME_PER_SEC 1000

// Задача 1 - НОД
// Наибольший общий делитель чисел a и b.
int gcd(int a, int b);

// Задача 2 - Сокращение дроби
int reduce_fraction(int *pnum, int *pden);

// Задача 3 - Простые числа до n
// Найти все простые числа от 2 до n включительно
int primes_up_to(int n, int **pprimes);

#endif
