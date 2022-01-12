#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	char string[50];
	struct node *next,*child;
	int count;
}node;
//*******************************************
node *newnode(char string[]) 
{ 
    node *newnode=malloc(sizeof(node)); 
    newnode->next = newnode->child = NULL; 
    strcpy(newnode->string,string);
    return newnode; 
} 
int degree_of_root(node * n)
{
	int degree=0;
	n=n->child;
	if(n==NULL)
	{
		return degree;
	}
	while(n!=NULL)
	{
		n=n->next;
		degree++;
	}
	return degree;
}
void degree_of_categ(node * n)
{
	n=n->child;
	if(n==NULL)
	{
		printf("\nCategories not present in tree, Please Enter categories!!");
		return;
	}
	node *temp;
	while(n!=NULL)
	{
		int degree=0;
		printf("\nCategory: %s ",n->string);
		temp=n->child;
		while(temp!=NULL)
		{
			degree++;
			temp=temp->next;
		}
		printf("|| Degree: %d",degree);
		n=n->next;
	}
}

void display(node * n)
{
	printf("\nRoot is %s \n\n",n->string);
	n=n->child;
	if(n==NULL)
	{
		printf("No Categories and No word are present in tree!!");
		return;
	}
	node *temp;
	while(n!=NULL)
	{
		printf("\n\nCategory: %s",n->string);
		temp=n->child;
		printf("\nWords:  ");
		while(temp!=NULL)
		{
			printf("\n      %s: %d",temp->string,temp->count);
			temp=temp->next;
		}
		n=n->next;
	}
}
void depth(node * n,char string[])
{
	int flag=0;
	n=n->child;
	if(n==NULL)
	{
		printf("No Categories and No word are present in tree!!");
		return;
	}
	node *temp;
	while(n!=NULL)
	{
		if(strcmp(n->string,string)==0)
		{
			printf("\n\nCategory: %s  || Level: %d",n->string,1);
			flag=1;
		}
		temp=n->child;
		while(temp!=NULL)
		{
			if(strcmp(temp->string,string)==0)
			{
				printf("\n\nWord: %s  || Level: %d",temp->string,2);
				flag=1;
			}
			temp=temp->next;
		}
		n=n->next;
	}
	if(flag==0)
	{
		printf("string '%s' is not present in tree",string);
	}
}
void display_word_according_to_freq(node * n)
{
	printf("\nRoot is %s \n\n",n->string);
	int max_freq=1;
	n=n->child;
	if(n==NULL)
	{
		printf("No word is present in tree!!");
		return;
	}
	node *temp,*temp1=n;
	while(n!=NULL)
	{
		temp=n->child;
		while(temp!=NULL)
		{
			if(max_freq<temp->count)
			{
				max_freq=temp->count;
			}
			temp=temp->next;
		}
		n=n->next;
	}
	while(max_freq>0)
	{
		n=temp1;
		while(n!=NULL)
		{
			temp=n->child;
			while(temp!=NULL)
			{
				if(max_freq==temp->count)
				{
					printf("%s: %d  ||  ",temp->string,temp->count);
				}
				temp=temp->next;
			}
			n=n->next;
		}
		max_freq--;
	}
}

void display_categ(node * n)
{
	printf("\nRoot is %s \n\n",n->string);
	n=n->child;

	if(n==NULL)
	{
		return;
	}
	while(n!=NULL)
	{
		printf("\nCategory: %s",n->string);
		n=n->next;
	}
}
void display_leave(node * n)
{
	printf("\nRoot is %s \n\n",n->string);
	n=n->child;
	if(n==NULL)
	{
		return;
	}
	node *temp;
	printf("\nLeaves words: ");
	while(n!=NULL)
	{
		
		temp=n->child;
		
		while(temp!=NULL)
		{
			printf("\n%s  ",temp->string);
			temp=temp->next;
		}
		n=n->next;
	}
}

node *addcateg(node *n, char string[]) 
{
	if(n==NULL)
	{
		printf("\n\nCategory %s is inserted !!",string);
		return newnode(string);
	
	}
	else if(strcmp(string,n->string)==0)
	{
		printf("Category already Exists!!");
	}
    else 
    {
    	n->next=addcateg(n->next,string);
	}

	return n;
} 
node *add_newword(node *n, char string[]) 
{
	if(n==NULL)
	{
		printf("\n\nWord '%s' is inserted !!",string);
		node *temp=newnode(string);
		temp->count=1;
		return temp;
	
	}
	else if(strcmp(string,n->string)==0)
	{
		printf("frequency of '%s' is increased",n->string);
		n->count=n->count+1;
	}
    else 
    {
    	n->next=add_newword(n->next,string);
	}

	return n;
} 
node *addword(node *temp, char categ[],char string[])
{
	while(strcmp(temp->string,categ)!=0 && temp->next!=NULL)
	{
		//printf("%s    ",temp->string);
		temp=temp->next;
	}
	if(strcmp(temp->string,categ)==0)
	{
		temp->child=add_newword(temp->child, string);
	}
	else
	{
		printf("Category '%s' does not exits!!",categ);
	}
	
}

void main()
{
	int choice,i,d;
	char string[50],categ[50];
	node *root=newnode("WORDS");
	//root->child=newnode("Education");
	printf("\n\nroot is %s",root->string);
	while(1)
	{
		printf("\n=========================================================================================================");
		printf("\n1. Insert Category  || 2. Insert word          ||3. Display Category  ||4. Display Leave");
		printf("\n5. Degree of root   || 6. Degree of categories ||7. Display All       ||8. depth");
		printf("\n9. display words according to frequency  ||0. Exit\n");
	    printf("\nEnter your Choice:  ");
	    scanf("%d",&choice);
	    
	    if(1==choice)
	    {
	    	printf("\nEnter category name: ");
			scanf(" %[^\t\n]s", string);
			
			root->child=addcateg(root->child, string);
			
			
		}
	    else if(2==choice)
	    {
	    	if(root->child!=NULL)
	    	{
	    		printf("\nEnter category name: ");
				scanf(" %[^\t\n]s", categ);
				
				printf("\nEnter word: ");
				scanf(" %[^\t\n]s", string);
				addword(root->child,categ,string);
			}
			else
			{
				printf("\nCategory does not Exits, please Enter Category!!");
			}
			
		}
		else if(3==choice)
		{
			display_categ(root);
		}
		else if(4==choice)
		{
			display_leave(root);
		}
		else if(5==choice)
		{
			d=degree_of_root(root);
			printf("Degree of root is %d",d);
		}
		else if(6==choice)
		{
			degree_of_categ(root);
		}
		else if(7==choice)
	    {
	    	display(root);
		}
		
		else if(8==choice)
	    {
	    	printf("\nEnter category/word : ");
			scanf(" %[^\t\n]s", string);
	    	depth(root,string);
		}
		else if(9==choice)
	    {
	    	display_word_according_to_freq(root);
		}
		else if(0==choice)
		{
			
			exit(1);
		}
	}
	
}
