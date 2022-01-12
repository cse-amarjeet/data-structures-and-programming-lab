#include<stdio.h>
#include<stdlib.h>

void print_numbers(int *p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",p[i]);
	}
}

int largest(int arr[], int n) {
    int mx = arr[0];
    int i;
    for (i = 1; i < n; i++)
    {
        if (arr[i] > mx)
        {
        	mx = arr[i];	
		}
    }
    return mx;
}
 
void countSort(int arr[], int n, int exp) {
    int output[n]; // output array
    int i, count[10] = { 0 };
 
    // count of occurrences
    for (i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }
 
    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
 
    //output array
    for (i = n - 1; i >= 0; i--) 
	{
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    for (i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}
 

void radix_sort(int arr[], int n) {
    int m = largest(arr, n);
 
    int exp;
    for (exp = 1; m / exp > 0; exp *= 10)
    {
    	countSort(arr, n, exp);
	}
}

void main()
{
	int n,i,choice;
	while(1)
	{
		printf("\n==================================================\n");
		printf("How many Number do you want to sort: ");
		scanf("%d",&n);
		int numbers[n];
		
		printf("Enter the Numbers: ");
		for(i=0;i<n;i++)
		{
			scanf("%d",&numbers[i]);
		}
		printf("\n\nNumbers before sorting:");
		print_numbers(numbers,n);
		
		radix_sort(numbers,n);
		printf("\nNumbers after sorting: ");
		print_numbers(numbers,n);
		
		printf("\n\nDo you want to run again(yes-->1 || No--> 0):");
		scanf("%d",&choice);
		if(choice==0)
		{
			exit(0);
		}
	}
}




