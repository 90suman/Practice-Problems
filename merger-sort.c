#include<stdio.h>

#define MAX 4294967295

//Merge the arr from position p to q and q+1 to r
void Merge (int arr[], int p, int q, int r)
{
	int n1 = q -p +1;
	int n2 = r - q;
	int leftArr[n1 + 1];
	int rightArr[n2+1];
	int i = 0,j=0,k= 0;
	for(;i<n1;i++)
		leftArr[i] = arr[p+i];
	leftArr[n1] = MAX;

	for (i = 0;i<n2;i++)
		rightArr[i] = arr[q+i+1];
	rightArr[n2] = MAX;
	printf("Left arr\n");	
	for (i = 0;i<n1;i++)
	{
		printf("%d ",leftArr[i]);
	}
	printf("\n");	
	printf("Right arr\n");	
	for (i = 0;i<n2;i++)
	{
		printf("%d ",rightArr[i]);
	}
	printf("\n");	

	i= 0,j = 0;	
	for (k=p;k<r;k++)
	{
		if (leftArr[i] >= rightArr[j])
		{
			arr[k] = rightArr[j];
			j++;
		}
		else  // either left is less or equal to right
		{
			arr[k] = leftArr[i];
			i++;
		}
	}
}


void mergeSort(int arr[], int p , int r)
{
	if (p<r)
	{
		int q = (p+r)/2	;
		mergeSort(arr,p,q);
		mergeSort(arr,q+1,r);
		Merge(arr,p,q,r);
	}
	
}

int main (void)
{
	//int arr[10] = {4,7,2,9,10,34,21,5,20,15};
	int arr[8] = {2,4,5,8,1,3,6,10};
	int size = sizeof(arr)/sizeof(arr[0]);
	int i = 0;
	for (;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\nAfter sorting\n");
	//mergeSort(arr,0,5);
	Merge(arr,0,3,7);
	for (i = 0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");

	return 0;
}
