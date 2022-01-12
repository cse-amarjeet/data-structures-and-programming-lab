#include <stdio.h>
#include <limits.h>
int min(int x, int y) {
    return (x < y) ? x : y;
}
int SmallSubarrayLen(int arr[], int n, int k)
{
    int Sum = 0;
    int len = INT_MAX;
    int left = 0;
    for (int right = 0; right < n; right++)
    {
        Sum += arr[right];
        while (Sum > k && left <= right)
        {
            len = min(len, right - left + 1);
            Sum -= arr[left];
            left++;
        }
    }
 
    if (len == INT_MAX) {
        return 0;
    }
    return len;
}
 
int main()
{
    int k,num;
    printf("Number of element You want to insert in array: ");
    scanf("%d",&num);
    int arr[num];
    printf("Enter element in array: ");
    for(int i=0;i<num;i++)
    {
    	scanf("%d",&arr[i]);
	}

    
    printf("Enter a Number 'N' sum of aubarray will grater Number 'N':  ");
    scanf("%d",&k);
    int n = sizeof(arr) / sizeof(arr[0]);
    int len = SmallSubarrayLen(arr, n, k);
    if(len==0)
    {
    	printf("No subarray exists");
	}
    else
    {
    	if (len != INT_MAX) {
        printf("The smallest subarray length is: %d", len);
    	}
    	else {
        	printf("No subarray exists");
    	}
	}
    
 
    return 0;
}



