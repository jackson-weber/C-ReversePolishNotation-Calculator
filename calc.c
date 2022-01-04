#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "calc.h"

Stack * initialize() {
    Stack * s = malloc (sizeof(Stack));
    s->top = NULL;
    return s;
}

Node * cons(float val, Node * list) {
    //Allocate the new node
    Node * newNode = malloc(sizeof(Node));
    //Set up the value
    newNode->val = val;
    //The new node points to the old list
    newNode->next = list;
    //return a pointer to the new node
    return newNode;
}

Node * removeFirst(Node * list) {
    if (list == NULL) return NULL; //empty list; nothing to remove
    
    Node * restOfList = list->next;
    free(list);
    return restOfList;
}

bool isEmpty(Stack * s) {
    return s->top == NULL;
}

void push(Stack * s, float key) {
    s->top = cons(key, s->top);
}

float peek(Stack * s) {
    if (isEmpty(s)) {
        freeStack(s);
        return EXIT_FAILURE;
    }
    
    return s->top->val;
}

float pop(Stack * s) {
    if (isEmpty(s)) {
        freeStack(s);
        return EXIT_FAILURE;
    }
    
    float retval = peek(s);
    s->top = removeFirst(s->top);
    
    return retval;
}

void freeStack(Stack * s) {
    while (!isEmpty(s)) {
        pop(s);
    }
    free(s);
}

bool checkint (float num)
{
    if ((num >= 0) && (num <= 9))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool checkop (char c)
{
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
        default:
            return false;
    }
}

float eval(Stack * s, char op)
{
    float ans, temp;

    switch (op) {
        case '+': 
            ans = pop(s) + pop(s);
            break;
        case '*':
            ans = pop(s) * pop(s);
            break;
        case '-':
            temp = pop(s);
            ans = pop(s) - temp;
            break;
        case '/':
            temp = pop(s);
            ans = pop(s) / temp;
            break;
    }

    return (ans);
}

bool readData(Stack * s, FILE * fptr)
{
    float c;
    char op;
    char input[256];
    fgets(input, 256, fptr);

    char * token = strtok(input, " ");
    
    while (token != NULL)
    {
        c = atof(token);

        if (c)
        {
            push(s, c);
        }
        else if (token[0] == '-' && token[1] == '0' && token[2] == '\0') //check for -0
        {
            push(s, c);
        }
        else
        {
            op = token[0];
            if (s -> top -> next == NULL)
            {
                return false;
            }
            push(s, eval(s, op));
        }

        token = strtok(NULL, " ");
    }

    return true;
}

#ifndef TEST_STACK
int main (int argc, char ** argv) {
	if (argc != 2) {
		fprintf(stderr, "Incorrect number of arguments.\n");
		fprintf(stderr, "Usage: ./pa11 <input file>\n");		
        return EXIT_FAILURE;
	}

    FILE * fptr;
    fptr = fopen(argv[1], "r");

    if (fptr == NULL)
    {
        return EXIT_FAILURE;
    }

    fseek(fptr, 0, SEEK_END); // goto end of file
    if (ftell(fptr) == 0) //check if file is empty
    {
        fclose(fptr);
        return EXIT_FAILURE;
    }
    fseek(fptr, 0, SEEK_SET); // goto beginning of file

    Stack * s = initialize();

    bool retval = readData(s, fptr);

    fclose(fptr);

    if ((!retval) || (s->top->next != NULL))
    {
        freeStack(s);
        return EXIT_FAILURE;
    }

	float result = peek(s); //store the result of your calculation here.
	
	printf("%f\n", result);

    freeStack(s);

	return EXIT_SUCCESS;
}
#endif