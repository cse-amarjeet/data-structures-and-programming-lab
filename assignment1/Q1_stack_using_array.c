
//stack implementation using array
#include<stdio.h>
int stack[10],choice,n,top,x,i; // Declaration of variables

int main()
{
	printf(“what %%”);
	int val=15%(-7);
	printf("\n\nvalue: %d \n",val);
	top = -1;     // Initially no element in stack
	printf("\n Enter the size of STACK : ");
	scanf("%d",&n);
	do
	{
	 	printf("\n---------------------------------------------------------");
		printf("\n 1.Push element \n 2.Pop element from Top\n 3.Display all element in stack\n 4.Exit\n");
		printf("\nEnter operation choice : ");
		scanf("%d",&choice);
		 
		if(choice==1) //Push operation
		{
			if(top >= n - 1)        
			{
				printf("\nSTACK OVERFLOW\n");    
			
			}
			else
			{
				printf("Enter a value to be pushed : ");
				scanf("%d",&x);
				top++;             // increment top after push operation
				stack[top] = x;   // element is push at the top
			}
		}
		 
		 
		if(choice==2) //POP operation
		 {
			  if(top <= -1)
			 {
			 	printf("\nSTACK UNDERFLOW\n");
			 }
			 else
			 {
				 printf("\nThe popped element is %d",stack[top]);   
				 top--;     //  after pop decrease top
			 }
		 }
		if(choice==3) // Display the element in stack
		 {
			 if(top >= 0)
			 {
				printf("\nElement in the stack\n\n");
				for(i = top ; i >= 0 ; i--)
					printf("%d\t",stack[i]);
			 }
			else
			 {
				printf("\nEMPTY STACK\n");
			 }
		 }
	
		if(choice>4) //Defaulf Case
		 {
			printf ("\nInvalid Choice\n");
		 }
		 }
		 while(choice!=4);
	 return 0;
}

