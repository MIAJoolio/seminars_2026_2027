#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "lab1.h"

void log_result(const char* task, const char* message) {
    printf("[%s] %s\n", task, message);
}

int main() {
    // ====== Задача 2: Максимум из трёх чисел ======
    log_result("Задача 2", "Начинаем тестирование");
    assert(max_of_three(5, 8, 2) == 8);
    assert(max_of_three(2, 1, 1) == 2);
    assert(max_of_three(1, 1, 2) == 2);
    assert(max_of_three(1, 1, 1) == 1);
    log_result("Задача 2", "Все тесты пройдены");

    // ====== Задача 6: Класс оценок ======
    log_result("Задача 6", "Начинаем тестирование");
    assert(strcmp(get_grade(85), "хорошо") == 0);
    log_result("Задача 6", "Все тесты пройдены");

    // ====== Задача 7: Евклидово расстояние ======
    log_result("Задача 7", "Начинаем тестирование");
    assert(fabs(euclidean_distance(0,0,3,4) - 5.0) < 1e-6);
    assert(fabs(euclidean_distance(0,0,0,0) - 0.0) < 1e-6);
    log_result("Задача 7", "Все тесты пройдены");


    // // ====== Задача 9: Среднее простых чисел ======
    // log_result("Задача 9", "Начинаем тестирование");
    // assert(fabs(average_primes_in_interval(17, 9) - 2.0) < 1e-6);
    // assert(fabs(average_primes_in_interval(0, 10) - 4.25) < 1e-6);
    // log_result("Задача 9", "Все тесты пройдены");

    // ====== Задача 13: День недели ======
    log_result("Задача 13", "Начинаем тестирование");
    assert(strcmp(day_of_week(1), "понедельник") == 0);
    assert(strcmp(day_of_week(3), "понедельник") == 0); 
    assert(strcmp(day_of_week(0), "некорректно") == 0);
    log_result("Задача 13", "Все тесты пройдены");

    // ====== Задача 14: Подсчёт цифр ======
    log_result("Задача 14", "Начинаем тестирование");
    assert(count_digits(0) == 1);
    assert(count_digits(6) == 1);
    assert(count_digits(2020) == 4);
    assert(count_digits(-123) == 3);
    log_result("Задача 14", "Все тесты пройдены");

    printf("Все тесты пройдены успешно!\n");
    return 0;
}
