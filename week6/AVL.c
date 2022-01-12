#include<stdio.h>
#include<stdlib.h>
int sum=0;
typedef struct node
{
int data;
struct node *left,*right;
int ht;
}node;

int sum_of_left(node *n)
{
	if(n!=NULL)
	{
		sum_of_left(n->left);
		sum=sum+n->data;
		sum_of_left(n->right);
	}
	return sum;
}
node *insert(node *,int);
node *Delete(node *,int);
void preorder(node *);
void inorder(node *);
void postorder(node *);
int height( node *);
node *rotateright(node *);
node *rotateleft(node *);
node *RR(node *);
node *LL(node *);
node *LR(node *);
node *RL(node *);
int BF(node *);
 
int main()
{
	node *root=NULL;
	int x,n,i,op;
	while(1)
	{
		printf("\n======================================================================");
		printf("\n1. Insert \n2. Delete \n3. Print (preorder, Inorder, Postorder)\n4. Sum of all node in left subtree \n0. Exit" );
		printf("\n\nEnter Your Choice:");
		scanf("%d",&op);
		
		
		if(op==1)
		{
			printf("\nEnter a data:");
			scanf("%d",&x);
			root=insert(root,x);
		}
		else if(op==2)
		{
			printf("\nEnter a data:");
			scanf("%d",&x);
			root=Delete(root,x);
		}
		else if(op==3)
		{
			printf("\nPreorder sequence:\n");
			preorder(root);
			printf("\n\nInorder sequence:\n");
			inorder(root);
			printf("\n\nPostOrder: \n");
			postorder(root);
		}
		else if(op==4)
		{
			int temp;
			sum=0;
			if(root!=NULL)
			{
				temp=sum_of_left(root->left);
				printf("Sum of left subtree of root node is: %d",temp);
			}
			else
			{
				printf("left subtree is empty!!");
			}
			
		}
		if(op==0)
		{
			exit(0);
		}
	}
	return 0;
}
 
node * insert(node *T,int x)
{
	if(T==NULL)
	{
	T=(node*)malloc(sizeof(node));
	T->data=x;
	T->left=NULL;
	T->right=NULL;
}
	else
		if(x > T->data) // insert in right subtree
		{
			T->right=insert(T->right,x);
			if(BF(T)==-2)
			if(x>T->right->data)
			T=RR(T);
			else
			T=RL(T);
		}
		else if(x<T->data)
		{
			T->left=insert(T->left,x);
			if(BF(T)==2)
			if(x < T->left->data)
			T=LL(T);
			else
			T=LR(T);
		}
		T->ht=height(T);
		return(T);
	}
 
node * Delete(node *T,int x)
{
	node *p;
	if(T==NULL)
	{
		return NULL;
	}
	else if(x > T->data) // insert in right subtree
	{
		T->right=Delete(T->right,x);
		if(BF(T)==2)
		if(BF(T->left)>=0)
		T=LL(T);
		else
		T=LR(T);
	}
	else if(x<T->data)
	{
		T->left=Delete(T->left,x);
		if(BF(T)==-2) //Rebalance during windup
		if(BF(T->right)<=0)
		T=RR(T);
		else
		T=RL(T);
	}
	else
	{
		if(T->right!=NULL)
		{ 
			p=T->right;
			while(p->left!= NULL)
			p=p->left;
			T->data=p->data;
			T->right=Delete(T->right,p->data);
			if(BF(T)==2)
			if(BF(T->left)>=0)
			T=LL(T);
			else
			T=LR(T);
		}
		else
		return(T->left);
	}
	T->ht=height(T);
	return(T);
}
 
int height(node *T)
{
	int lh,rh;
	if(T==NULL)
	return(0);
	if(T->left==NULL)
	lh=0;
	else
	lh=1+T->left->ht;
	if(T->right==NULL)
	rh=0;
	else
	rh=1+T->right->ht;
	if(lh>rh)
	return(lh);
	return(rh);
}
 
node * rotateright(node *x)
{
	node *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->ht=height(x);
	y->ht=height(y);
	return(y);
}
 
node * rotateleft(node *x)
{
	node *y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->ht=height(x);
	y->ht=height(y);
	return(y);
}
 
node * RR(node *T)
{
	T=rotateleft(T);
	return(T);
}
 
node * LL(node *T)
{
	T=rotateright(T);
	return(T);
}
 
node * LR(node *T)
{
	T->left=rotateleft(T->left);
	T=rotateright(T);
	return(T);
}
 
node * RL(node *T)
{
	T->right=rotateright(T->right);
	T=rotateleft(T);
	return(T);
}
 
int BF(node *T)
{
	int lh,rh;
	if(T==NULL)
	return(0);
	 
	if(T->left==NULL)
	lh=0;
	else
	lh=1+T->left->ht;
	 
	if(T->right==NULL)
	rh=0;
	else
	rh=1+T->right->ht;
	 
	return(lh-rh);
}
 
void preorder(node *T)
{
	if(T!=NULL)
	{
		printf(" %d ",T->data);
		preorder(T->left);
		preorder(T->right);
	}
}
 
void inorder(node *T)
{
	if(T!=NULL)
	{
		inorder(T->left);
		printf(" %d ",T->data);
		inorder(T->right);
	}
}
void postorder(node *T)
{
	if(T!=NULL)
	{
		postorder(T->left);
		postorder(T->right);
		printf(" %d ",T->data);
	}
}
