#include<stdio.h>

void Swap(int *a,int *b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}


void Print(int *arr,int size)
{
	for (int i = 0; i<size;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

//Partition the arr from 
int Partition (int arr[], int p, int r)
{
	int pivot = arr[r];
	int i = p-1;
	int j = p;
	for(j = p ; j <= r-1; j++)
	{
		if(arr[j] < pivot)
		{
			i++;
			Swap(&arr[i],&arr[j]);
		}
	}
	Swap(&arr[i+1],&arr[r]);
	Print(arr,r-p);
	return i+1;
}


void QuickSort(int arr[], int p , int r)
{
	if (p<r)
	{
		int q = Partition(arr,p,r);
		QuickSort(arr,p,q-1);
		QuickSort(arr,q+1,r);
	}
	
}

int main (void)
{
	int arr[10] = {10,9,8,7,6,5,4,3,2,1};
	int size = sizeof(arr)/sizeof(arr[0]);
	int i = 0;
	for (;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	QuickSort(arr,0,size-1);
	printf("\nAfter sorting\n");
	for (i = 0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");

	return 0;
}
