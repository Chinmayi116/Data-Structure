#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert_first(int data)
{
    struct Node *newnode = (struct Node*) malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

// Insert at end
void insert_end(int data)
{
    struct Node *newnode;
    newnode = (struct Node*) malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct Node *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display()
{
    struct Node *q = head;
    while(q != NULL)
    {
        printf("%d -> ", q->data);
        q = q->next;
    }
    printf("NULL\n");
}

// delete first
void delete_first()
{
    struct Node *temp = head;
    if(head == NULL)
        printf("List is empty\n");
    else
    {
        head = head->next;
        printf("deleted node is: %d\n", temp->data);
        free(temp);
    }
}

// delete last
void delete_last()
{
    struct Node *temp = head;
    struct Node *p = NULL;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    while(temp->next != NULL)
    {
        p = temp;
        temp = temp->next;
    }

    p->next = NULL;
    free(temp);
}

// insert at position
void insert_at_pos(int data)
{
    struct Node *newnode = (struct Node*) malloc(sizeof(struct Node));
    int pos, i;
    newnode->data = data;

    printf("Enter the position: ");
    scanf("%d", &pos);

    if(pos == 1)
    {
        newnode->next = head;
        head = newnode;
        return;
    }

    struct Node* temp = head;

    for(i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Position not valid\n");
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

// delete at position
void delete_at_pos()
{
    struct Node *temp = head;
    struct Node *prev = NULL;
    int pos, i;

    printf("Enter the position: ");
    scanf("%d", &pos);

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(pos == 1)
    {
        head = temp->next;
        free(temp);
        return;
    }

    for(i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Position not valid\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}
