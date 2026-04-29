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
    newnode->prer = NULL;
    newnode->next = head;

    if (head != NULL)
    {
        head->prer = newnode;
    }

    head = newnode;
}

void insert_last(int value)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL)
    {
        newnode->prer = NULL;
        head = newnode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prer = temp;
}

void delete_first()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    if (head != NULL)
    {
        head->prer = NULL;
    }

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

    struct Node *temp = head;

    if (temp->next == NULL)
    {
        free(temp);
        head = NULL;
        printf("Last node deleted\n");
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->prer->next = NULL;
    free(temp);
    printf("Last node deleted\n");
}

void display()
{
    struct Node *temp = head;

    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("List: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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
