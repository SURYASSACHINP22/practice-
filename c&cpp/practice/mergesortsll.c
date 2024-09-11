#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to merge two sorted linked lists
struct ListNode* mergeSortedLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* mergedList = NULL;
    struct ListNode* current = NULL;

    while (list1 != NULL && list2 != NULL) {
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));

        if (list1->val < list2->val) {
            newNode->val = list1->val;
            list1 = list1->next;
        } else {
            newNode->val = list2->val;
            list2 = list2->next;
        }

        newNode->next = NULL;

        if (mergedList == NULL) {
            mergedList = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    // Append remaining nodes
    if (list1 != NULL) {
        if (mergedList == NULL) {
            mergedList = list1;
        } else {
            current->next = list1;
        }
    } else if (list2 != NULL) {
        if (mergedList == NULL) {
            mergedList = list2;
        } else {
            current->next = list2;
        }
    }

    return mergedList;
}

// Function to print a linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// Function to create a new node in the linked list
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// Example usage
int main() {
    // Creating two sorted linked lists
    struct ListNode* list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(5);

    struct ListNode* list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);

    // Merging the two lists
    struct ListNode* mergedList = mergeSortedLists(list1, list2);

    // Printing the merged list
    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
