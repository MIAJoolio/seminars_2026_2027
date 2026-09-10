#include <stdio.h>
#include <string.h>
#include <assert.h>

// switch (expression)
// {
// case constant expression:
//     /* code */
//     break;
// case constant expression:
//     /* code */
//     break;
// default:
//     break;
// }

// автомат, в котором нужно ввести число от 1 до 9
// 1-3 то будет мишка
// 4-6 то будет машинка
// 7-9 то будет кукла
// char "a" - 10, "v" - 35
const char* get_gift(int code){
    switch (code)
    {
    case 1:
    case 2:
    case 3:
        return "мишка";
    case 4:
    case 5:
    case 6:
        return "машинка";
    case 7:
    case 8:
    case 9:
        return "кукла";
    default:
        return "некорректный код";
    }
}

int main() {
    assert(strcmp(get_gift(1), "мишка") == 0);
    assert(strcmp(get_gift(2), "машинка") == 0);
    assert(strcmp(get_gift(7), "кукла") == 0);
    assert(strcmp(get_gift(17), "некорректный код") == 0);
    printf("Все тесты выполнены");
    return 0;
}

// if (code == 1 || code == 2 || code == 3) {
//     return "мишка";
// } else if (code == 4 || code == 5 || code == 6) {
//     return "машинка";
// } else if (code == 7 || code == 8 || code == 9) {
//     return "кукла";
// } else {
//     return "некорректно";
// }