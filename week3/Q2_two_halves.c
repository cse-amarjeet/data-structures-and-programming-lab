#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *last,*h1,*h2;
void insert(int);
void display_ele(struct node *);
void split_into_halves();
int count=0;

void main()
{
    int ch,ele;
    while(1){
    	printf("\n================================================================================================\n");
        printf("\n1.Insert an element into list\n2.Display the list element\n3.Split list into two halves\n0.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);

        if(ch==1)
        {
            printf("\nEnter an element to insert:");
            scanf("%d",&ele);
            insert(ele);
        }
        else if(ch==2)
        {
        	if(last!=NULL)
        	{
        	    printf("\nThe elements of list are:\n");
                display_ele(last->next);
                printf("\nThe number of elements of list= %d",count);
			}
			else
			{
				printf("List is Empty!!");
			}

          
        }
        else if(ch==3)
        {
        	if(last!=NULL)
        	{
        		split_into_halves();
	            printf("\nThe first half:\n");
	            display_ele(h1);
	            printf("\nThe second half:\n");
	            display_ele(h2);
                return;
			}
			else if(ch==0)
			{
				exit(0);
			}
            else
			{
				printf("List is Empty!!");
			}
        }
        else{
            printf("\nPlease enter a valid choice:");
        }

    }



}

void insert(int ele)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node*));
    temp->data=ele;
    if(last==NULL)
    {
        last=temp;
        temp->next=last;
        printf("\nElement %d is inserted into list",ele);
        count++;
    }
    else{
        temp->next=last->next;
        last->next=temp;
        last=temp;
        printf("\nElement %d is inserted into list",ele);
        count++;
    }

}
void display_ele(struct node *head)
{
  struct node *temp = head;
  if(head != NULL)
  {
    printf("\n");
    do {
      printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != head);
  }
  else{
    printf("\nlist is empty.");
  }
}

void split_into_halves()
{
   struct node *head=last->next;
   struct node *ptr1 = head;
   struct node *ptr2= head;

    if(head == NULL)
        return;


    while(ptr2->next != head &&ptr2->next->next != head)
    {
        ptr2 = ptr2->next->next;
        ptr1 = ptr1->next;
    }


    if(ptr2->next->next == head)
        ptr2 = ptr2->next;

    h1= head;


    if(head->next != head)
        h2 = ptr1->next;

    ptr2->next = ptr1->next;


    ptr1->next = head;

}

