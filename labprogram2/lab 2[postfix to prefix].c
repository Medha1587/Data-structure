#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int priority(char x) {
    if (x == '^')
        return 3;

    if (x == '*' || x == '/')
        return 2;

    if (x == '+' || x == '-')
        return 1;

    return 0;
}

int main() {
    char infix[100], postfix[100];
    int i, j = 0;
    char x;

    printf("Enter infix expression: ");
    scanf("%99s", infix);

    for (i = 0; infix[i] != '\0'; i++) {
        x = infix[i];

        if (isalnum((unsigned char)x)) {
            postfix[j++] = x;
        }
        else if (x == '(') {
            push(x);
        }
        else if (x == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }

            if (top != -1 && stack[top] == '(') {
                pop();
            }
        }
        else if (x == '+' || x == '-' ||
                 x == '*' || x == '/' || x == '^') {

            while (top != -1 && stack[top] != '(' &&
                  (priority(stack[top]) > priority(x) ||
                  (priority(stack[top]) == priority(x)
                   && x != '^'))) {
                postfix[j++] = pop();
            }

            push(x);
        }
        else {
            printf("Invalid character: %c\n", x);
            return 1;
        }
    }

    while (top != -1) {
        if (stack[top] == '(') {
            printf("Invalid expression: unmatched parentheses\n");
            return 1;
        }

        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
