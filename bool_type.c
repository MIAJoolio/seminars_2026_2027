#include <stdio.h>

int main() {
    int a = 5;
    int b = 3;
    int c = 6;

    // && - и
    // || - или
    // !(a==b) - не

    // bool сравнения
    // True (||) или False = True
    // True (&&) и False = False

    // if (условие1 && условие2) {
    //     // тело условия
    // }

    // if (c == b && c == c) {
    // if (c == b || c == c) {
    if (!(c == b) && c == c) {
        printf("Цисла равны\n");
    } else {
        printf("Цисла не равны\n");
    }

    // тернарный оператор
    printf("a==b: %s\n", (a==b) ? "True" : "False");
    printf("c==c: %s\n", (c==c) ? "True" : "False");
    return 0;
}