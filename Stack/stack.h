#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct node
{
    void *data;
    struct node *next;
} node;

typedef struct stack
{
    node *top;
} stack;

static inline void createStack(stack *s)
{
    s->top = NULL;
}

static inline void Push(stack *s, void *data)
{
    node *new_node;

    new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

static inline void *Pop(stack *s)
{
    node *stack_top;
    void *x;

    if (s->top == NULL)
        return NULL;
    stack_top = s->top;
    s->top = s->top->next;
    x = stack_top->data;
    free(stack_top);
    return x;
}

static inline void *Peek(stack s, int pos)
{
    node *p;

    p = s.top;
    for (int i = 1; i < pos; i++)
        p = p->next;
    if (p)
        return p->data;
    else
        return NULL;
}

static inline void *StackTop(stack s)
{
    if (s.top)
        return s.top->data;
    return NULL;
}

static inline int isEmpty(stack s)
{
    if (s.top)
        return 0;
    return 1;
}

static inline int isFull()
{
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL)
        return 1;
    free(new_node);
    return 0;
}

#endif /* STACK_H */
