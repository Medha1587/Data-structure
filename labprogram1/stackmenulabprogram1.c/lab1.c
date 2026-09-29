#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stack[MAX];
int top = -1;
void push(int element);
int pop();
void display();

int main() {
    int choice, element;

    printf("--- Stack Simulation (Max Size: %d) ---\n", MAX);

    while (1) {
        printf("\n=== STACK OPERATIONS MENU ===\n");
        printf("1. Push (Add Element)\n");
        printf("2. Pop (Remove Element)\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("❌ Invalid input! Please enter a valid integer.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter integer element to push: ");
                if (scanf("%d", &element) == 1) {
                    push(element);
                } else {
                    printf("❌ Invalid element! Only integers are allowed.\n");
                    while (getchar() != '\n');
                }
                break;

            case 2:
                element = pop();
                if (element != -1) {
                    printf("💥 Successfully popped %d from the stack.\n", element);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf(" Invalid choice! Please select an option from the menu.\n");
        }
    }
    return 0;
}

// Push operation
void push(int element) {
    // Check for Stack Overflow
    if (top >= MAX - 1) {
        printf(" Stack Overflow! Cannot push element. The stack is full.\n");
    } else {
        top++;
        stack[top] = element;
        printf("Successfully pushed %d onto the stack.\n", element);
    }
}

// Pop operation
int pop() {
    // Check for Stack Underflow
    if (top == -1) {
        printf(" Stack Underflow! Cannot pop element. The stack is empty.\n");
        return -1; // Return -1 to indicate error/empty stack
    } else {
        int popped_element = stack[top];
        top--;
        return popped_element;
    }
}

// Display operation
void display() {
    // Check if stack is empty
    if (top == -1) {
        printf("The stack is currently empty.\n");
    } else {
        printf("\n--- Current Stack (Top to Bottom) ---\n");
        for (int i = top; i >= 0; i--) {
            printf("| %d |\n", stack[i]);
        }
        printf("-------------------------------------\n");
    }
}
