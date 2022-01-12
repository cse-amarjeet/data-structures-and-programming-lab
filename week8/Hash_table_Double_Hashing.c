#include <stdlib.h>
#include <stdio.h>
#define size 11 // Hash Table Size
int insert(int ele);
int search(int ele);
int delete_ele(int ele);
int hash[size],count=0;  //Hash Table Initilazation

/*
if Hash table cell contain "-1" then that cell is empty
1st Hash Function---> h1(k)= k (mod 11)
2st Hash Function---> h2(k)= 8-( k (mod 8))
if collision Happen then resolve using --->  [h1(k)+ i*h2(k)]mod 11
here "i" is collision number
*/

void main()
{
	int choice,temp,i;
	for(i=0;i<size;i++)  //initially fill hash table with -1
	{
		hash[i]=-1;
	}
	
	
	while(1)
	{
		printf("\n===============================Double Hashing===============================================\n");
		printf("\n1. Insert element \n2. Search element \n3. Delete an element \n4. Calculate Load Factor \n5. Display array element\n0. Exit");
		printf("\nEnter Your choice: ");
		scanf("%d",&choice);
		
		if(choice==1)
		{
			int insert_success;
			printf("\nEnter Element for Insertion: ");
			scanf("%d",&temp);
			count=count+1;
			insert_success= insert(temp);
			
			if(insert_success==1)
			{
				printf("%d is inserted !!",temp);
			}
			else
			{
				printf("\nHash Table Full  !!");
			}
		}
		else if(choice==2)
		{
			int index=-1;
			printf("\nEnter Element for Search: ");
			scanf("%d",&temp);
			index=search(temp);
			if(index!=-1)
			{
				printf("Index of %d is: %d",temp,index);
			}
			else
			{
				printf("Element not Found!! ");
			}
			
		}
		else if(choice==3)
		{
			printf("\nEnter Element for Deletion: ");
			scanf("%d",&temp);
			count=count-1;
			delete_ele(temp);
		}
		else if(choice==4)
		{
			printf("\nCount: %d  Size: %d\n ",count,size);
			printf("Load factor of the hash table: %.4f",((float)count/(float)size));
		}
		else if(choice==0)
		{
			exit(0);
		}
		else if(choice==5)
		{
			for(i=0;i<size;i++)
			{
				printf(" %d ",hash[i]);
			}
		}
		else
		{
			printf("Please Enter a valid choice !!");
		}
	}
	
}
int insert(int ele)
{
		int t,i,prob1,prob2;
		t=ele%size;
		prob1=t;
		prob2=8-(ele%8);
		for(i=1;i<size+1;i++)
		{
			if(hash[t]==-1 || hash[t]==-2)
			{
				hash[t]=ele;
				return 1;
			}
			t=(prob1+ i*prob2)%size ;  // Double Hashing Function
		}
}
int search(int ele)
{
		int t,i,prob1,prob2;
		t=ele%size;
		prob1=t;
		prob2=8-(ele%8);
		for(i=1;i<size+1;i++)
		{
			if(hash[t]==ele)  
			{
				return t;
			}
			else if(hash[t]==-1)  // when hash contain "-1" that means hash table doesn't contain the value.
			{
				return -1;
			}
			/*
			if(hash[t]==-2) // if hash contain "-2" that means previously box 
			{               //contained the value but deleted so, nothing have to do,
							// just go to next index and continue searching
			}*/
			t=(prob1+ i*prob2)%size ;  // Double Hashing Function
		}
	return -1;
	
}

int delete_ele(int ele)
{
	int temp;
	temp=search(ele);
	if(temp!=-1)
	{
		hash[temp]=-2; //if Hash table cell contain "-2" then that cell is element is deleted and cell is empty
		printf("Element is Deleted !!");
	}
	else
	{
		printf("Element not exit !!");
	}	
}
