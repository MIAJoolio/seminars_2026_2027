#include "lab1.h"
#include <math.h>
#include <stdio.h>

// Задача 2 - Максимум из трёх чисел
int max_of_three(int a, int b, int c) {
    int max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    return max;
}

int max_of_three(int a, int b, int c) {
    if (a >= b && a >= c) {
        return a;
    } else if (b >= a && b >= c) {
        return b;
    } else {
        return c;
    }
}

// Задача 6 - Класс оценок
// 90 - 100 = "отлично"
// 75 - 89 = "хорошо"
// 60 - 74 = "удовлетворительно"
// 0 - 59 = "неудовлетворительно"
const char* get_grade(int score) {
    if (score >= 75 && score < 90) return "хорошо";    
}

// // Задача 7 - Евклидово расстояние
// double euclidean_distance(double x1, double y1, double x2, double y2) {
//     return sqrt(pow(x2-x1, 2)+pow(y2-y1, 2));
// }

double euclidean_distance(double x1, double y1, double x2, double y2) {
    double dx = (x2-x1);
    double dy = (y2-y1);
    return sqrt(dx*dx+dy*dy);
}

// Вспомогательная функция для проверки простоты (можно писать сразу в задаче 9, но это плохой тон)
int is_prime(int n) {
    if (n <= 1) return 0;
    
    int i = 0; 
    
    for (i = 2; i <= n / i; i+=1) { // i++
        if (n % i == 0) return 0;
        printf("%d\n", i);
    }

    return 1;
}

// Задача 9 - Среднее арифметическое простых чисел в интервале
double average_primes_in_interval(int a, int b) {
    printf("a %d\n", is_prime(a));
    printf("b %d\n", is_prime(b));
    return 0.0;
}

// Задача 13 - День недели
const char* day_of_week(int day_num) {
    switch (day_num) {
        case 1:
        case 3:
            return "понедельник";
        case 2: return "вторник";
        default: return "некорректно";
    }
}

// Задача 14 - Подсчёт цифр в числе
int count_digits(int n) {
    if (n < 0) {
        n = -n;
    }
    
    int count = 0;

    do {
        count += 1; // count++
        n /= 10; // 123 -> 12 -> 1 -> 0; 6 -> 0; 
    } while (n > 0);

    return count;
}

// // Задача 14 - Подсчёт цифр в числе
// int count_digits(int n) {
//     if (n == 0) return 1;
//     if (n < 0) {
//         n = -n;
//     }
    
//     int count = 0;

//     while (n > 0) {
//         count += 1; // count++
//         n /= 10; // 123 -> 12 -> 1 -> 0; 6 -> 0; 
//     };

//     return count;
// }