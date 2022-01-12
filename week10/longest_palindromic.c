#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int longest_palindrom(char str[50],int n)
{
	int i,j,k;
    int maxLength = 1, start = 0;

    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            int flag = 1;

            for (k = 0; k < (j - i + 1) / 2; k++)
                if (str[i + k] != str[j - k])
                    flag = 0;

            if (flag && (j - i + 1) > maxLength) {
                start = i;
                maxLength = j - i + 1;
            }
        }
    }

    printf("Longest palindrome substring is: ");
    for(i=start;i<=start + maxLength - 1;i++)
    {
    	printf("%c",str[i]);
	}
    return maxLength;
}

void main()
{
	char string[50];  
	int len,n,choice;
	
	while(1)
	{
		printf("\n===============================================================");
		printf("\nEnter String: ");
		scanf(" %[^\t\n]s", string);
		
		len=strlen(string);
		n=longest_palindrom(string,len);
		printf("\nlength of longest palindromic is: %d",n);
		
		printf("\n\nDo you want to Run Again (yes-->1 || No-->0): ");
		scanf("%d",&choice);
		if(0==choice)
		{
			exit(0);
		}
	}
	

}








