#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void push(struct Node **top, int value);
int pop(struct Node **top);
void display(struct Node *top);
int main()
{
    struct Node *top = NULL;
    int choice, value;
    do
    {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&top, value);
                break;
            case 2:
                value = pop(&top);

                if (value != -1)
                    printf("Popped value: %d\n", value);
                break;
            case 3:
                display(top);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
void push(struct Node **top, int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Stack overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    printf("Value pushed: %d\n", value);
}
int pop(struct Node **top)
{
    struct Node *temp;
    int poppedValue;
    if (*top == NULL)
    {
        printf("Stack underflow\n");
        return -1;
    }
    temp = *top;
    poppedValue = temp->data;
    *top = temp->next;
    free(temp);
    return poppedValue;
}
void display(struct Node *top)
{
    struct Node *temp;

    if (top == NULL)
    {
        printf("The stack is empty.\n");
        return;
    }
    printf("Stack elements:\n");
    temp = top;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
