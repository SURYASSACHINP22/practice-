#include<stdio.h>
#include<stdlib.h>

#define max 50

int Q[max];
int F = -1, R = -1;
int count = 0;

void insert(int ele) {
    if (F == -1 && R == -1) {
        printf("Queue was empty, not empty now.\n");
        F = 0;
        R = 0;
        Q[R] = ele;
        count++;
    } else if ((F == 0 && R == max - 1) || (F != 0 && R == F - 1)) {
        printf("Queue is full.\n");
    } else {
        R = (R + 1) % max;
        Q[R] = ele;
        count++;
    }
}

void delete() {
    if (F == -1 && R == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("The deleted element is %d.\n", Q[F]);
        if (F == R) {
            F = -1;
            R = -1;
        } else {
            F = (F + 1) % max;
        }
        count--;
    }
}

void display() {
    if (F == -1 && R == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", Q[(F + i) % max]);
        }
        printf("\n");
    }
}

int main() {
    int ch;
    printf("Performing operations for circular queue:\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the data for circular queue: ");
                int ele;
                scanf("%d", &ele);
                insert(ele);
                break;
            case 2:
                printf("Deleting data from circular queue.\n");
                delete();
                break;
            case 3:
                printf("Displaying data from circular queue.\n");
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}
