// different bracket matching
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 20
struct stack
{
    int size;
    int top;
    char *arr;
};

struct stack *createStack()
{
    struct stack *s = malloc(sizeof(struct stack));
    if (!s)
        return NULL;
    s->size = MAXSIZE;
    s->top = -1;
    s->arr = malloc(MAXSIZE * sizeof(char));
    if (!s->arr)
        return NULL;
    return s;
}

int isEmpty(struct stack *s)
{
    return s->top = -1;
}

int isFull(struct stack *s)
{
    return s->top = MAXSIZE - 1;
}

void push(struct stack *s, char ch)
{
    if (s->top==MAXSIZE-1)
    {
        printf("stack overflow\n");
    }
    else
    {
        s->arr[++s->top] = ch;
        // s->top++;
        // s->arr[s->top]=ch;
    }
}

void pop(struct stack *s)
{
    if (s->top==-1)
    {
        printf("stack underflow\n");
        // return '\0';
    }
    else
    {
        // char c;
        // c = s->arr[s->top];
        s->top--;
        // return c;
    }
}

int isSymbol(char c)
{
    if (c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']')
        return 1;
    else
        return 0;
}

int isOpen(char c)
{
    if (c == '(' || c == '[' || c == '{')
        return 1;
    else
        return 0;
}

int isClose(char c)
{
    if (c == ')' || c == ']' || c == '}')
        return 1;
    else
        return 0;
}
void match(char *ch)
{
    struct stack *s = createStack();
    for (int i = 0; i < strlen(ch); i++)
    {
        if (isSymbol(ch[i]))
        {
            if (isOpen(ch[i]))
            {
                push(s, ch[i]);
                continue;
            }
            else if (isClose(ch[i]))
            {
                // if(isEmpty(s))
                // return 0;
                if (ch[i] == ')')
                {
                    if (s->arr[s->top] == '(')
                    {
                        pop(s);
                    }
                    else
                    {
                        printf("unbalanced\n");
                        break;
                    }
                    // return 0;
                }
                else if (ch[i] == '}')
                {
                    if (s->arr[s->top] == '{')
                    {
                        pop(s);
                    }
                    else
                    {
                        printf("unbalanced\n");
                        // return 0;
                        break;
                    }
                }
                else if (ch[i] == ']')
                {
                    if (s->arr[s->top] == '[')
                    {
                        pop(s);
                    }
                    else
                    {
                        printf("unbalanced\n");
                        // return 0;
                        break;
                    }
                }
            }
        }
    }
    if (s->top==-1)
        printf("balanced\n");
    // return 1;
    else
        printf("unbalanced\n");
    // return isEmpty(s);
}

int main()
{
    // char*c="()";
    char c[MAXSIZE];
    printf("enter the expression:\n");
    scanf("%s", c);
    char *ch = c;
    match(ch);
    // if(match(ch))
    // printf("balanced\n");
    // else
    // printf("unbalanced\n");
    printf("successful\n");
    return 0;
}