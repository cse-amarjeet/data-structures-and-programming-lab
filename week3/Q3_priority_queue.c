//priority Queue in Week 3 (Question 3)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	char name[100];
	int score;
	struct node *next;
}node;


void insert();
void delete_entry();
void display();
node *head=NULL;

void main(){
	int x;
	while(1){
			printf("\n==================== Priority queue ===============================\n");
			printf("1.insert    ||  2.delete   || 3.display   ||  0.exit \n\n");
			printf("Enter ur choice: ");
			scanf("%d",&x);
			
			if(x==1)
			{
				insert();
			} 
			else if(x==2)
			{
				delete_entry();
			}  
			else if(x==3) 
			{
				display();
			}
			else if(x==0)
			{
				exit(1);
			}
			else 
			{ 
				printf("\nEnter a valid choice "); 
			}
	}
}

void insert()
{
	int d,p;
	node *start = head;
	node *ptr;
	ptr=(node *)malloc(sizeof(node));
	printf("\nEnter name of new student:  ");
	scanf("%s",&ptr->name);
	printf("\nEnter score of new node:  ");
	scanf("%d",&ptr->score);
	p=ptr->score;
	printf("\nName: %s  and  score: %d",ptr->name,ptr->score);
	ptr->next=NULL;

	if(head==NULL){
		head=ptr;
	}
	else{
	    if ((head->score) < p) {

	        ptr->next = head;
	        head = ptr;
	    }
	    else {
	        while ((start->next != NULL)&&(start->next->score > p)) {
	            start = start->next;
	        }
	        ptr->next = start->next;
	        start->next = ptr;
	        //head=start;
	    }
	}
}


void delete_entry(){
	node *ptr;
	if(head==NULL) printf("\nQueue is Empty!!");
	else{
		ptr=head;
		printf("\ndeleted student name: %s  and score: ",ptr->name,ptr->score);
		head=ptr->next;
		free(ptr);
	}
}

void display(){
	node *ptr;
	if(head==NULL) printf("\nQueue is Empty!!");
	else{
		ptr=head;
		printf("\nName\t\tScore\n");
		printf("----------------------\n");
		while(ptr!=NULL)
		{
			printf("%s\t\t%d",ptr->name,ptr->score);
			ptr=ptr->next;
			printf("\n");
		}
	printf("\n");
	}
}

