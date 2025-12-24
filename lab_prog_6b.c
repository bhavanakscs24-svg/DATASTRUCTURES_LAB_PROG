#include <stdio.h>
#include <stdlib.h>

// Node definition
struct node {
    int data;
    struct node *next;
};

struct node *top = NULL; // For Stack
struct node *front = NULL; // For Queue
struct node *rear = NULL; // For Queue

// ----------------- STACK OPERATIONS -----------------

// Push operation
void push() {
    int value;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter value to push: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = top;
    top = newnode;

    printf("Pushed %d into stack.\n", value);
}

// Pop operation
void pop() {
    if (top == NULL) {
        printf("Stack Underflow! Cannot pop.\n");
        return;
    }
    struct node *temp = top;
    printf("Popped element: %d\n", temp->data);
    top = top->next;
    free(temp);
}

// Display Stack
void display_stack() {
    struct node *temp = top;
    if (temp == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// ----------------- QUEUE OPERATIONS -----------------

// Enqueue operation
void enqueue() {
    int value;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter value to enqueue: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = NULL;

    if (front == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }

    printf("Enqueued %d into queue.\n", value);
}

// Dequeue operation
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow! Cannot dequeue.\n");
        return;
    }
    struct node *temp = front;
    printf("Dequeued element: %d\n", temp->data);
    front = front->next;
    free(temp);
    if (front == NULL)
        rear = NULL;
}

// Display Queue
void display_queue() {
    struct node *temp = front;
    if (temp == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements (front to rear): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// ----------------- MAIN MENU -----------------

int main() {
    int choice, subchoice;
    printf("NAME:Bhavani\nUSN:1BM24CS071");
    do {
        printf("\n--- LINKED LIST SIMULATION ---\n");
        printf("1. Stack Operations\n");
        printf("2. Queue Operations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                do {
                    printf("\n--- STACK MENU ---\n");
                    printf("1. Push\n2. Pop\n3. Display Stack\n4. Back\n");
                    printf("Enter your choice: ");
                    scanf("%d", &subchoice);

                    switch (subchoice) {
                        case 1: push(); break;
                        case 2: pop(); break;
                        case 3: display_stack(); break;
                        case 4: break;
                        default: printf("Invalid choice!\n");
                    }
                } while (subchoice != 4);
                break;

            case 2:
                do {
                    printf("\n--- QUEUE MENU ---\n");
                    printf("1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Back\n");
                    printf("Enter your choice: ");
                    scanf("%d", &subchoice);

                    switch (subchoice) {
                        case 1: enqueue(); break;
                        case 2: dequeue(); break;
                        case 3: display_queue(); break;
                        case 4: break;
                        default: printf("Invalid choice!\n");
                    }
                } while (subchoice != 4);
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 3);

    return 0;
}
