#include <stdio.h>

#define MAX 3 // Maximum size of stack

int stack[MAX];
int top = -1;

// Function to push an element into stack
void push() {
    int item;
    if (top == MAX - 1) {
        printf("\nStack Overflow! Cannot push element.\n");
    } else {
        printf("\nEnter the element to push: ");
        scanf("%d", &item);
        top++;
        stack[top] = item;
        printf("Element %d pushed into stack.\n", item);
    }
}

// Function to pop an element from stack
void pop() {
    if (top == -1) {
        printf("\nStack Underflow! Cannot pop element.\n");
    } else {
        printf("\nPopped element: %d\n", stack[top]);
        top--;
    }
}

// Function to display stack elements
void display() {
    int i;
    if (top == -1) {
        printf("\nStack is empty.\n");
    } else {
        printf("\nStack elements are:\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

// Main function
int main() {
    int choice;
    printf("NAME: Bhavani \nUSN: 1BM24CS071");
    do {
        printf("\n--- STACK OPERATIONS MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
