#include <stdio.h>


void Swap(int arr[], int i)
{
	int temp = arr[i];
	arr[i] = arr[i+1];
	arr[i+1] = temp;
}
/*After every round, the max element is moved at the last of array.*/
void BubbleSort(int arr[], int size)
{
        for (int round = 0; round < size -1 ;round++)
	{
		int noOfSwap = 0;
		for (int i = 0; i <size-1-round; i++)
		{
			if (arr[i] > arr[i+1])
			{
				Swap(arr,i);
				noOfSwap = 1;
			}
		}
		if (noOfSwap == 0) // Optimization 
			break;
	}
}

int main (void)
{

	int arr[10] = {4,14,6,9,8,10,0,2,1,5};
	int size = sizeof(arr)/sizeof(arr[0]);
	printf("Before sorting numbers are \n");
	for (int i = 0;i <size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	BubbleSort(arr,size);
	printf("Sorted numbers are \n");
	for (int i = 0;i <size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}

	
	
	
