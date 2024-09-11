#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    struct node *prev;
    int ssn, phno;
    float sal;
    char name[20], dept[10], desg[20];
    struct node *next;
};

typedef struct node Node;

int count = 0;
Node *h = NULL, *temp = NULL, *temp1 = NULL, *temp2 = NULL;

void create() {
    int ssn, phno;
    float sal;
    char name[20], dept[10], desg[20];
    temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->prev = NULL;
    temp->next = NULL;
    printf("\nEnter SSN, name, department, designation, salary, and phone number of employee: ");
    scanf("%d %s %s %s %f %d", &ssn, name, dept, desg, &sal, &phno);
    temp->ssn = ssn;
    strcpy(temp->name, name);
    strcpy(temp->dept, dept);
    strcpy(temp->desg, desg);
    temp->sal = sal;
    temp->phno = phno;
    count++;
}

void insertBeg() {
    create();
    if (h == NULL) {
        h = temp;
        temp1 = h;
    } else {
        temp->next = h;
        h->prev = temp;
        h = temp;
    }
}

void insertEnd() {
    create();
    if (h == NULL) {
        h = temp;
        temp1 = h;
    } else {
        temp1->next = temp;
        temp->prev = temp1;
        temp1 = temp;
    }
}

void displayBeg() {
    temp2 = h;
    if (temp2 == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("\nLinked list elements from beginning:\n");
    while (temp2 != NULL) {
        printf("%d %s %s %s %.2f %d\n", temp2->ssn, temp2->name, temp2->dept, temp2->desg, temp2->sal, temp2->phno);
        temp2 = temp2->next;
    }
    printf("Number of employees = %d\n", count);
}

int deleteEnd() {
    if (h == NULL) {
        printf("List is empty\n");
        return 0;
    }
    struct node *temp;
    temp = h;
    if (temp->next == NULL) {
        free(temp);
        h = NULL;
    } else {
        while (temp1->next != NULL) {
            temp1 = temp1->next;
        }
        temp2 = temp1->prev;
        temp2->next = NULL;
        printf("%d %s %s %s %.2f %d\n", temp1->ssn, temp1->name, temp1->dept, temp1->desg, temp1->sal, temp1->phno);
        free(temp1);
    }
    count--;
    return 0;
}

int deleteBeg() {
    if (h == NULL) {
        printf("List is empty\n");
        return 0;
    }
    struct node *temp;
    temp = h;
    if (temp->next == NULL) {
        free(temp);
        h = NULL;
    } else {
        h = h->next;
        printf("%d %s %s %s %.2f %d", temp->ssn, temp->name, temp->dept, temp->desg, temp->sal, temp->phno);
        free(temp);
    }
    count--;
    return 0;
}

int main() {
    int ch, n, i;
    printf("-----------------MENU--------------------\n");
    printf("\n1 - Create a DLL of n employees");
    printf("\n2 - Display from beginning");
    printf("\n3 - Insert at end");
    printf("\n4 - Delete at end");
    printf("\n5 - Insert at beginning");
    printf("\n6 - Delete at beginning");
    printf("\n7 - Exit\n");
    printf("------------------------------------------\n");
    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter number of employees: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++)
                    insertEnd();
                break;
            case 2:
                displayBeg();
                break;
            case 3:
                insertEnd();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                insertBeg();
                break;
            case 6:
                deleteBeg();
                break;
            case 7:
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}
