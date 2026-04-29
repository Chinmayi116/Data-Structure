#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prer;
};

struct Node *head = NULL;

void insert_beg(int value)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = value;

    if (head == NULL)
    {
        newnode->next = newnode;
        newnode->prer = newnode;
        head = newnode;
        return;
    }

    struct Node *last = head->prer;

    newnode->next = head;
    newnode->prer = last;

    last->next = newnode;
    head->prer = newnode;

    head = newnode;
}

void insert_last(int value)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = value;

    if (head == NULL)
    {
        newnode->next = newnode;
        newnode->prer = newnode;
        head = newnode;
        return;
    }

    struct Node *last = head->prer;

    newnode->next = head;
    newnode->prer = last;

    last->next = newnode;
    head->prer = newnode;
}

void delete_first()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
        printf("First node deleted\n");
        return;
    }

    struct Node *last = head->prer;
    struct Node *temp = head;

    head = head->next;

    head->prer = last;
    last->next = head;

    free(temp);
    printf("First node deleted\n");
}

void delete_last()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
        printf("Last node deleted\n");
        return;
    }

    struct Node *last = head->prer;
    struct Node *second_last = last->prer;

    second_last->next = head;
    head->prer = second_last;

    free(last);
    printf("Last node deleted\n");
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    printf("List: ");
    do
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(HEAD)\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete First\n");
        printf("4. Delete Last\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insert_beg(value);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insert_last(value);
            break;

        case 3:
            delete_first();
            break;

        case 4:
            delete_last();
            break;

        case 5:
            display();
            break;

        case 6:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
