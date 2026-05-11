#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at Beginning
void insert_first(int data)
{
    struct Node *newnode;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->data = data;
    newnode->next = head;

    head = newnode;
}

// Insert at End
void insert_end(int data)
{
    struct Node *newnode;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }
}

// Insert at Position
void insert_position(int data, int pos)
{
    struct Node *newnode, *temp;
    int i;

    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;

    if (pos == 1)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        temp = head;

        for (i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            printf("Invalid Position\n");
        }
        else
        {
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}

// Display
void display()
{
    struct Node *q = head;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (q != NULL)
        {
            printf("%d ", q->data);
            q = q->next;
        }
    }

    printf("\n");
}

// Delete First Node
void delete_first()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        head = head->next;

        printf("Deleted node is : %d\n", temp->data);

        free(temp);
    }
}

// Delete Last Node
void delete_last()
{
    struct Node *temp, *prev;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else if (head->next == NULL)
    {
        printf("Deleted node is : %d\n", head->data);
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;

        printf("Deleted node is : %d\n", temp->data);

        free(temp);
    }
}

// Delete at Position
void delete_position(int pos)
{
    struct Node *temp, *prev;
    int i;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else if (pos == 1)
    {
        temp = head;
        head = head->next;

        printf("Deleted node is : %d\n", temp->data);

        free(temp);
    }
    else
    {
        temp = head;

        for (i = 1; i < pos; i++)
        {
            prev = temp;
            temp = temp->next;

            if (temp == NULL)
            {
                printf("Invalid Position\n");
                return;
            }
        }

        prev->next = temp->next;

        printf("Deleted node is : %d\n", temp->data);

        free(temp);
    }
}

// Main Function
int main()
{
    insert_end(10);
    insert_end(20);
    insert_end(30);

    printf("Original Linked List:\n");
    display();

    insert_first(5);

    printf("After Insert First:\n");
    display();

    insert_position(15, 3);

    printf("After Insert at Position:\n");
    display();

    delete_first();

    printf("After Delete First:\n");
    display();

    delete_last();

    printf("After Delete Last:\n");
    display();

    delete_position(2);

    printf("After Delete at Position:\n");
    display();

    return 0;
}
