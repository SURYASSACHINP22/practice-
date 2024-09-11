#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *head=NULL,*temp,*newnode=NULL;
int i,count=0,nodeno;

struct node *create()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter the data to insert\n\n");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	return newnode;
}

void display()
{
	if(head==NULL)
	{
		printf("linked list is empty\n");
	}
	else
	{
		printf("the linked list daTA IS\n");
		temp=head;
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);	
			temp=temp->next;
		}		        	
		
	}
}

void getnode()
{
	printf("enter which node you want you have only %d nodes only\n",count);
	scanf("%d",&nodeno);
	temp=head;
	i=1;
	while(temp!=NULL && i<nodeno)
	{
		temp=temp->next;
		i++;
	}		        	
	printf("%d\n",temp->data);				
}

int main()
{	
	printf("writing the liked list\n");
	int i=1,ch;
	while(i)
	{
		printf("enter the choice please!!!\n");
		printf("\n1.create() is same for insert() also\n2.display\n3.search()\n4.exit\n\n");
		scanf("%d",&ch);
		
		switch (ch)
		{
			case 1:
					printf("trying to createn\n\n");
					newnode=create();
					if(head==NULL)
					{
						head=temp=newnode;
					}
			        else
			        {
			        	temp->next=newnode;
			        	temp=newnode;
			        }
                    count++;
                    printf("created another one node also\n");
			        break;
			        
			case 2:
					printf("calling display function\n");
					display();
					break;
			case 3:
					printf("calling getnode function\n");
					getnode();
					break;
			default:
			       exit(0);			      
		}	
	}
	
}