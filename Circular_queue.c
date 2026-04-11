#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue() {
    int value;

    
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Queue is Full\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

  
    if (front == -1) {
        front = rear = 0;
    }
    
    else if (rear == SIZE - 1) {
        rear = 0;
    }
    else {
        rear++;
    }

    queue[rear] = value;
    printf("Inserted: %d\n", value);
}

void dequeue() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);


    if (front == rear) {
        front = rear = -1;
    }
    
    else if (front == SIZE - 1) {
        front = 0;
    }
    else {
        front++;
    }
}


void display() {
    int i;

    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements are: ");

    if (rear >= front) {
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (i = front; i < SIZE; i++) {
            printf("%d ", queue[i]);
        }
        for (i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }

    printf("\n");
}


int main() {
    int choice;

    do {
        printf("\n--- Circular Queue Menu ---\n");
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
