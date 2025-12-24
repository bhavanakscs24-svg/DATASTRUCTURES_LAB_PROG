#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void create() {
    int n, i, value;
    struct node *temp, *newnode;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newnode->data);

        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
    printf("Doubly linked list created successfully.\n");
}

void insert_left() {
    int key, value;
    struct node *temp, *newnode;

    if (head == NULL) {
        printf("List is empty. Cannot insert.\n");
        return;
    }

    printf("Enter the value of the node to insert left of: ");
    scanf("%d", &key);
    printf("Enter new node data: ");
    scanf("%d", &value);

    temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;

    newnode->next = temp;
    newnode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newnode;
    else
        head = newnode; // New node becomes head

    temp->prev = newnode;

    printf("Node inserted successfully to the left of %d.\n", key);
}

void delete_node() {
    int key;
    struct node *temp;

    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    printf("Enter value of node to delete: ");
    scanf("%d", &key);

    temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next; // Node to delete is head

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);

    printf("Node with value %d deleted successfully.\n", key);
}

void display() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    printf("Doubly linked list contents:\n");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;
    printf("NAME:Bhavana K S\nUSN:1BM24CS070");
    do {
        printf("\n--- DOUBLY LINKED LIST MENU ---\n");
        printf("1. Create List\n");
        printf("2. Insert Left of a Node\n");
        printf("3. Delete Node by Value\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: create(); break;
            case 2: insert_left(); break;
            case 3: delete_node(); break;
            case 4: display(); break;
            case 5: printf("Exiting program.\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 5);

    return 0;
}
