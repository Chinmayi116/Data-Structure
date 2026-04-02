#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Enqueue Operation
void enqueue() {
    int value;
    
    if (rear == SIZE - 1) {
        printf("Queue is Full\n");
        return;
    }
    
    if (front == -1)
        front = 0;

    printf("Enter value: ");
    scanf("%d", &value);

    rear++;
    queue[rear] = value;

    printf("Inserted: %d\n", value);
}

// Dequeue Operation
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);
    front++;

    if (front > rear)
        front = rear = -1;
}

// Display Queue
void display() {
    int i;

    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements are: ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main Function
int main() {
    int choice;

    do {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }

    } while (choice != 4);

    return 0;
}
