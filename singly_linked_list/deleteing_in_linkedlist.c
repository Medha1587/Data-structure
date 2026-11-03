#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Create linked list
void create()
{
    struct node *newnode, *temp;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
        }
    }
}

// Delete first node
void deleteFirst()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);

    printf("First node deleted\n");
}

// Delete specified element
void deleteElement()
{
    struct node *temp, *prev;
    int key;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter element to delete: ");
    scanf("%d", &key);

    temp = head;
    prev = NULL;

    while(temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Element not found\n");
        return;
    }

    if(prev == NULL)
        head = head->next;
    else
        prev->next = temp->next;

    free(temp);

    printf("Element deleted\n");
}

// Delete last node
void deleteLast()
{
    struct node *temp, *prev;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    if(head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        while(temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        free(temp);
    }

    printf("Last node deleted\n");
}

// Display linked list
void display()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice;

    create();

    while(1)
    {
        printf("\n1. Delete First");
        printf("\n2. Delete Specified Element");
        printf("\n3. Delete Last");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: deleteFirst();
                    break;

            case 2: deleteElement();
                    break;

            case 3: deleteLast();
                    break;

            case 4: display();
                    break;

            case 5: exit(0);

            default: printf("Invalid choice\n");
        }
    }

    return 0;
}
