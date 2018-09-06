#include <stdio.h>

void Swap (int arr[], int i);

int main (void)
{

	int arr[5];
	int i = 0;
	do
	{
		printf ("Input %d number \n",i+1);
		scanf("%d",&arr[i]);
	}while(++i < 5);

	int round = 0;
	int size = sizeof(arr)/sizeof(arr[0]);

        for (round = 0; round < size -1 ;round++)
	{
		int noOfSwap = 0;
		printf("Iterating for %d time\n",round+1);
		for (int i = 0; i <size-1-round; i++)
		{
			if (arr[i] > arr[i+1])
			{
				Swap(arr,i);
				noOfSwap++;
			}
		}
		if (noOfSwap == 0)
			break;
	}
	printf("Sorted numbers are \n");
	for (int i = 0;i <size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void Swap(int arr[], int i)
{
	int temp = arr[i];
	arr[i] = arr[i+1];
	arr[i+1] = temp;
}
	
	
	
