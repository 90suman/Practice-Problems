#include "stack_ll.h"


Stack_t *CreateStack ()
{
	Stack_t *s1 = (Stack_t*)malloc(sizeof(Stack_t)*1);
	s1->top = NULL;
	s1->size = 0;

	return s1;
}

void push(Stack_t *s1, int data)
{
	if( !s1) {
		printf("Error: No stack created \n");
		return;
	}

	Node_t *node = (Node_t *) malloc(sizeof(Node_t)*1);
	node->data = data;
	Node_t *temp = s1->top;
	s1->top = node;
	node->next = temp;
	s1->size += 1;
	printf("Item pushed %d\n",data);
}

int pop (Stack_t *s1)
{
	if( !s1) {
		printf("Error: No stack created \n");
		return -1;
	}
	if (s1->size == 0) {
		printf("Error : Stack is empty ");
		return -1;
	}

	Node_t *temp = s1->top;
	int res = temp->data;
	s1->top = s1->top->next;
	s1->size -= 1;
	free(temp);
	printf("Item popped %d\n",res);
	return res;
}

int peek (Stack_t *s1)
{
	if( !s1) {
		printf("Error: No stack created \n");
		return -1;
	}
	if (s1->size == 0) {
		printf("Error : Stack is empty \n");
		return -1;
	}
	return s1->top->data;
}

void PrintStack (Stack_t *s1)
{
	
	if( !s1) {
		printf("Error: No stack created \n");
		return;
	}
	if (s1->size == 0) {
		printf("Error : Stack is empty  Nothing to print\n");
		return;
	}
	Node_t *temp = s1->top;
	printf("Stack: \n");
	while (temp != NULL)
	{
		printf("\t %d \n",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int IsEmpty(Stack_t *s)
{
	if(s && s->size >0 )
		return 0;
	return 1;
}

int GetSize (Stack_t *s)
{
	if (s)
		return s->size;
	else
		return -1;
}
