#include<stdio.h>
#include<stdlib.h>
 
struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};
int isEmpty(struct queue *q);
int isFull(struct queue *q);
void enqueue(struct queue *q, int val);
int dequeue(struct queue *q);
 
int main(){
    struct queue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));
    int choice;
    while(1)
    {
    	printf("\n---------------------------------------------------------");
		printf("\n 1.Enqueue element \n 2.Dequeuing element \n 3.Exit\n");
		printf("\nEnter operation choice : ");
		scanf("%d",&choice);
		
		if(choice==1)
		{
			int num;
			printf("Enter Value for inserting in Queue: ");
			scanf("%d",&num);
			enqueue(&q,num);
		}
		if(choice==2)
		{
			printf("Dequeuing element: %d\n", dequeue(&q));
		}
		if(choice==3)
		{
			exit(0);
		}
		if(choice>3)
		{
			printf("please Enter Valid choice");
		}
	}
    
 
    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    if(isFull(&q)){
        printf("Queue is full\n");
    }
 
    return 0;
}

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
        printf("Enqued element: %d\n", val);
    }
}
 
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}

