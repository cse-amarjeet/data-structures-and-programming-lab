#include <stdio.h>
#include<stdlib.h>
 
void insert(int f,int r,int initial,int q, int m);
void delete(int f,int r,int initial,int q);
void display(int f,int r,int initial,int q);
int queue_array[30];
//int rear=-1;
//int front=-1;   {-1,5,9,12};

int rear1[]={-1,19,39,59};
int front1[]= {-1,19,39,59};
main()
{
    int choice,i,select_Q,max;
    //Initial element Entering
    for(i=0;i<5;i++)
    {
    	 if (front1[0] == -1)
        {
        	front1[0] = 0;
		}
        rear1[0] = rear1[0] + 1;
        queue_array[rear1[0]] = i;	
	}
	for(i=0;i<3;i++)
    {
    	 if (front1[1] == 19)
        {
        	front1[1] = front1[1]+1;
		}
        rear1[1] = rear1[1] + 1;
        queue_array[rear1[1]] = i;	
	}
	for(i=0;i<2;i++)
    {
    	 if (front1[2] == 39)
        {
        	front1[2] = 40;
		}
        rear1[2] = rear1[2] + 1;
        queue_array[rear1[2]] = i;	
	}
	for(i=0;i<6;i++)
    {
    	 if (front1[3] == 59)
        {
        	front1[3] = 60;
		}
        rear1[3] = rear1[3] + 1;
        queue_array[rear1[3]] = i;	
	}
	//End of Initail element entering
    while (1)
    {
    	printf("\n=============================================================\n");
    	printf("0.Exit \n");
        printf("1.Insert element into queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all Queue \n\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
            
            if(choice==1)
            {
            	//Find number of element in each queue
            	int q1_min=-1,q2_min=-1,q3_min=-1,q4_min=-1;
            	if(front1[0]==-1)
            	{
            		q1_min=0;
				}
				else
				{
					if(q1_min<(rear1[0]-front1[0]+1))
            		{
            		q1_min=(rear1[0]-front1[0]+1);
					}
				}
            	if(front1[1]==19)
            	{
            		q2_min=0;
				}
				else
				{
					if(q2_min<(rear1[1]-front1[1]+1))
            		{
            		q2_min=(rear1[1]-front1[1]+1);
					}
				}
				if(front1[2]==39)
            	{
            		q3_min=0;
				}
				else
				{
					if(q3_min<(rear1[2]-front1[2]+1))
            		{
            		q3_min=(rear1[2]-front1[2]+1);
					}
				}
				if(front1[3]==59)
            	{
            		q4_min=0;
				}
				else
				{
					if(q4_min<(rear1[3]-front1[3]+1))
            		{
            		q4_min=(rear1[3]-front1[3]+1);
					}
				}
				//end of finding number of element in each queue
				//insert(front1[select_Q],rear1[select_Q],-1,select_Q,max);
				if(q1_min<=q2_min && q1_min<=q3_min && q1_min<=q4_min )
				{	
					insert(front1[0],rear1[0],-1,0,19);
				}
				else if(q2_min<=q1_min && q2_min<=q3_min && q2_min<=q4_min )
				{	
					insert(front1[1],rear1[1],19,1,39);
				}
				else if(q3_min<=q1_min && q3_min<=q2_min && q3_min<=q4_min )
				{	
					insert(front1[2],rear1[2],39,2,59);
				}
				else if(q4_min<=q1_min && q4_min<=q2_min && q4_min<=q3_min )
				{	
					insert(front1[3],rear1[3],-59,3,79);
				}
        	}
            else if(choice==2)
            {
            	//Find number of element in each queue
            	int q1_min=-1,q2_min=-1,q3_min=-1,q4_min=-1;
            	if(front1[0]==-1)
            	{
            		q1_min=0;
				}
				else
				{
					if(q1_min<(rear1[0]-front1[0]+1))
            		{
            		q1_min=(rear1[0]-front1[0]+1);
					}
				}
            	if(front1[1]==19)
            	{
            		q2_min=0;
				}
				else
				{
					if(q2_min<(rear1[1]-front1[1]+1))
            		{
            		q2_min=(rear1[1]-front1[1]+1);
					}
				}
				if(front1[2]==39)
            	{
            		q3_min=0;
				}
				else
				{
					if(q3_min<(rear1[2]-front1[2]+1))
            		{
            		q3_min=(rear1[2]-front1[2]+1);
					}
				}
				if(front1[3]==59)
            	{
            		q4_min=0;
				}
				else
				{
					if(q4_min<(rear1[3]-front1[3]+1))
            		{
            		q4_min=(rear1[3]-front1[3]+1);
					}
				}
				//end of finding number of element in each queue
				//Deleting
				if(q1_min>=q2_min && q1_min>=q3_min && q1_min>=q4_min )
				{	
					delete(front1[0],rear1[0],-1,0);
				}
				else if(q2_min>=q1_min && q2_min>=q3_min && q2_min>=q4_min )
				{	
					delete(front1[1],rear1[1],19,1);
				}
				else if(q3_min>=q1_min && q3_min>=q2_min && q3_min>=q4_min )
				{	
					delete(front1[2],rear1[2],39,2);
				}
				else if(q4_min>=q1_min && q4_min>=q2_min && q4_min>=q3_min )
				{	
					delete(front1[3],rear1[3],59,3);
				}
			}
            else if(choice==3)
            {
            	for(select_Q=0;select_Q<4;select_Q++)
            	{
            		if(select_Q==0)
	            	{
	            		display(front1[select_Q],rear1[select_Q],-1,select_Q);
					}
					else if(select_Q==1)
	            	{
	            		display(front1[select_Q],rear1[select_Q],19,select_Q);
					}
					else if(select_Q==2)
	            	{
	            		display(front1[select_Q],rear1[select_Q],39,select_Q);
					}
					else if(select_Q==3)
	            	{
	            		display(front1[select_Q],rear1[select_Q],59,select_Q);
					}
				}
			}
			else if(choice==0)
            {
            	exit(0);
            }
            else
            {
            	 printf("Wrong choice \n");
			}
        
    } /* End of while */
} /* End of main() */
 
void insert(int f,int r,int initial,int q, int m)
{
    int add_item;
    if (r == m - 1)
    printf("Queue Overflow \n");
    else
    {
        if (f == initial)
        {
        	f = initial+1;
		}
        printf("Inset the element in queue : ");
        scanf("%d", &add_item);
        r = r + 1;
        queue_array[r] = add_item;
    }
    rear1[q]=r;
    front1[q]=f;
} /* End of insert() */
 
void delete(int f,int r,int initial,int q)
{
    if (f == initial || f > r)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[f]);
        f = f + 1;
    }
    front1[q]=f;
} /* End of delete() */
 
void display(int f,int r,int initial,int q)
{
    int i;
    //printf("F:%d  Rear: %d  Initial: %d ",f,r,initial);
    if (f == initial)
        printf("Queue %d is empty \n",q+1);
    else
    {
        printf("\nQueue %d is: \n",q+1);
        for (i = f; i <= r; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
} 
