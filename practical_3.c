#include<stdio.h>
#include<stdlib.h>
#define Max 3
int queue[Max];
int front = -1,rear = -1;
void insert()
{
    int i;
    if((front == 0 && rear == Max - 1) || (rear + 1 == front))
    {
        printf("The queue is full.\n");
        return;
    }
    printf("Enter any number to insert in the queue: ");
    scanf("%d",&i);
    if(front == -1)
    {
        front = rear = 0;
    }
    else if(rear == Max - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = i;
    printf("%d is successfully inserted in the queue.\n",i);
}
void delete()
{
    if(front == -1)
    {
        printf("The queue is empty.\n");
        return;
    }
    int i = queue[front];
    printf("%d is successfully deleted from the queue.\n",i);
    if(front == rear)
    {
        front = rear = -1;
    }
    else if(front == Max - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}
void display()
{
    if(front == -1)
    {
        printf("The queue is empty.\n");
        return;
    }
    printf("The queue elements are: ");
    if(rear >= front)
    {
        for(int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    else 
    { 
        for(int i = front; i < Max; i++)
        {
            printf("%d ",queue[i]);
        }
        for(int i = 0; i <= rear; i++)
        {
            printf("%d ",queue[i]);
        }
    }
    printf("\n");
}
int main()
{
    int choice;
    while (1) 
    {
        printf("\n----- Circular Queue Menu -----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice from the above: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            default:
            printf("Invalid choice.\n");
            printf("Please try again.\n");
        }
    }
    return 0;
}