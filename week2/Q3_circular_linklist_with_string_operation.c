#include<stdlib.h>
#include <stdio.h>
#include <string.h>
struct node
{
    char str1[15],str2[15],str3[15];
    struct node *next;
};
struct node *start=NULL;
void create_node();
void display();

int main()
{
	int choice,count,i=0;
	while(1)
	{
		printf("\n---------------------------------------------------------");
		printf("\n 1.Create Node:  \n 2.Enter String in Info \n 3.Display all Info string\n4.Exit\n");
		printf("\nEnter operation choice : ");
		scanf("%d",&choice);
		
		if(choice==1)
		{
			printf("Enter Number Of Node You Want to Create:");
			scanf("%d",&count);
			for(i=0;i<=count;i++)
			{
				create_node();
			}
		}
		if(choice==2)
		{
			char temp_char[15];
			struct node *temp=start;
			if(count==0)
			{
				printf("please create Node First!!");
			}
			else
			{
				for(i=0;i<count;i++)
				{
					printf("\nNow You Are entering information of %d Node",i);
					printf("\nEnter 1st Info String:");
					scanf("%s",temp->str1);
					
					
					printf("Enter 2st Info String:");
					scanf("%s",temp->str2);
					//temp->str2=temp_char;
					
					printf("Enter 3st Info String:");
					scanf("%s",temp->str3);
					//temp->str3=temp_char;
				}
			}
	    }
	    if(choice==3)
	    {
	    	display();
		}
		if(choice==4)
		{
			exit(0);
		}
    }
	
}

void create_node()
{
	struct node *temp_ptr;
    struct node *n = (struct node *) malloc(sizeof(struct node));
    if(n==NULL){
        printf("Memory Full");
    }
    else{
       if(start==NULL)
		{
			start=n;
			n->next = start;
		}
		else
		{
			n->next = start;
			temp_ptr=start;
			while (temp_ptr->next != start)
    		{
        		temp_ptr = temp_ptr->next;
    		}
    		temp_ptr->next=n;  
		}
    }
}
void display()
{
	struct node *temp=start;
	if(start==NULL)
	{
		printf("list is Empty:");
	}
	else
	{
		int j=1;
		do
		{
			printf("\n\ninformation of %d Node",j);
			printf("\n1st Info String:  %s",temp->str1);
			printf("\n1st Info String:  %s",temp->str2);
			printf("\n1st Info String:  %s",temp->str3);
			temp=temp->next;
			j=j+1;
			
		}while(temp->next != start);
	}
	
}


