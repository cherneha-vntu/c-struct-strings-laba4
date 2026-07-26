#include <stdio.h>

int wordLength(const char *s, int n) {
    int word_count = 0;
    int len = 0;
    int in_word = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n') {
            if (!in_word) {
                in_word = 1;
                word_count++;
            }
            if (word_count == n) {
                len++;
            }
        } else {
            if (in_word) {
                in_word = 0;
                if (word_count == n) {
                    return len;
                }
            }
        }
    }

    return (word_count == n) ? len : 0;
}

int main(void) {
    char text[256];
    int n;

    printf("Введіть речення: ");
    if (fgets(text, sizeof(text), stdin) == NULL) {
        printf("Помилка читання.\n");
        return 1;
    }

    printf("Введіть порядковий номер слова: ");
    scanf("%d", &n);

    int length = wordLength(text, n);

    if (length > 0) {
        printf("Довжина слова № %d: %d символів.\n", n, length);
    } else {
        printf("Слова № %d у рядку немає.\n", n);
    }

    return 0;
}
