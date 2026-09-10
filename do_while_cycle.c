#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int sum_of_digits(int number) {
    
    if (number < 0) {
        number = -number;
    }

    int sum = 0;

    do {
        sum += number % 10;
        number = number / 10;
    } while (number > 0);

    return sum;
}

int main () {
    assert(sum_of_digits(123) == 6);
    assert(sum_of_digits(-45) == 9);
    printf("Все тесты выполнены");
}