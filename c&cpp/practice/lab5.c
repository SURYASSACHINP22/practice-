#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    int sem, phno;
    char name[20], branch[10], usn[20];
    struct node *next;
};
typedef struct node Node;
Node *first = NULL, *last = NULL;
int count = 0;
Node *createNode() {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->next = NULL;
    return newNode;
}

void insertAtFirst() {
    Node *temp = createNode();
    printf("\nEnter USN, name, branch, sem, phno of student: ");
    scanf("%s %s %s %d %d", temp->usn, temp->name, temp->branch, &temp->sem, &temp->phno);
    if (first == NULL) {
        first = last = temp;
    } else {
        temp->next = first;
        first = temp;
    }
    count++;
}

void insertAtLast() {
    Node *temp = createNode();
    printf("\nEnter USN, name, branch, sem, phno of student: ");
    scanf("%s %s %s %d %d", temp->usn, temp->name, temp->branch, &temp->sem, &temp->phno);
    if (first == NULL) {
        first = last = temp;
    } else {
        last->next = temp;
        last = temp;
    }
    count++;
}

void display() {
    Node *temp = first;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("\nLinked list elements from beginning:\n");
    while (temp != NULL) {
        printf("%s %s %s %d %d\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
        temp = temp->next;
    }
    printf("Number of students = %d\n", count);
}

void deleteEnd() {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = first;
    if (temp->next == NULL) {
        free(temp);
        first = NULL;
    } else {
        while (temp->next != last) {
            temp = temp->next;
        }
        printf("Deleted element: %s %s %s %d %d\n", last->usn, last->name, last->branch, last->sem, last->phno);
        free(last);
        temp->next = NULL;
        last = temp;
    }
    count--;
}

void deleteFront() {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = first;
    first = first->next;
    printf("Deleted element: %s %s %s %d %d\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phno);
    free(temp);
    count--;
}

int main() {
    int ch;
    printf("-----------------MENU----------------------\n");
    printf("\n1. Create a SLL of n emp");
    printf("\n2. Display from beginning");
    printf("\n3. Insert at end");
    printf("\n4. Delete at end");
    printf("\n5. Insert at beg");
    printf("\n6. Delete at beg");
    printf("\n7. Exit\n");
    printf("-------------------------------------------\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                {
                    int n, i;
                    printf("\nEnter number of students: ");
                    scanf("%d", &n);
                    for (i = 0; i < n; i++)
                        insertAtFirst();
                }
                break;
            case 2:
                display();
                break;
            case 3:
                insertAtLast();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                insertAtFirst();
                break;
            case 6:
                deleteFront();
                break;
            case 7:
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}
