#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int is_full(struct stack *sp)
{
    if (sp->top == sp->size - 1)
    {
        return 1;
    }
    return 0;
}

int is_empty(struct stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *sp, char character)
{
    if (is_full(sp))
    {
        printf("stack overflow");
    }
    else
    {
        sp->top += 1;
        sp->arr[sp->top] = character;
    }
}
void pop(struct stack *sp)
{
    if (is_empty(sp))
    {
        printf("stack underflow");
    }
    else
    {
        sp->top--;
    }
}

int Parenthesis_match(char *exp)
{
    //initialised a stack structure
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));// initialise structure array to 
    //push '(' this into array and pop out ')' 

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (is_empty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }
    if (is_empty(sp))
    {
        return 1;
    }
    return 0;
}

int main()
{
    char *s = "((8)*(9))";
    if (Parenthesis_match(s))
    {
        printf("Balanced");
    }
    else
    {
        printf("Unbalanced");
    }
    return 0;
}