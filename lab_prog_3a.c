#include <stdio.h>

#define MAX 3

int queue[MAX];
int front = -1, rear = -1;

// Insert operation
void insert() {
    int item;
    if (rear == MAX - 1) {
        printf("\nQueue Overflow! Cannot insert element.\n");
    } else {
        if (front == -1)
            front = 0;
        printf("Enter element to insert: ");
        scanf("%d", &item);
        rear++;
        queue[rear] = item;
        printf("Element inserted successfully.\n");
    }
}

// Delete operation
void delete() {
    if (front == -1 || front > rear) {
        printf("\nQueue is Empty! Cannot delete element.\n");
    } else {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}

// Display operation
void display() {
    int i;
    if (front == -1 || front > rear) {
        printf("\nQueue is Empty.\n");
    } else {
        printf("Queue elements are:\n");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    printf("NAME:Bhavani\nUSN:1BM24CS071");
    do {
        printf("\n--- LINEAR QUEUE MENU ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: printf("Exiting program.\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
