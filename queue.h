#include<stdio.h>
#include<stdlib.h>


struct Node {
        int data;
        struct Node* next;
};
typedef struct {
	int size;
        struct Node* front;
        struct Node* rear;
}Queue;

void enque(Queue *q,int data);
int deque(Queue *q);
int size(Queue *q);
Queue* CreateQueue(void);

