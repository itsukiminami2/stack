/*
    description  : A generic stack implementation in C.
    author       : Mayank Kumar
    date         : 30-09-2017
*/

#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct
{
    void *elem;        /* a data item */
    int   top;         /* top of stack */
    int   capacity;    /* total no.. of elements in the stack. */
    int   member_size; /* size of each element in the stack. */
} Stack;

/* Forward declarations of stack utility functions. */
Stack *create(int, int);
int push(Stack*, void*);
int pop(Stack*, void*);
void expand_stack(Stack*);
int top(Stack*, void*);
int destroy(Stack*);

#endif
