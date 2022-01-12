#include<stdlib.h>
#include <stdio.h>
#include <string.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
int main()     
   {
        int choice;
        while(1)
		{
               
            printf("\n---------------------------------------------------------");
			printf("\n 1.Push element \n 2.Pop element from Top\n 3.Display all element in stack\n 4.Exit\n");
			printf("\nEnter operation choice : ");
			scanf("%d",&choice);
                
                if(choice==1)  //Create Node and Push
                {
                    struct node *temp_n;
			        temp_n=(struct node *)malloc(sizeof(struct node));
			        if(temp_n==NULL)
			        {
			                printf("Some Error Happen!!");
			                exit(0);
			        }
			        printf("Enter the value for the node: ");
			        scanf("%d",&temp_n->data);
			        temp_n->next=NULL;
			        if(start==NULL)
			        {
			                start=temp_n;
			        }
			        else
			        {
			            temp_n->next=start;
			            start=temp_n;
			        }
			    }
			    if(choice==2) //Pop the element
			    {
			    	struct node *temp_ptr;
			        if(start==NULL)
			        {
			            printf("List is Empty!!");
			            
			        }
			        else
			        {
			            temp_ptr=start;
			            start=start->next ;
			            printf("The deleted element is :%d",temp_ptr->data);
			            free(temp_ptr);
			        }
				}
				if(choice==3) //Display all the element
				{
					struct node *temp_ptr;
			        if(start==NULL)
			        {
			            printf("No element in The Stack");
			        }
			        else
			        {
			            temp_ptr=start;
			            printf("The List elements are:");
			            while(temp_ptr!=NULL)
			            {
			                printf("%d  ",temp_ptr->data );
			                temp_ptr=temp_ptr->next ;
			            }
			        }
				}
				if(choice==4) //Exit
				{
					exit(0);
				}
		}
		return 0;
	}
