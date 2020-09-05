#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
        struct Node *next;
        int data;
}Node_t;

typedef struct Stack {
        int size;
        Node_t *top;
}Stack_t;

Stack_t * CreateStack ();
void push (Stack_t *, int );
int pop(Stack_t *);
int peek(Stack_t *);
int IsEmpty(Stack_t *);
int GetSize(Stack_t *);
void PrintStack(Stack_t *);
