#include<stdio.h>

/*Start from index 1, left side is already sorted, pick an element from right array sequentially,
compare with sorted list to find correction location for insertion*/
void insertionSort(int arr[], int size)
{
	int i = 1,j = 0;
	for (;i<size;i++)
	{
		j = i-1;
		int temp = arr[i];
		while(j > -1 && arr[j] > temp)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
}

int main (void)
{
	int arr[] = {9,8,7,6,5,4,3,2,1,0};
	int size = sizeof(arr)/sizeof(arr[0]);
	printf("Before Sorting\n");
	for (int i = 0;i< size;i++)
		printf("%d ",arr[i]);

	printf("\nAfter Sorting\n");
	insertionSort(arr,size);
	for(int i = 0;i<size;i++)
		printf("%d ",arr[i]);

	printf("\n");
	return 0;
}
		

	
