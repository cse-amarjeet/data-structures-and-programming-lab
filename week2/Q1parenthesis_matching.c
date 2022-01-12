#include<stdlib.h>
#include <stdio.h>
#include <string.h>
struct node
{
    char data;
    struct node *next;
};
struct node *start=NULL;
int pop();
void push(char val);
int isEmpty(struct node *ptr);

int main()
{
	char exp[50], Parenthe, op;
	int i;
	printf("Enter Expression with Parenthesis(only: {}, [], () ):   ");
	gets(exp);
	printf("Your Entered Expression is: %s",exp);
	int n=strlen(exp), matched=1;
	for(i=0; i<=n;i++)
	{
		op=exp[i];
		if(op=='(' || op=='{' || op=='[')
		{
			push(op);
		}
		if(op==')' || op=='}' || op==']')
		{
			Parenthe=pop();
			
			if(op==')')
			{
				if(Parenthe!='(')
				{
					matched=0;
					break;
				}
			}
			if(op=='}')
			{
				if(Parenthe!='{')
				{
					matched=0;
					break;
				}
			}
			if(op==']')
			{
				if(Parenthe!='[')
				{
					matched=0;
					break;
				}
			}
			
		}
	}
	if(matched==1 && isEmpty(start)==1)
	{
		printf("\n\nTrue");
	}
	else
	{
		printf("\n\nFalse");
	}
	
	
}

void push(char val)
{
    struct node *n = (struct node *) malloc(sizeof(struct node));
    if(n==NULL){
        printf("stack is Full (Overflow)");
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
		    n->next=start;
			start=n;
		}
    }
}
int pop()
{
	char pop_ele;
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
		//printf("\nThe deleted element is :%c",temp_ptr->data);
		free(temp_ptr);
	}
	return pop_ele;
}
int isEmpty(struct node *ptr)
{
	int a=pop();
	if(a==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
 
