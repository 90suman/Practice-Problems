#include "queue.h"

Queue* CreateQueue(void)
{
	Queue* q = malloc(sizeof(Queue)*1);
	q->front = q->rear = NULL;
	q->size = 0;
	return q;
}

void enque(Queue *q,int data)
{
	struct Node * node  = malloc(sizeof(struct Node)*1);
	node->data = data;
	node->next = NULL;

	if(q->front == NULL)
	{
		q->front = q->rear = node;
		return;
	}
	if(q->rear)
	{
		q->rear->next = node;
	}
	q->rear = node;
	q->size += 1;
	return;		
}

int deque(Queue *q)
{
	int res = -1;
	if(q->front)
	{
		struct Node* temp = q->front;
		q->front = q->front->next;
		res = temp->data;
		q->size  -= 1;
		free(temp);
	}
	return res;
}
void PrintQueue(Queue *q)
{
	struct Node * temp = q->front;
	while(temp)
	{
		printf(" %d \n",temp->data);
		temp = temp->next;
	}
}
int size(Queue *q)
{
	return q->size;
}
