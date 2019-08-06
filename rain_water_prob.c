#include <stdio.h>
#include <stdlib.h>

int min(int a,int b)
{
	return a >b ? b: a;
}
int ComputeMaxWater(int *arr, int n)
{
	int *leftarr = (int*) malloc(sizeof(int) *n);
	int *rightarr = (int*) malloc(sizeof(int) *n);
	int sum = 0, i = 0;

	//Calculate left Array
	int leftmax = 0;
	for (int i = 0;i<n;i++)
	{
		if(arr[i] > leftmax)
		{
			leftarr[i] = arr[i];
			leftmax = arr[i];
		}
		else
			leftarr[i] = leftmax;	
	}
	//Calculate right array
	int rightmax = 0;
	for (i = n-1 ;i >= 0 ;i--)
	{
		if(arr[i] > rightmax)
		{
			rightarr[i] = arr[i];
			rightmax = arr[i];
		}
		else
			rightarr[i] = rightmax;	
	}

	for(i = 0; i<n ;i++)
	{
		sum += min(leftarr[i],rightarr[i]) - arr[i];
	}
	return sum;
	
}

int main(void)
{
	int size = 0;
	printf("Enter size of array ");
	scanf("%d",&size);

	int *arr = (int*) malloc(sizeof(int) *size);
	int i = 0;
	while(i<size) {
		printf("Enter the number\n");
		scanf("%d",&arr[i]);
		i++;
	}

	printf("Max water stored is %d\n",ComputeMaxWater(arr,size));
	free(arr);
	return 0;
}
