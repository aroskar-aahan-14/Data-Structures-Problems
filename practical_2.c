#include<stdio.h>
#define Max 10
int stack[Max];
int top=-1;
void push(int x)
{
    if(top == Max - 1)
    {
        printf("The stack is full\n");
    }
    else
    {
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("The stack is empty\n");
    }
    else
    {
        int data = stack[top];
        top = top - 1;
        printf("%d was popped.\n", data);
    }
}
void display()
{
    if(top==-1)
    {
        printf("The stack is empty\n");
    }
    else
    {
        for(int i=top;i>=0;i--)
        {
            printf("|%d|\n",stack[i]);
        }
    }
}
void peek()
{
    if(top == -1)
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("%d\n",stack[top]);
    }
}
int main()
{
    push(90);
    push(80);
    push(70);
    display();
    pop();
    display();
    return 0;
}