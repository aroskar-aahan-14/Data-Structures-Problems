#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* createNode(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) 
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(struct Node** head, int value) 
{
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at the beginning.\n", value);
}
void insertAtEnd(struct Node** head, int value) 
{
    struct Node* newNode = createNode(value);
    if(*head == NULL) 
    {
        *head = newNode;
        printf("Inserted %d at the end.\n", value);
        return;
    }
    struct Node* temp = *head;
    while(temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Inserted %d at the end.\n", value);
}
void insertAtPosition(struct Node** head, int value, int position) 
{
    if(position < 1) 
    {
        printf("Invalid position.\n");
        printf("Please Try Again.\n");
        return;
    }
    if(position == 1) 
    {
        insertAtBeginning(head, value);
        return;
    }
    struct Node* temp = *head;
    for(int i = 1; temp != NULL && i < position - 1; i++) 
    {
        temp = temp->next;
    }
    if(temp == NULL) 
    {
        printf("Invalid position.\n");
        printf("Please Try Again.\n");
        return;
    }
    struct Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", value, position);
}
void deleteFromBeginning(struct Node** head) 
{
    if(*head == NULL) 
    {
        printf("The list is empty.\n");
        printf("There is nothing to delete.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    printf("Deleted element %d from the beginning.\n", temp->data);
    free(temp);
}
void deleteFromEnd(struct Node** head) 
{
    if(*head == NULL) 
    {
        printf("The list is empty.\n");
        printf("There is nothing to delete.\n");
        return;
    }
    struct Node* temp = *head;
    if(temp->next == NULL) 
    {
        printf("Deleted element %d from the end.\n", temp->data);
        free(temp);
        *head = NULL;
        return;
    }
    while(temp->next->next != NULL) 
    {
        temp = temp->next;
    }
    printf("Deleted element %d from the end.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}
void deleteFromPosition(struct Node** head, int position) 
{
    if(*head == NULL) 
    {
        printf("The list is empty.\n");
        printf("There is nothing to delete.\n");
        return;
    }
    if(position < 1) 
    {
        printf("Invalid position.\n");
        printf("Please Try Again.\n");
        return;
    }
    if(position == 1) 
    {
        deleteFromBeginning(head);
        return;
    }
    struct Node* temp = *head;
    for(int i = 1; temp != NULL && i < position - 1; i++) 
    {
        temp = temp->next;
    }
    if(temp == NULL || temp->next == NULL) 
    {
        printf("Invalid position.\n");
        printf("Please Try Again.\n");
        return;
    }
    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    printf("Deleted element %d from position %d.\n", delNode->data, position);
    free(delNode);
}
void display(struct Node* head) 
{
    if(head == NULL) 
    {
        printf("The list is empty.\n");
        return;
    }
    printf("The List is: ");
    struct Node* temp = head;
    while(temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() 
{
    struct Node* head = NULL;
    int choice, value, position;
    while(1) 
    {
        printf("\n----- Menu Driven Singly Linked List -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at a Specific Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from a Specific Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice from the above: ");
        scanf("%d", &choice);
        switch(choice) 
        {
            case 1:
            printf("Enter a value to insert at beginning: ");
            scanf("%d", &value);
            insertAtBeginning(&head, value);
            break;
            case 2:
            printf("Enter value to insert at end: ");
            scanf("%d", &value);
            insertAtEnd(&head, value);
            break;
            case 3:
            printf("Enter value and position: ");
            scanf("%d %d", &value, &position);
            insertAtPosition(&head, value, position);
            break;
            case 4:
            deleteFromBeginning(&head);
            break;
            case 5:
            deleteFromEnd(&head);
            break;
            case 6:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            deleteFromPosition(&head, position);
            break;
            case 7:
            display(head);
            break;
            case 8:
            while(head != NULL)           
            {
                deleteFromBeginning(&head);
            }
            exit(0);
            default:
            printf("Invalid choice.\n");
            printf("Please try again.\n");
        }
    }
    return 0;
}