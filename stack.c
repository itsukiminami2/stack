#include "stack.h"

Stack* create(int member_size, int capacity)
{
    Stack* stack = malloc(sizeof(Stack));           /* allocate space for a new Stack structure. */
    assert(stack);                                  /* check if stack was created successfully. */
    stack->top = -1;                                /* initialize top of stack to -1 to indicate an empty stack. */
    stack->capacity = capacity;
    stack->member_size = member_size;
    stack->elem = malloc(member_size * capacity);   /* allocate enough space for the entire stack. */
    
    return stack;
}

void expand_stack(Stack *stack)
{
    stack->elem = realloc(stack->elem, stack->capacity * 2);
    assert(stack->elem);
    stack->capacity *= 2;
}

int push(Stack *stack, void *elem)
{
    assert(stack);
    assert(elem);

    if(stack->top == stack->capacity - 1)
    {
        expand_stack(stack);
    }
    
    /* if the stack isn't full, increment 'top' and calculate the address at which the new value will be inserted. */
    stack -> top++;
    void *addr = (char*)stack->elem + (stack->top * stack->member_size);
    memcpy(addr, elem, stack->member_size);

    return 0;
}

int pop(Stack *stack, void *dest)
{
    assert(stack);
    assert(dest);

    if(stack->top == -1)
    {
        return 1;
    }

    void* source = (char*)stack->elem + (stack->top * stack->member_size);
    stack->top--;
    memcpy(dest, source, stack->member_size);


    return 0;
}

int top(Stack *stack, void *dest)
{
    assert(stack);
    assert(dest);
    
    if(stack->top == -1)
    {
        return 1;
    }

    void* source = (char*)stack->elem + (stack->top * stack->member_size);
    memcpy(dest, source, stack->member_size);


    return 0;
}

int destroy(Stack *stack)
{
    free(stack->elem);
    free(stack);

    return 0;
}