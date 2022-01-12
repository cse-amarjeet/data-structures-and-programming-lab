#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};
struct queue q;
 
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        //printf("Enqued element: %d\n", val);
    }
}
 
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        //printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}

void print_matrix(int n,int matrix[n][n])
{
	int i,j;
		for(i=0;i<n;i++)
	{
		printf("%d: ",i);
		for(j=0;j<n;j++)
		{
			printf("%d  ",matrix[i][j]);
		}
		printf("\n");
	}
}
void print_dfs(int n,int matrix[n][n], int start_v,int visited[])
{
	int i;
	printf("%d  ",start_v);
	visited[start_v]=1;
	for(i=0;i<n;i++)
	{
		if(i==start_v)
		{
			continue;
		}
		if(matrix[start_v][i]==1)
		{
			if(visited[i]==1)
			{
				continue;
			}
			print_dfs(n,matrix,i,visited);
		}
	}
}

void main()
{
	int choice;
	int n,e,i,j;
	
	q.size = 40;
	q.f = q.r = 0;
	q.arr = (int*) malloc(q.size*sizeof(int));	
	
	printf("Enter number of vertices: ");
	scanf("%d",&n);
	int matrix[n][n];
	while(1)
	{
		printf("\n==============================================================\n");
		printf("1. Create a Graph \n2. BFS traversal in the Graph\n3. DFS traversal in the Graph\n4. Print adjacency matrix\n0. Exit");
		printf("\nEnter Your Choice: ");
		scanf("%d",&choice);
		if(1==choice)
		{
			printf("Enter number of edges: ");
			scanf("%d",&e);
			//matrix initialization with "0"
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					matrix[i][j]=0;
				}
			}
			
			printf("Enter the edges between two vertices:");
			int v1,v2;
			for(i=0;i<e;i++)
			{
				printf("\nEnter 1st Vertice: ");
				scanf("%d",&v1);
				if(v1>n-1)
				{
					printf("Entre valid vertices!!\n\nEnter vertices between 0 to %d\n",n-1);
					i--;
					continue;
				}
				printf("Enter 2nd Vertice: ");
				scanf("%d",&v2);
				if(v2>n-1)
				{
					printf("Entre valid vertices!!\nEnter vertices between 0 to %d",n-1);
					i--;
					continue;
				}
				matrix[v1][v2]=1;
				matrix[v2][v1]=1;
				printf("edges between %d and %d created!!",v1,v2);
			}
		}
		else if(2==choice)
		{
			int node;
		    int i = 0,j,k;
		    int visited[n];
		    for(k=0;k<n;k++)
		    {
		    	visited[k]=0;
			}
		    printf("%d ", i);
		    visited[i] = 1;
		    enqueue(&q, i); // Enqueue i for exploration
		    while (!isEmpty(&q))
		    {
		        int node = dequeue(&q);
		        for (j = 0; j < 7; j++)
		        {
		            if(matrix[node][j] ==1 && visited[j] == 0){
		                printf(" %d ", j);
		                visited[j] = 1;
		                enqueue(&q, j);
		            }
		        }
		    }
		}
		else if(3==choice)
		{
			int visited[n];
			for(i=0;i<n;i++)
			{
				visited[i]=0;
			}
		
			print_dfs(n,matrix,0,visited);
		}
		else if(4==choice)
		{
			printf("\n\n");
			print_matrix(n,matrix);
		}
		else if(0==choice)
		{
			exit(0);
		}
		
		
	}
}
