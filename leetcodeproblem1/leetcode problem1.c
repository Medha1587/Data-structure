#include <stdio.h>
#include <string.h>

int main() {
    char word[] = "abcdef";
    char ch = 'd';
    int length = strlen(word);

    char stack[100];
    int top = -1;
    int target_index = -1;

    for (int i = 0; i < length; i++) {
        stack[++top] = word[i];

        if (word[i] == ch) {
            target_index = i;
            break;
        }
    }

    if (target_index != -1) {
        for (int i = 0; i <= target_index; i++) {
            word[i] = stack[top--];
        }
    }

    printf("Output: %s\n", word);

    return 0;
}
