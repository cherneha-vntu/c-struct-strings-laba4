#include <stdio.h>
#include <string.h>

#define ROUTES_COUNT 5

struct ROUTE {
    char number[15];
    char start_point[50];
    char end_point[50];
};

struct ROUTE routes[ROUTES_COUNT] = {
    {"15", "ЦУМ", "Кінотеатр \"Луцьк\""},
    {"12", "КРЗ", "вул. Володимирська"},
    {"1",  "ЛПЗ", "КРЗ"},
    {"25", "вул. Карбишева", "вул. Володимирська"},
    {"10", "Шота Руставелі", "вул. Карбишева"}
};

void showMarsh(char *number) {
    int found = 0;

    for (int i = 0; i < ROUTES_COUNT; i++) {
        if (strcmp(routes[i].number, number) == 0) {
            printf("Маршрут знайдено!\n"
                   "  Номер:    %s\n"
                   "  Напрямок: %s — %s\n",
                   routes[i].number,
                   routes[i].start_point,
                   routes[i].end_point);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Помилка: маршрут з номером '%s' не знайдено.\n", number);
    }
}

int main(void) {
    char search_num[15];

    printf("Введіть номер маршруту для пошуку: ");
    scanf("%14s", search_num);

    showMarsh(search_num);

    return 0;
}
