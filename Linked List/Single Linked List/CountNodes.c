#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;
void createList(int n);
int countNodes();
void displayList();
int main()
{
    int n, total;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);
    printf("Data in the list is:\n");
    displayList();
    total = countNodes();
    printf("\nTotal number of nodes: %d\n", total);
    return 0;
}
void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;
    head = (struct node *)malloc(sizeof(struct node));
    if(head == NULL)
    {
        printf("Unable to allocate memory!");
        exit(0);
    }
    else
    {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);
        head -> data = data;
        head -> next = NULL;
        temp = head;
        for(i=2;i<=n;i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            if(newNode == NULL)
            {
                printf("\nUnable to allocate memory!");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);
                newNode -> data = data;
                newNode -> next = NULL;
                temp -> next = newNode;
                temp = temp -> next;
            }
        }
        printf("Linked List Created Successfully!\n");
    }
}
int countNodes()
{
    int count = 0;
    struct node *temp;
    temp = head;
    while(temp!=NULL)
    {
        count++;
        temp = temp -> next;
    }
    return count;
}
void displayList()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("\nList is empty!");
    }
    else
    {
        temp = head;
        while(temp!=NULL)
        {
            printf("%d->", temp -> data);
            temp = temp -> next;
        }
    }
}