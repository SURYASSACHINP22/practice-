#include <stdio.h>
#include <stdlib.h>
#define size 10

void insert_rear();
void delete_rear();
void insert_front();
void delete_front();
void show();

int dqar[size];
int rear = -1;
int front = -1;

int main() {
    int ch;
    while (1) {
        printf("\n1. Insert rear");
        printf("\n2. Delete rear");
        printf("\n3. Insert front");
        printf("\n4. Delete front");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insert_rear();
                break;
            case 2:
                delete_rear();
                break;
            case 3:
                insert_front();
                break;
            case 4:
                delete_front();
                break;
            case 5:
                show();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Incorrect choice\n");
        }
    }
    return 0;
}

void insert_rear() {
    int tempir;
    if (rear == size - 1)
        printf("\nOverflow\n");
    else {
        if (front == -1)
            front = 0;
        printf("Enter the element to be inserted: ");
        scanf("%d", &tempir);
        rear++;
        dqar[rear] = tempir;
    }
}

void insert_front() {
    int tempif;
    if (front == -1)
        front = 0;
    printf("Enter the element to be inserted: ");
    scanf("%d", &tempif);
    if (front != 0) {
        front--;
        dqar[front] = tempif;
    } else {
        printf("\nCannot insert from front\n");
    }
}

void delete_front() {
    if (front == -1 || front > rear)
        printf("\nUnderflow\n");
    else {
        printf("Deleted element: %d\n", dqar[front]);
        front++;
    }
}

void delete_rear() {
    if (rear == -1 || front > rear)
        printf("\nUnderflow\n");
    else {
        printf("Deleted element: %d\n", dqar[rear]);
        rear--;
    }
}

void show() {
    int i;
    if (front == -1) {
        printf("\nThe queue is empty\n");
    } else {
        printf("\nQueue: ");
        for (i = front; i <= rear; i++)
            printf("%d ", dqar[i]);
        printf("\n");
    }
}
