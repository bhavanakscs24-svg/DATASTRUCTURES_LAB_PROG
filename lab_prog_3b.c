#include <stdio.h>

#define MAX 3

int cq[MAX];
int front = -1, rear = -1;

// Insert operation
void insert() {
    int item;

    // Overflow condition
    if ((rear + 1) % MAX == front) {
        printf("\nCircular Queue Overflow! Cannot insert.\n");
        return;
    }

    printf("Enter element to insert: ");
    scanf("%d", &item);

    // First insertion
    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    cq[rear] = item;
    printf("Element inserted successfully.\n");
}

// Delete operation
void delete() {
    // Empty condition
    if (front == -1) {
        printf("\nCircular Queue is Empty! Cannot delete.\n");
        return;
    }

    printf("Deleted element: %d\n", cq[front]);

    // Single element case
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Display operation
void display() {
    int i;

    if (front == -1) {
        printf("\nCircular Queue is Empty.\n");
        return;
    }

    printf("Circular Queue elements are:\n");
    i = front;
    while (i != rear) {
        printf("%d ", cq[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", cq[rear]);
}

// Main function
int main() {
    int choice;
    printf("NAME:Bhavana K S \nUSN:1BM24CS070");
    do {
        printf("\n--- CIRCULAR QUEUE MENU ---\n");
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
