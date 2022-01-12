#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

void Merge(int *A,int *L,int leftCount,int *R,int rightCount);
void MergeSort(int *A,int n);
void swap(int *a, int *b);
int Partition(int a[], int low, int high);
int RandomPivotPartition(int a[], int low, int high);
int QuickSort_random_pivot(int a[], int low, int high);
int QuickSort(int a[], int low, int high);
int partition_pivot_median(int array[], int low, int high);
int QuickSort_pivot_median(int a[], int low, int high);
void main()
{
	int choice;
	printf("\n1. Quick Sort\n2. Merge sort\n");
	printf("Enter Your Choice: ");
	scanf("%d",&choice);
	if(1==choice)
	{
		clock_t start41,end41,start51,end51,start42,end42,start52,end52,start43,end43,start53,end53,start61,end61,start62,end62,start63,end63,start71,end71,start72,end72,start73,end73;
		float t41,t51,t42,t52,t43,t53,t61,t62,t63,t71,t72,t73;
		int i,n;
		n=pow(10,4);
		int *A1=(int*)malloc(n*sizeof(int)); 
		//**************************first pivot 10^4 for random array element*******************
		start41=clock();
		//initiallization of array 
	    for(i=0;i<n;i++)
	    {
	  		A1[i] = rand() % n; 
		}
		printf("\nBefore Sorting the array\n");
		for(i = 0; i < n; i++)
		{
			printf("%d ", A1[i]);
		}
		printf("\n\n\n==================================================\n\n===============================================\n\n\n\n");
		
		QuickSort(A1,0,n-1);  //calling merge sort
		
		printf("\nAfter Sorting the array\n");
		for(i = 0; i < n; i++){
		    printf("%d ", A1[i]);
	    	}
		end41=clock();
		t41=(end41-start41)/CLOCKS_PER_SEC;
		
		//**************************first pivot 10^4 for sorted array*******************
		start42=clock();
		
		 // After Calling merge shorted on A1 array, The A1 array is sorted now
		 // so call marge sort on A1 itself
		QuickSort(A1,0,n-1);
		end42=clock();
		t42=(end42-start42)/CLOCKS_PER_SEC;
		
		//**************************first pivot 10^4 for almost sorted array*******************
		start43=clock();
		int n_1_percent=n/100,temp; // 1% of n
		for(i=0;i<n_1_percent;i++)
		{
			temp=rand() % n; 
			A1[temp]=temp;
		}
		QuickSort(A1,0,n-1);
		end43=clock();
		t43=(end43-start43)/CLOCKS_PER_SEC;
		
		printf("\n\nFor 10^4:\n");
		printf("\nPivot         Random            sorted        Almost sorted");
		printf("\n\nFirst     %f          %f          %f ",t41,t42,t43);
		//**************************Random pivot 10^4 for random array element******************* 
		start51=clock();
		//initiallization of array 
	    for(i=0;i<n;i++)
	    {
	  		A1[i] = rand() % n; 
		}
		/*printf("\nBefore Sorting the array\n");
		for(i = 0; i < n; i++)
		{
			printf("%d ", A1[i]);
		}
		printf("\n\n\n=================================================================================================\n\n\n\n");
		*/
		QuickSort_random_pivot(A1,0,n-1);  //calling merge sort
		/*
		printf("\nAfter Sorting the array\n");
		for(i = 0; i < n; i++){
		    printf("%d ", A1[i]);
	    	}*/
		end51=clock();
		t51=(end51-start51)/CLOCKS_PER_SEC;
		
		//**************************Random pivot 10^4 for sorted array*******************
		start52=clock();
		
		 // After Calling merge shorted on A2 array, The A1 array is sorted now
		 // so call marge sort on A2 itself
		QuickSort_random_pivot(A1,0,n-1);
		end52=clock();
		t52=(end52-start52)/CLOCKS_PER_SEC;
		//**************************Random pivot 10^4 for almost sorted array*******************
		start53=clock();
		n_1_percent=n/100; // 1% of n
		for(i=0;i<n_1_percent;i++)
		{
			temp=rand() % n; 
			A1[temp]=temp;
		}
		QuickSort_random_pivot(A1,0,n-1);
		end53=clock();
		t53=(end53-start53)/CLOCKS_PER_SEC;
		
		printf("\nRandom     %f          %f          %f ",t51,t52,t53);
		//**************************median pivot 10^4 for random array element*******************
		start61=clock();
		//initiallization of array 
	    for(i=0;i<n;i++)
	    {
	  		A1[i] = rand() % n; 
		}
		/*printf("\nBefore Sorting the array\n");
		for(i = 0; i < n; i++)
		{
			printf("%d ", A1[i]);
		}
		printf("\n\n\n=================================================================================================\n\n\n\n");
		*/
		QuickSort_pivot_median(A1,0,n-1);  //calling merge sort
		/*
		printf("\nAfter Sorting the array\n");
		for(i = 0; i < n; i++){
		    printf("%d ", A1[i]);
	    	}*/
		end61=clock();
		t61=(end61-start61)/CLOCKS_PER_SEC;
		//**************************median pivot 10^4 for sorted array*******************
		start62=clock();
		
		 // After Calling merge shorted on A2 array, The A1 array is sorted now
		 // so call marge sort on A2 itself
		QuickSort_pivot_median(A1,0,n-1);
		end62=clock();
		t62=(end62-start62)/CLOCKS_PER_SEC;
		//*************************median pivot 10^4 for almost sorted array*******************
		start63=clock();
		n_1_percent=n/100; // 1% of n
		for(i=0;i<n_1_percent;i++)
		{
			temp=rand() % n; 
			A1[temp]=temp;
		}
		QuickSort_pivot_median(A1,0,n-1);
		end63=clock();
		t63=(end63-start63)/CLOCKS_PER_SEC;
		printf("\nMedian     %f          %f          %f ",t61,t62,t63);
		//*************************median pivot 10^4 for random array element*******************
		start71=clock();
		//initiallization of array 
	    for(i=0;i<n;i++)
	    {
	  		A1[i] = rand() % n; 
		}
		/*printf("\nBefore Sorting the array\n");
		for(i = 0; i < n; i++)
		{
			printf("%d ", A1[i]);
		}
		printf("\n\n\n=================================================================================================\n\n\n\n");
		*/
		QuickSort_random_pivot(A1,0,n-1);  //calling merge sort
		/*
		printf("\nAfter Sorting the array\n");
		for(i = 0; i < n; i++){
		    printf("%d ", A1[i]);
	    	}*/
		end71=clock();
		t71=(end71-start71)/CLOCKS_PER_SEC;
		//*************************median pivot 10^4 for sorted array*******************
		start72=clock();
		
		 // After Calling merge shorted on A2 array, The A1 array is sorted now
		 // so call marge sort on A2 itself
		QuickSort_random_pivot(A1,0,n-1);
		end72=clock();
		t72=(end72-start72)/CLOCKS_PER_SEC;
		//*************************median pivot 10^4 for almost sorted array*******************
		start73=clock();
		n_1_percent=n/100; // 1% of n
		for(i=0;i<n_1_percent;i++)
		{
			temp=rand() % n; 
			A1[temp]=temp;
		}
		QuickSort_random_pivot(A1,0,n-1);
		end73=clock();
		t73=(end73-start73)/CLOCKS_PER_SEC;
		printf("\nMedian    %f          %f          %f ",t71,t72,t73);
		
			
//#######################10^5 starts here ##############################################################	
			
		n=pow(10,5);
		int *A2=(int*)malloc(n*sizeof(int)); 
		//**************************first pivot 10^5 for random array element*******************
		start41=clock();
		//initiallization of array 
	    for(i=0;i<n;i++)
	    {
	  		A2[i] = rand() % n; 
		}
		/*printf("\nBefore Sorting the array\n");
		for(i = 0; i < n; i++)
		{
			printf("%d ", A2[i]);
		}
		printf("\n\n\n==================================================\n\n===============================================\n\n\n\n");
		*/
		QuickSort(A2,0,n-1);  //calling merge sort
		/*
		printf("\nAfter Sorting the array\n");
		for(i = 0; i < n; i++){
		    printf("%d ", A2[i]);
	    	}*/
		end41=clock();
		t41=(end41-start41)/CLOCKS_PER_SEC;
		
		//**************************first pivot 10^5 for sorted array*******************
		start42=clock();
		
		 // After Calling merge shorted on A2 array, The A2 array is sorted now
		 // so call marge sort on A2 itself
		QuickSort(A2,0,n-1);
		end42=clock();
		t42=(end42-start42)/CLOCKS_PER_SEC;
		
		//**************************first pivot 10^5 for almost sorted array*******************
		start43=clock();
		n_1_percent=n/100,temp; // 1% of n
		for(i=0;i<n_1_percent;i++)
		{
			temp=rand() % n; 
			A2[temp]=temp;
		}
		QuickSort(A2,0,n-1);
		end43=clock();
		t43=(end43-start43)/CLOCKS_PER_SEC;
		
		printf("\n\n\nFor 10^5:\n");
		printf("\nPivot         Random            sorted        Almost sorted");
		printf("\n\nFirst     %f          %f          %f ",t41,t42,t43);
		//**************************Random pivot 10^5 for random array element******************* 
		start51=clock();
		//initiallization of array 
	    for(i=0;i<n;i++)
	    {
	  		A2[i] = rand() % n; 
		}
		/*printf("\nBefore Sorting the array\n");
		for(i = 0; i < n; i++)
		{
			printf("%d ", A2[i]);
		}
		printf("\n\n\n=================================================================================================\n\n\n\n");
		*/
		QuickSort_random_pivot(A2,0,n-1);  //calling merge sort
		/*
		printf("\nAfter Sorting the array\n");
		for(i = 0; i < n; i++){
		    printf("%d ", A2[i]);
	    	}*/
		end51=clock();
		t51=(end51-start51)/CLOCKS_PER_SEC;
		
		//**************************Random pivot 10^5 for sorted array*******************
		start52=clock();
		
		 // After Calling merge shorted on A2 array, The A2 array is sorted now
		 // so call marge sort on A2 itself
		QuickSort_random_pivot(A2,0,n-1);
		end52=clock();
		t52=(end52-start52)/CLOCKS_PER_SEC;
		//**************************Random pivot 10^5 for almost sorted array*******************
		start53=clock();
		n_1_percent=n/100; // 1% of n
		for(i=0;i<n_1_percent;i++)
		{
			temp=rand() % n; 
			A2[temp]=temp;
		}
		QuickSort_random_pivot(A2,0,n-1);
		end53=clock();
		t53=(end53-start53)/CLOCKS_PER_SEC;
		
		printf("\nRandom     %f          %f          %f ",t51,t52,t53);
		//**************************median pivot 10^5 for random array element*******************
		start61=clock();
		//initiallization of array 
	    for(i=0;i<n;i++)
	    {
	  		A2[i] = rand() % n; 
		}
		/*printf("\nBefore Sorting the array\n");
		for(i = 0; i < n; i++)
		{
			printf("%d ", A2[i]);
		}
		printf("\n\n\n=================================================================================================\n\n\n\n");
		*/
		QuickSort_pivot_median(A2,0,n-100000);  //calling merge sort
		/*
		printf("\nAfter Sorting the array\n");
		for(i = 0; i < n; i++){
		    printf("%d ", A2[i]);
	    	}*/
		end61=clock();
		t61=(end61-start61)/CLOCKS_PER_SEC;
		//**************************median pivot 10^5 for sorted array*******************
		start62=clock();
		
		 // After Calling merge shorted on A2 array, The A2 array is sorted now
		 // so call marge sort on A2 itself
		QuickSort_pivot_median(A2,0,n-100000);
		end62=clock();
		t62=(end62-start62)/CLOCKS_PER_SEC;
		//*************************median pivot 10^5 for almost sorted array*******************
		start63=clock();
		n_1_percent=n/100; // 1% of n
		for(i=0;i<n_1_percent;i++)
		{
			temp=rand() % n; 
			A2[temp]=temp;
		}
		QuickSort_pivot_median(A2,0,n-100000);
		end63=clock();
		t63=(end63-start63)/CLOCKS_PER_SEC;
		printf("\nMedian     %f          %f          %f ",t61,t62,t63);
		//*************************median pivot 10^5 for random array element*******************
		start71=clock();
		//initiallization of array 
	    for(i=0;i<n;i++)
	    {
	  		A2[i] = rand() % n; 
		}
		/*printf("\nBefore Sorting the array\n");
		for(i = 0; i < n; i++)
		{
			printf("%d ", A2[i]);
		}
		printf("\n\n\n=================================================================================================\n\n\n\n");
		*/
		QuickSort_random_pivot(A2,0,n-1);  //calling merge sort
		/*
		printf("\nAfter Sorting the array\n");
		for(i = 0; i < n; i++){
		    printf("%d ", A2[i]);
	    	}*/
		end71=clock();
		t71=(end71-start71)/CLOCKS_PER_SEC;
		//*************************median pivot 10^5 for sorted array*******************
		start72=clock();
		
		 // After Calling merge shorted on A2 array, The A2 array is sorted now
		 // so call marge sort on A2 itself
		QuickSort_random_pivot(A2,0,n-1);
		end72=clock();
		t72=(end72-start72)/CLOCKS_PER_SEC;
		//*************************median pivot 10^5 for almost sorted array*******************
		start73=clock();
		n_1_percent=n/100; // 1% of n
		for(i=0;i<n_1_percent;i++)
		{
			temp=rand() % n; 
			A2[temp]=temp;
		}
		QuickSort_random_pivot(A2,0,n-1);
		end73=clock();
		t73=(end73-start73)/CLOCKS_PER_SEC;
		printf("\nMedian    %f          %f          %f ",t71,t72,t73);
		
//###############################10^6 start here ##################################################

		n=pow(10,6);
		int *A3=(int*)malloc(n*sizeof(int)); 
		//**************************first pivot 10^6 for random array element*******************
		start41=clock();
		//initiallization of array 
	    for(i=0;i<n;i++)
	    {
	  		A3[i] = rand() % n; 
		}
		/*printf("\nBefore Sorting the array\n");
		for(i = 0; i < n; i++)
		{
			printf("%d ", A3[i]);
		}
		printf("\n\n\n==================================================\n\n===============================================\n\n\n\n");
		*/
		QuickSort(A3,0,n-1000);  //calling merge sort
		/*
		printf("\nAfter Sorting the array\n");
		for(i = 0; i < n; i++){
		    printf("%d ", A3[i]);
	    	}*/
		end41=clock();
		t41=(end41-start41)/CLOCKS_PER_SEC;
		
		//**************************first pivot 10^6 for sorted array*******************
		start42=clock();
		
		 // After Calling merge shorted on A3 array, The A3 array is sorted now
		 // so call marge sort on A3 itself
		QuickSort(A3,0,n-1000);
		end42=clock();
		t42=(end42-start42)/CLOCKS_PER_SEC;
		
		//**************************first pivot 10^6 for almost sorted array*******************
		start43=clock();
		n_1_percent=n/100,temp; // 1% of n
		for(i=0;i<n_1_percent;i++)
		{
			temp=rand() % n; 
			A3[temp]=temp;
		}
		QuickSort(A3,0,n-1000);
		end43=clock();
		t43=(end43-start43)/CLOCKS_PER_SEC;
		
		printf("\n\n\nFor 10^6:\n");
		printf("\nPivot         Random            sorted        Almost sorted");
		printf("\n\nFirst     %f          %f          %f ",t41,t42,t43);
		//**************************Random pivot 10^6 for random array element******************* 
		start51=clock();
		//initiallization of array 
	    for(i=0;i<n;i++)
	    {
	  		A3[i] = rand() % n; 
		}
		/*printf("\nBefore Sorting the array\n");
		for(i = 0; i < n; i++)
		{
			printf("%d ", A3[i]);
		}
		printf("\n\n\n=================================================================================================\n\n\n\n");
		*/
		QuickSort_random_pivot(A3,0,n-1000);  //calling merge sort
		/*
		printf("\nAfter Sorting the array\n");
		for(i = 0; i < n; i++){
		    printf("%d ", A3[i]);
	    	}*/
		end51=clock();
		t51=(end51-start51)/CLOCKS_PER_SEC;
		
		//**************************Random pivot 10^6 for sorted array*******************
		start52=clock();
		
		 // After Calling merge shorted on A3 array, The A3 array is sorted now
		 // so call marge sort on A3 itself
		QuickSort_random_pivot(A3,0,n-1000);
		end52=clock();
		t52=(end52-start52)/CLOCKS_PER_SEC;
		//**************************Random pivot 10^6 for almost sorted array*******************
		start53=clock();
		n_1_percent=n/100; // 1% of n
		for(i=0;i<n_1_percent;i++)
		{
			temp=rand() % n; 
			A3[temp]=temp;
		}
		QuickSort_random_pivot(A3,0,n-1000);
		end53=clock();
		t53=(end53-start53)/CLOCKS_PER_SEC;
		
		printf("\nRandom     %f          %f          %f ",t51,t52,t53);
		//**************************median pivot 10^6 for random array element*******************
		start61=clock();
		//initiallization of array 
	    for(i=0;i<n;i++)
	    {
	  		A3[i] = rand() % n; 
		}
		/*printf("\nBefore Sorting the array\n");
		for(i = 0; i < n; i++)
		{
			printf("%d ", A3[i]);
		}
		printf("\n\n\n=================================================================================================\n\n\n\n");
		*/
		QuickSort_pivot_median(A3,0,n-1000);  //calling merge sort
		/*
		printf("\nAfter Sorting the array\n");
		for(i = 0; i < n; i++){
		    printf("%d ", A3[i]);
	    	}*/
		end61=clock();
		t61=(end61-start61)/CLOCKS_PER_SEC;
		//**************************median pivot 10^6 for sorted array*******************
		start62=clock();
		
		 // After Calling merge shorted on A3 array, The A3 array is sorted now
		 // so call marge sort on A3 itself
		QuickSort_pivot_median(A3,0,n-1000);
		end62=clock();
		t62=(end62-start62)/CLOCKS_PER_SEC;
		//*************************median pivot 10^6 for almost sorted array*******************
		start63=clock();
		n_1_percent=n/100; // 1% of n
		for(i=0;i<n_1_percent;i++)
		{
			temp=rand() % n; 
			A3[temp]=temp;
		}
		QuickSort_pivot_median(A3,0,n-1000);
		end63=clock();
		t63=(end63-start63)/CLOCKS_PER_SEC;
		printf("\nMedian     %f          %f          %f ",t61,t62,t63);
		//*************************median pivot 10^6 for random array element*******************
		start71=clock();
		//initiallization of array 
	    for(i=0;i<n;i++)
	    {
	  		A3[i] = rand() % n; 
		}
		/*printf("\nBefore Sorting the array\n");
		for(i = 0; i < n; i++)
		{
			printf("%d ", A3[i]);
		}
		printf("\n\n\n=================================================================================================\n\n\n\n");
		*/
		QuickSort_random_pivot(A3,0,n-1000);  //calling merge sort
		/*
		printf("\nAfter Sorting the array\n");
		for(i = 0; i < n; i++){
		    printf("%d ", A3[i]);
	    	}*/
		end71=clock();
		t71=(end71-start71)/CLOCKS_PER_SEC;
		//*************************median pivot 10^6 for sorted array*******************
		start72=clock();
		
		 // After Calling merge shorted on A3 array, The A3 array is sorted now
		 // so call marge sort on A3 itself
		QuickSort_random_pivot(A3,0,n-1000);
		end72=clock();
		t72=(end72-start72)/CLOCKS_PER_SEC;
		//*************************median pivot 10^6 for almost sorted array*******************
		start73=clock();
		n_1_percent=n/100; // 1% of n
		for(i=0;i<n_1_percent;i++)
		{
			temp=rand() % n; 
			A3[temp]=temp;
		}
		QuickSort_random_pivot(A3,0,n-1000);
		end73=clock();
		t73=(end73-start73)/CLOCKS_PER_SEC;
		printf("\nMedian    %f          %f          %f ",t71,t72,t73);
			
		
	
	
	
		
	}
	else if(2==choice)
	{
		clock_t start41,end41,start51,end51,start42,end42,start52,end52,start43,end43,start53,end53,start61,end61,start62,end62,start63,end63,start71,end71,start72,end72,start73,end73;
		float t41,t51,t42,t52,t43,t53,t61,t62,t63,t71,t72,t73;
		int i,n;
		n=pow(10,4);
		int *A1=(int*)malloc(n*sizeof(int)); 
		//**************************10^4 for random array element*******************
		start41=clock();
		//initiallization of array 
	    for(i=0;i<n;i++)
	    {
	  		A1[i] = rand() % n; 
		}
		printf("\nBefore Sorting the array\n");
		for(i = 0; i < n; i++)
		{
			printf("%d ", A1[i]);
		}
		printf("\n\n\n=================================================================================================\n\n\n\n");
		
		MergeSort(A1,n);  //calling merge sort
		
		printf("\nAfter Sorting the array\n");
		for(i = 0; i < n; i++){
		    printf("%d ", A1[i]);
	    	}
	    
		end41=clock();
		t41=(end41-start41)/CLOCKS_PER_SEC;
		
		//**************************10^4 for sorted array*******************
		start42=clock();
		
		 // After Calling merge shorted on A1 array, The A1 array is sorted now
		 // so call marge sort on A1 itself
		MergeSort(A1,n);
		end42=clock();
		t42=(end42-start42)/CLOCKS_PER_SEC;
		
		//**************************10^4 for almost sorted array*******************
		start43=clock();
		int n_1_percent=n/100,temp; // 1% of n
		for(i=0;i<n_1_percent;i++)
		{
			temp=rand() % n; 
			A1[temp]=temp;
		}
		MergeSort(A1,n);
		end43=clock();
		t43=(end43-start43)/CLOCKS_PER_SEC;
		printf("\n\n");
		printf("\nN         Random           sorted           Almost sorted");
		printf("\n10^4     %f          %f          %f ",t41,t42,t43);
		//**************************10^5 for random array element*******************
		n=pow(10,5);
		int *A2=(int*)malloc(n*sizeof(int)); 
		start51=clock();
		//initiallization of array 
	    for(i=0;i<n;i++)
	    {
	  		A2[i] = rand() % n; 
		}
		/*printf("\nBefore Sorting the array\n");
		for(i = 0; i < n; i++)
		{
			printf("%d ", A1[i]);
		}
		printf("\n\n\n=================================================================================================\n\n\n\n");
		*/
		MergeSort(A2,n);  //calling merge sort
		/*
		printf("\nAfter Sorting the array\n");
		for(i = 0; i < n; i++){
		    printf("%d ", A1[i]);
	    	}*/
		end51=clock();
		t51=(end51-start51)/CLOCKS_PER_SEC;
		
		//**************************10^5 for sorted array*******************
		start52=clock();
		
		 // After Calling merge shorted on A2 array, The A1 array is sorted now
		 // so call marge sort on A2 itself
		MergeSort(A2,n);
		end52=clock();
		t52=(end52-start52)/CLOCKS_PER_SEC;
		//**************************10^5 for almost sorted array*******************
		start53=clock();
		n_1_percent=n/100; // 1% of n
		for(i=0;i<n_1_percent;i++)
		{
			temp=rand() % n; 
			A2[temp]=temp;
		}
		MergeSort(A2,n);
		end53=clock();
		t53=(end53-start53)/CLOCKS_PER_SEC;
		
		//**************************10^6 for random array element*******************
		n=pow(10,6);
		int *A3=(int*)malloc(n*sizeof(int)); 
		start61=clock();
		//initiallization of array 
	    for(i=0;i<n;i++)
	    {
	  		A3[i] = rand() % n; 
		}
		/*printf("\nBefore Sorting the array\n");
		for(i = 0; i < n; i++)
		{
			printf("%d ", A1[i]);
		}
		printf("\n\n\n=================================================================================================\n\n\n\n");
		*/
		MergeSort(A3,n);  //calling merge sort
		/*
		printf("\nAfter Sorting the array\n");
		for(i = 0; i < n; i++){
		    printf("%d ", A1[i]);
	    	}*/
		end61=clock();
		t61=(end61-start61)/CLOCKS_PER_SEC;
	
		//**************************10^6 for sorted array*******************
		start62=clock();
		
		 // After Calling merge shorted on A2 array, The A1 array is sorted now
		 // so call marge sort on A2 itself
		MergeSort(A3,n);
		end62=clock();
		t62=(end62-start62)/CLOCKS_PER_SEC;
		//**************************10^6 for almost sorted array*******************
		start63=clock();
		n_1_percent=n/100; // 1% of n
		for(i=0;i<n_1_percent;i++)
		{
			temp=rand() % n; 
			A3[temp]=temp;
		}
		MergeSort(A3,n);
		end63=clock();
		t63=(end63-start63)/CLOCKS_PER_SEC;
			
		//**************************10^7 for random array element*******************
		n=pow(10,7);
		int *A4=(int*)malloc(n*sizeof(int)); 
		start71=clock();
		//initiallization of array 
	    for(i=0;i<n;i++)
	    {
	  		A4[i] = rand() % n; 
		}
		/*printf("\nBefore Sorting the array\n");
		for(i = 0; i < n; i++)
		{
			printf("%d ", A1[i]);
		}
		printf("\n\n\n=================================================================================================\n\n\n\n");
		*/
		MergeSort(A4,n);  //calling merge sort
		/*
		printf("\nAfter Sorting the array\n");
		for(i = 0; i < n; i++){
		    printf("%d ", A1[i]);
	    	}*/
		end71=clock();
		t71=(end71-start71)/CLOCKS_PER_SEC;
		
		//**************************10^7 for sorted array*******************
		start72=clock();
		
		 // After Calling merge shorted on A2 array, The A1 array is sorted now
		 // so call marge sort on A2 itself
		MergeSort(A4,n);
		end72=clock();
		t72=(end72-start72)/CLOCKS_PER_SEC;
		//**************************10^7 for almost sorted array*******************
		start73=clock();
		n_1_percent=n/100; // 1% of n
		for(i=0;i<n_1_percent;i++)
		{
			temp=rand() % n; 
			A4[temp]=temp;
		}
		MergeSort(A4,n);
		end73=clock();
		t73=(end73-start73)/CLOCKS_PER_SEC;

		printf("\n10^5     %f          %f          %f ",t51,t52,t53);
		printf("\n10^6     %f          %f          %f ",t61,t62,t63);
		printf("\n10^7     %f          %f          %f ",t71,t72,t73);
	
		
		
	}
}

void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
	int i,j,k;
	i = 0; j = 0; k =0;

	while(i<leftCount && j< rightCount) {
		if(L[i]  < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}

// Recursive function to sort an array of integers. 
void MergeSort(int *A,int n) {
	int mid,i, *L, *R;
	if(n < 2) return; // base condition. If the array has less than two element, do nothing. 

	mid = n/2;  
	L = (int*)malloc(mid*sizeof(int)); 
	R = (int*)malloc((n- mid)*sizeof(int)); 
	
	for(i = 0;i<mid;i++) L[i] = A[i]; // creating left subarray
	for(i = mid;i<n;i++) R[i-mid] = A[i]; // creating right subarray

	MergeSort(L,mid);  // sorting the left subarray
	MergeSort(R,n-mid);  // sorting the right subarray
	Merge(A,L,mid,R,n-mid);  // Merging L and R into A as sorted list.
        free(L);
        free(R);
}


void swap(int *a, int *b)
{
	int temp; 
	temp = *a;
	*a = *b;
	*b = temp;
}
 

int Partition(int a[], int low, int high)
{
	int pivot, index, i;
	index = low;
	pivot = high;
 
	
	for(i=low; i < high; i++)
	{
		if(a[i] < a[pivot])
		{
			swap(&a[i], &a[index]);
			index++;
		}
	}

	swap(&a[pivot], &a[index]);
 
	return index;
}
 
// Random selection of pivot.
int RandomPivotPartition(int a[], int low, int high)
{
	int pvt, n, temp;
	n = rand();
	// Randomizing the pivot value in the given subpart of array.
	pvt = low + n%(high-low+1);
 
	// Swapping pvt value from high, so pvt value will be taken as pivot while partitioning.
	swap(&a[high], &a[pvt]);
 
	return Partition(a, low, high);
}

int QuickSort_random_pivot(int a[], int low, int high)
{
	int pindex;
	if(low < high)
	{

		pindex = RandomPivotPartition(a, low, high);

		QuickSort(a, low, pindex-1);
		QuickSort(a, pindex+1, high);
	}
	return 0;
}
int QuickSort(int a[], int low, int high)
{
	int pindex;
	if(low < high)
	{
	
		pindex = Partition(a, low, high);
		
		QuickSort(a, low, pindex-1);
		QuickSort(a, pindex+1, high);
	}
	return 0;
}
int partition_pivot_median(int array[], int low, int high) {
	
	int pivot;
	int mid = (low + high) / 2;
	if (array[mid] < array[low]) 
		swap(&array[mid], &array[low]);
	if (array[high] < array[low])
		swap(&array[high], &array[low]);
	if (array[high] < array[mid])
		swap(&array[high], &array[mid]);
	swap(&array[mid], &array[high-1]);
	
	pivot = array[high-1];
 
	return Partition(array, low, high);
}

int QuickSort_pivot_median(int a[], int low, int high)
{
	int pindex;
	if(low < high)
	{
	
		pindex = partition_pivot_median(a, low, high);
		
		QuickSort(a, low, pindex-1);
		QuickSort(a, pindex+1, high);
	}
	return 0;
}
