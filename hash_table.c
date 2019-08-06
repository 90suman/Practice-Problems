/*Implements Hash table using chaining*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
	int data;
	struct Node *next;
};

struct HashTable {
	int size;
	struct Node **node;
};

struct Node * CreateNode ()
{
	struct Node *n =  (struct Node*) malloc(sizeof(struct Node));
	return n;
}
void PopulateData (struct HashTable *ht)
{
	int n ;
	printf("Enter no of data to be entered\n");
	scanf("%d",&n);
	for(int i =0; i<n; i++ )
	{
		int data = 0;
		printf("Enter data \n");
		scanf("%d",&data);
		
		struct Node *n = CreateNode();
		n->data = data;
		n->next = NULL;

		int index = data % ht->size ;
		if(ht->node[index] == NULL)
		{
			ht->node[index] = n;
		}
		else 
		{
			struct Node *temp = ht->node[index];
			while(temp->next != NULL)
			{
				temp  = temp->next;
			}
			temp->next = n;
		}
	}
		
}

void DisplayData(struct HashTable *ht) 
{
	for(int i =0; i<ht->size ;i++)
	{
		if (ht->node[i])
		{
			printf("Elements in index %d \n",i);
			struct Node *temp = ht->node[i];
			while(temp)
			{
				printf("%d ---> ",temp->data);
				temp = temp->next;
			}
			printf("\n");
		}
	}
}

int SearchData(int data, struct HashTable *ht)
{
	int index = data % ht->size;
	if(ht->node[index])
	{
		struct Node *temp = ht->node[index];
		while(temp)
		{
			if(temp->data == data)
				return 1;
			else 
				temp = temp->next;
		}
		return -1;
	}
	else
		return -1;
}
int main ()
{
	unsigned int size = 0;
	int search;
	struct HashTable ht;	
	
	printf("Enter size of hash table \n");
	scanf("%d",&size);

	ht.size = size;
	/* Creating a hash table of size and assigning all ptrs to NULL */
	ht.node = (struct Node**) malloc(sizeof(struct Node*) * size);
	for(int i = 0;i <size; i++)
		ht.node[i] = NULL;

	PopulateData(&ht);
	DisplayData(&ht);
	
	printf("Enter element to be searched \n");
	scanf("%d",&search);
	if(SearchData(search,&ht) == 1)
		printf("Element found \n");
	else
		printf("Element Notfound \n");
	return 0;
}
	
	
