#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;

node *head = NULL;

void insert_end() {
    int data;
    node *temp, *pre;

    printf("\nEnter value: ");
    scanf("%d", &data);

    temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } 
    else {
        pre = head;

        while (pre->next != NULL) {
            pre = pre->next;
        }

        pre->next = temp;
    }
}

void insert_first() {
    int data;
    node *temp;

    printf("\nEnter the value to insert: ");
    scanf("%d", &data);

    temp = (node *)malloc(sizeof(node));
    temp->data = data;

    temp->next = head;
    head = temp;
}

void insert_pos() {
    int data, pos, count = 1;
    node *temp, *pre;

    printf("\nEnter the value to insert: ");
    scanf("%d", &data);

    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos <= 0) {
        printf("\nInvalid position\n");
        return;
    }

    if (pos == 1) {
        insert_first();
        return;
    }

    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }

    temp = head;

    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("\nInvalid position\n");
        return;
    }

    pre = (node *)malloc(sizeof(node));
    pre->data = data;

    pre->next = temp->next;
    temp->next = pre;
}

void display() {
    node *temp;
    int count = 1;

    temp = head;

    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("List[%d]: %d\n", count, temp->data);
        temp = temp->next;
        count++;
    }
}

void search() {
    node *temp;
    int flag = 0;
    int count = 1;
    int data;

    printf("\nEnter element to search: ");
    scanf("%d", &data);

    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }

    temp = head;

    while (temp != NULL) {
        if (data == temp->data) {
            flag = 1;
            break;
        }

        temp = temp->next;
        count++;
    }

    if (flag == 1) {
        printf("\nElement found at position %d\n", count);
    }
    else {
        printf("\nElement not found\n");
    }
}

void delete_first() {
    node *temp;

    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    free(temp);

    printf("\nFirst node deleted\n");
}

int main() {
    int opt;

    do {
        printf("\n1) Insert in first");
        printf("\n2) Insert in end");
        printf("\n3) Insert at position");
        printf("\n4) Display");
        printf("\n5) Search");
        printf("\n6) Delete first");
        printf("\n0) Quit");

        printf("\nChoose option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                insert_first();
                break;

            case 2:
                insert_end();
                break;

            case 3:
                insert_pos();
                break;

            case 4:
                display();
                break;

            case 5:
                search();
                break;

            case 6:
                delete_first();
                break;

            case 0:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid option, please try again.\n");
        }

    } while (opt != 0);

    return 0;
}
