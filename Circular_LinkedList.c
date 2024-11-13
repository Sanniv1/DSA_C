#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void CircularLinkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    if (head == NULL)
    {
        printf("Circular Linked List is empty.\n");
        return;
    }
    do
    {
        printf("Element %d \n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

struct Node *insertAtPosition(struct Node *head, int data, int position)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    for (int i = 1; i < position - 1; i++)
    {
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node *deleteAtFirst(struct Node *head)
{
    if (head == NULL)
    {
        printf("Circular Linked List is empty. Cannot delete.\n");
        return head;
    }
    struct Node *temp = head;
    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = head->next;
    head = head->next;
    free(temp);
    return head;
}

struct Node *deleteAtPosition(struct Node *head, int position)
{
    if (head == NULL)
    {
        printf("Circular Linked List is empty. Cannot delete.\n");
        return head;
    }
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 1; i < position - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct Node *deleteAtLast(struct Node *head)
{
    if (head == NULL)
    {
        printf("Circular Linked List is empty. Cannot delete.\n");
        return head;
    }
    struct Node *temp = head;
    struct Node *prev = NULL;
    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == head)
    {
        free(temp);
        head = NULL;
    }
    else
    {
        prev->next = head;
        free(temp);
    }
    return head;
}

int main()
{
    struct Node *head = NULL;
    int choice, value, position;

    do
    {
        printf("\nCircular Linked List Menu:\n");
        printf("1. Insert at First\n");
        printf("2. Insert at Any Position\n");
        printf("3. Delete First\n");
        printf("4. Delete at Any Position\n");
        printf("5. Delete Last\n");
        printf("6. Display Circular Linked List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert at first: ");
            scanf("%d", &value);
            head = insertAtFirst(head, value);
            break;
        case 2:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            printf("Enter the position to insert at: ");
            scanf("%d", &position);
            head = insertAtPosition(head, value, position);
            break;
        case 3:
            head = deleteAtFirst(head);
            printf("First element deleted.\n");
            break;
        case 4:
            printf("Enter the position to delete: ");
            scanf("%d", &position);
            head = deleteAtPosition(head, position);
            printf("Element at position %d deleted.\n", position);
            break;
        case 5:
            head = deleteAtLast(head);
            printf("Last element deleted.\n");
            break;
        case 6:
            printf("Circular Linked List:\n");
            CircularLinkedListTraversal(head);
            break;
        case 7:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 7);

    return 0;
}
