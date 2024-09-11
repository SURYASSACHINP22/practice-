#include<stdio.h>
#include<stdlib.h>

struct BST_tree
{
    int data;
    struct BST_tree *llink;
    struct BST_tree *rlink;    
};

typedef struct BST_tree *NODE;

NODE getnode()
{
    NODE temp = (NODE)malloc(sizeof(struct BST_tree));
    temp->llink = temp->rlink = NULL;
    return temp;
}

NODE insert(NODE root, int ele)
{
    if(root == NULL)
    {  
        NODE new_node = getnode();
        new_node->data = ele;
        return new_node;
    }
    else
    {
        if(root->data > ele)
        {
            root->llink = insert(root->llink, ele);
        }
        else
        {
            root->rlink = insert(root->rlink, ele);
        }
        return root;
    }
}

int search(NODE root, int key)
{
    if(root == NULL)
        return -1;
    
    if(root->data == key)
        return 1;
    else if(root->data > key)
        return search(root->llink, key);
    else
        return search(root->rlink, key);
}

void display_inorder(NODE root)
{
    if(root != NULL)
    {
        display_inorder(root->llink);
        printf("%d ", root->data);
        display_inorder(root->rlink);
    }
}

void display_postorder(NODE root)
{
    if(root != NULL)
    {
        display_postorder(root->llink);
        display_postorder(root->rlink);
        printf("%d ", root->data);
    }
}

void display_preorder(NODE root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        display_preorder(root->llink);
        display_preorder(root->rlink);
    }
}

int main()
{
    NODE root = NULL;
    int ch, ele, key;
    printf("BST tree operations\n");
    while(1)
    {
        printf("Enter your choice\n");
        printf("1. Insert\n2. Search\n3. Display\n4. Exit\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter the tree element\n");
                scanf("%d", &ele);
                root = insert(root, ele);
                break;
            case 2:
                printf("Enter the key\n");
                scanf("%d", &key);
                if(search(root, key) == 1)
                {
                    printf("Key is found inside\n");   
                }
                else
                {
                    printf("Not found\n");
                }
                break;   
            case 3:
                printf("Inorder traversal: ");
                display_inorder(root);
                printf("\nPreorder traversal: ");
                display_preorder(root);
                printf("\nPostorder traversal: ");
                display_postorder(root);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
