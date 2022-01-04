#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node
{
    float val;
    struct Node * next;
} Node;
 
typedef struct Stack {
    Node * top; //top of the stack. If it points to NULL, the stack is empty
} Stack;

Stack * initialize(); //Initializes stack

Node * cons(float val, Node * list); //Adds new node to stack

Node * removeFirst(Node * list); //removes first node from stack

bool isEmpty (Stack * s); //checks if stack is empty

void push(Stack * s, float key); //pushes node onto top of stack

float peek(Stack * s); //returns value of top node of stack

float pop(Stack * s); //pops top node off stack and returns its value

void freeStack(Stack * s); //frees the whole stack

bool checkint(float num);

bool checkop(char c);

float eval(Stack * s, char op);

bool readData(Stack * s, FILE * fptr);