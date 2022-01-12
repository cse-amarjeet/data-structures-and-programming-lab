#include <stdio.h>
#include <stdlib.h> 
struct Node
{
    int data;
    struct Node *next;
};
struct Node *f = NULL;
struct Node *r = NULL;

void linkedListTraversal(struct Node *ptr);
void enqueue(int val);
int dequeue();
int main()
{
	int choice;
	while(1)
    {
    	printf("\n---------------------------------------------------------");
		printf("\n 1.Enqueue element \n 2.Dequeuing element \n 3.Display Queue elements \n 4.Exit\n");
		printf("\nEnter operation choice : ");
		scanf("%d",&choice);
		
		if(choice==1)
		{
			int num;
			printf("Enter Value for inserting in Queue: ");
			scanf("%d",&num);
			enqueue(num);
		}
		if(choice==2)
		{
			printf("Dequeuing element: %d\n", dequeue());
		}
		if(choice==3)
		{
			linkedListTraversal(f);
		}
		if(choice==4)
		{
			exit(0);
		}
		if(choice>3)
		{
			printf("please Enter Valid choice");
		}
	}
    
	
    return 0;
}

void linkedListTraversal(struct Node *ptr)
{
    printf("Printing the elements of this linked list:\n");
    if(ptr==NULL)
    {
    	printf("Queue is empty!!");
	}
	else
	{
		while (ptr != NULL)
    	{
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    	}
	}
    
}
 
void enqueue(int val)
{
    struct Node *n = (struct Node *) malloc(sizeof(struct Node));
    if(n==NULL){
        printf("Queue is Full");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next = n;
            r=n;
        }
    }
}
 
int dequeue()
{
    int val = -1;
    struct Node *ptr = f;
    if(f==NULL){
        printf("Queue is Empty\n");
    }
    else{
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

