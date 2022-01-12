#include<stdlib.h>
#include <stdio.h>
#include <string.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
int delete_from_begin();
void insert(int val);

int main()
{
	//insert(5);
	int choice;
	int decimal=0;
	while(1)
	{
		printf("\n---------------------------------------------------------");
		printf("\n 1.Insert Binary digit \n 2.Show Decimal \n 3.Exit\n");
		printf("\nEnter operation choice : ");
		scanf("%d",&choice);
		
		if(choice==1)
		{
			int num;
			printf("Enter Binary digit (Enter only 0 or 1) :: ");
			scanf("%d",&num);
			if(num==0 || num==1)
			{
				insert(num);
			}
			else
			{
				printf("Please Enter only 0 or 1");
			}
		}
		if(choice==2)
		{
			int temp;
			while(1)
			{
				temp=delete_from_begin();
				if(temp==-1)
				{
					break;
				}
				if(decimal==0)
				{
					decimal=temp;
				}
				else
				{
					decimal=decimal*2 + temp;
				}
			}
			printf("Decimal Value is :: %d",decimal);
		}
		if(choice==3)
		{
			exit(0);
		}
		if(choice>3)
		{
			printf("please Enter Valid choice");
		}
	}
	
}

void insert(int val)
{
	struct node *temp_ptr;
    struct node *n = (struct node *) malloc(sizeof(struct node));
    if(n==NULL){
        printf("Memory Full");
    }
    else{
        n->data = val;
        n->next = NULL;
       if(start==NULL)
		{
			start=n;
		}
		else
		{
			temp_ptr=start;
			while (temp_ptr->next != NULL)
    		{
        		temp_ptr = temp_ptr->next;
    		}
    		temp_ptr->next=n;  
		    //n->next=start;
			//start=n;
		}
    }
}
int delete_from_begin()
{
	int pop_ele;
	struct node *temp_ptr;
	if(start==NULL)
	{   
		//printf("Stack is Empty!!");
		return -1;
			            
	}
	else
	{
		temp_ptr=start;
		start=start->next ;
		pop_ele=temp_ptr->data;
		//printf("\nThe deleted element is :%d",temp_ptr->data);
		free(temp_ptr);
	}
	return pop_ele;
}


