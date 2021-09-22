#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int length(struct node *head)
{
    int l = 0;
    struct node *ptr = head;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        l++;
    }
    return l;
}

void listElements(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

struct node *insertAtBeginning(struct node *head, int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = head;
    return new;
}

struct node *insertAtEnd(struct node *head, int data)
{
    struct node *ptr = head;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    new->data = data;
    new->next = NULL;
    ptr->next = new;
    return ptr;
}

struct node *insertAtIndex(struct node *head, int data, int index)
{
    struct node *p = head;
    int i = 1;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    struct node *q = (struct node *)malloc(sizeof(struct node));
    q->data = data;
    q->next = p->next;
    p->next = q;
    return p;
}

struct node *deletionAtBeginning(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node *deletionAtEnd(struct node *head)
{
    struct node *p = head;
    struct node *q = p->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct node *deletionAtIndex(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = p->next;
    int i = 1;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 26;
    head->next = NULL;
    int choice, data, index, nindex;
    printf("1.Length of the linked list\n2.List the elements of the linked list\n3.Insertion at the beginning of the list\n4.Insertion at the end of the list\n5.Insertion at a particular position\n6.Deletion at the beginning of the list\n7.Deletion at the end of the list\n8.Deletion after a particular index\n9.Exit\n");
    while (1)
    {
        printf("\nEnter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("The length of the linked list is: %d\n", length(head));
            break;
        case 2:
            printf("Elements of you linked list are:\n");
            listElements(head);
            break;
        case 3:
            // int data;
            printf("Enter the element to be inserted:\n");
            scanf("%d", &data);
            head = insertAtBeginning(head, data);
            break;
        case 4:
            // int data;
            printf("Enter the element to be inserted:\n");
            scanf("%d", &data);
            head = insertAtEnd(head, data);
            break;
        case 5:
            // int data, index;
            printf("Enter the element to be inserted:\n");
            scanf("%d", &data);
            printf("Enter the position at which you want to enter:\n");
            scanf("%d", &index);
            head = insertAtIndex(head, data, index);
            break;
        case 6:
            head = deletionAtBeginning(head);
            printf("The element at the beginning is deleted\n");
            break;
        case 7:
            head = deletionAtEnd(head);
            printf("The element at the end is deleted\n");
            break;
        case 8:
            printf("Enter the position of deletion:\n");
            scanf("%d", &nindex);
            head = deletionAtIndex(head, nindex);
            printf("The element at the beginning is deleted\n");
            break;
        case 9:
            printf("Exit!!\n");
            return 0;
        }
    }
    return 0;
}