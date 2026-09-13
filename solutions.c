#include "lab1.h"
#include <math.h>
#include <stdio.h>

// Задача 2 - Максимум из трёх чисел
int max_of_three(int a, int b, int c) {
    return 0;
}

// Задача 6 - Класс оценок
// 90 - 100 = "отлично"
// 75 - 89 = "хорошо"
// 60 - 74 = "удовлетворительно"
// 0 - 59 = "неудовлетворительно"
// && - и 
// || - или
// !() - не
const char* get_grade(int score) {
    if (score >= 75 && score < 90) return "хорошо";    
}

// Задача 7 - Евклидово расстояние
// pow, abs, fabs, sqrt
double euclidean_distance(double x1, double y1, double x2, double y2) {
    return 0;
}

// Вспомогательная функция для проверки простоты (можно писать сразу в задаче 9, но это плохой тон)
int is_prime(int n) {
    return 0;
}

// Задача 9 - Среднее арифметическое простых чисел в интервале
double average_primes_in_interval(int a, int b) {
    printf("a %d\n", is_prime(a));
    printf("b %d\n", is_prime(b));
    return 0.0;
}

// Задача 13 - День недели
const char* day_of_week(int day_num) {
    return "";
}

// Задача 14 - Подсчёт цифр в числе
int count_digits(int n) {
    return 0;
}