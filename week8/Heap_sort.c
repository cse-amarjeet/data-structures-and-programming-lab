#include <stdio.h>
#include <stdlib.h>
int count=7;
//************Build Max Heap ***************************
void make_max_heap(int * a, int size) {
	int heapsize;
	for(heapsize = 0; heapsize < size; ++heapsize) {
		int n = heapsize;
		while(n > 0) {
			int p = (n-1) / 2;
			if (a[n] > a[p]) {
				int t = a[n];
				a[n] = a[p];
				a[p] = t;
				n = p;
			}
			
			else
			{
				break;
			}
		}
	}
}
////////////////////////////////////////////////////////
//************Build Min Heap ***************************
void make_min_heap(int * a, int size) {
	int heapsize;
	for(heapsize = 0; heapsize < size; ++heapsize) {
		int n = heapsize;
		while(n > 0) {
			int p = (n-1) / 2;
			if (a[n] < a[p]) {
				int t = a[n];
				a[n] = a[p];
				a[p] = t;
				n = p;
			}
			
			else
			{
				break;
			}
		}
	}
}
/////////////////////////////////////////////////////////////////
//************Heap sort Using Max Heap***************************
void sort_heap_using_max(int * a, int n) {
	int heapsize = n; 
	while(heapsize > 0) {
		int t = a[0];  //swap
		a[0] = a[--heapsize];
		a[heapsize] = t;
		int p = 0;
		int c = 1;
		while(c < heapsize) {
			if (c + 1 < heapsize && a[c + 1] > a[c]) c++;  // Check greater value between left and right node of root
			if (a[c] > a[p]) {   						   // check root node is greater or left/right node of that root node 
				int t = a[p];    //swap
				a[p] = a[c];
				a[c] = t;
				p = c;
				c = p * 2 + 1;
			} else {
				break;
			}
		}
	}
}
////////////////////////////////////////////////////////////
//************Heap sort Using Min Heap***************************
void sort_heap_using_min(int * a, int n) {
	int heapsize = n; 
	while(heapsize > 0) {
		int t = a[0];  //swap
		a[0] = a[--heapsize];
		a[heapsize] = t;
		int p = 0;
		int c = 1;
		while(c < heapsize) {
			if (c + 1 < heapsize && a[c + 1] < a[c]) c++;  // Check greater value between left and right node of root
			if (a[c] < a[p]) {   						   // check root node is greater or left/right node of that root node 
				int t = a[p];    //swap
				a[p] = a[c];
				a[c] = t;
				p = c;
				c = p * 2 + 1;
			} else {
				break;
			}
		}
	}
}
////////////////////////////////////////////////////////////
//************Insert in Max Heap***************************
int insert_max_heap(int *a,int n, int value)
{
	a[n]=value;
	int i=n,parent;
	while(i>0)
	{
		parent=(i-1)/2;
		if(a[parent]<a[i])
		{
			int temp;
			temp=a[parent];
			a[parent]=a[i];
			a[i]=temp;
			i=parent;
		}
		else
		{
			printf("%d is inserted !!",value);
			return;
		}
	}	
}
////////////////////////////////////////////////////////////
//************Insert in Min Heap***************************
int insert_min_heap(int *a,int n, int value)
{
	a[n]=value;
	int i=n,parent;
	while(i>0)
	{
		parent=(i-1)/2;
		if(a[parent]>a[i])
		{
			int temp;
			temp=a[parent];
			a[parent]=a[i];
			a[i]=temp;
			i=parent;
		}
		else
		{
			printf("%d is inserted !!",value);
			return;
		}
	}	
}
///////////////////////////////////////////////////////////////
//************Delete from Max Heap***************************
int delete_from_max_heap(int *a,int n)
{
	n=count-1;
	int temp=a[0],p,c;   //store max value in temp variable
	a[0]=a[n];
	a[n]=temp;
	p=0;
	c=1;
	while(c<n)
	{
		if (c + 1 < n && a[c + 1] > a[c]) c++;  // Check greater value between left and right node of root
		if (a[c] > a[p]) {   						   // check root node is greater or left/right node of that root node 
			int t = a[p];    //swap
			a[p] = a[c];
			a[c] = t;
			p = c;
			c = p * 2 + 1;
		} else {
			break;
		}
	}
	return temp;	
}
///////////////////////////////////////////////////////////////
//************Delete from Max Heap***************************
int delete_from_min_heap(int *a,int n)
{
	n=count-1;
	int temp=a[0],p,c;   //store max value in temp variable
	a[0]=a[n];
	a[n]=temp;
	p=0;
	c=1;
	while(c<n)
	{
		if (c + 1 < n && a[c + 1] < a[c]) c++;  // Check greater value between left and right node of root
		if (a[c] < a[p]) {   						   // check root node is greater or left/right node of that root node 
			int t = a[p];    //swap
			a[p] = a[c];
			a[c] = t;
			p = c;
			c = p * 2 + 1;
		} else {
			break;
		}
	}
	return temp;	
}
//////////////////////////////////////////////////////////////


int main() {
	int a[100],i,ch,ch1,temp;
	for (i = 0; i < count; ++i) 
		a[i] = rand() % 100;
	
	printf("Initailly array is: ");
	for(i=0;i<count;i++)
		{
			printf("%d  ",a[i]);
			
		}
	printf("\n");

	printf("\n\n1. Using min-heapify\n2. Using Max-heapify");
	printf("\nEnter Your Choice: ");
	scanf("%d",&ch1);
	if(ch1==1)
	{
		
	
		while(1)
		{
			printf("\n===================================Using Min -heapify===================================\n");
			printf("1. Build Heap\n2. Insert key into Heap\n3. Delete key into haep\n4. sort\n0. Exit");
			printf("\nEnter Your choice: ");
			scanf("%d",&ch);
			if(ch==1)
			{
				make_min_heap(a, count);
		
				printf("Heap:  ");
				for(i = 0; i < count; ++i)
					printf("%d ", a[i]);
				printf("\n\n");
						
			}
			else if(ch==2)
			{
				printf("Enter a key: ");
				scanf("%d",&temp);
				insert_min_heap(a,count,temp);
				count++;
				printf("\n\n");
				for(i=0;i<count;i++)
				{
					printf("%d  ",a[i]);
					
				}
				printf("\n");
			}
			else if(ch==3)
			{
				int t1=delete_from_min_heap(a,count);
				printf("\nminimum element deleted from min Heap is:  %d",t1);//delete_from_min_heap 
				printf("\nAfter Deletion of %d, The Min Heap is: \n",t1); 
				count--;
				for(i=0;i<count;i++)
				{
					printf("%d  ",a[i]);
					
				}
				printf("\n");
			}
			else if(ch==4)
			{
				sort_heap_using_min(a, count);
				printf("array: ");
				for(i = count-1; i >= 0; --i)
					printf("%d ", a[i]);
				printf("\n");
						
			}
			else if(ch==0)
			{
				exit(1);
			}
			else
			{
				printf("Enter a valied choice!!");
				continue;
			}
        }
		
	}
	else if(ch1==2)
	{
	
		while(1)
		{
			printf("\n===================================Using Max-heapify===================================\n");
			printf("1. Build Heap\n2. Insert key into Heap\n3. Delete key into haep\n4. sort\n5. Display array\n0. Exit");
			printf("\nEnter Your choice: ");
			scanf("%d",&ch);
			if(ch==1)
			{
				make_max_heap(a, count);
		
				printf("Heap:  ");
				for(i = 0; i < count; ++i)
					printf("%d ", a[i]);
				printf("\n\n");
						
			}
			else if(ch==2)
			{
				printf("Enter a key: ");
				scanf("%d",&temp);
				//a[count]=temp;
				
				insert_max_heap(a,count,temp);
				count++;
				printf("\n\n");
				for(i=0;i<count;i++)
				{
					printf("%d  ",a[i]);
					
				}
				printf("\n");
			}
			else if(ch==3)
			{
				printf("maximum element deleted from max Heap is:  %d",delete_from_max_heap(a,count));
				printf("\n"); 
				count--;
			}
			else if(ch==4)
			{
				sort_heap_using_max(a, count);
				printf("array: ");
				for(i = 0; i < count; ++i)
					printf("%d ", a[i]);
				printf("\n");
						
			}
			else if(ch==5)
			{
				for(i=0;i<count;i++)
				{
					printf("%d  ",a[i]);
					
				}
				printf("\n");
			}
			else if(ch==0)
			{
				exit(1);
			}
			else
			{
				printf("Enter a valied choice!!");
			}
        }
	}
	else
	{
		printf("Enter a valied choice!!");
	}
	return 0;
}
