#include <stdio.h>
#include <string.h>

int main() {
    printf("%d\n", strcmp("Привет", "привет")); // для одинаковых строк выводит 0
    printf("%d\n", strcmp("banana", "banana")); // для одинаковых строк выводит -1
    return 0;
}
