// peek operation in stack
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
struct stack{
    int size;
    int top;
    char*arr;
};

struct stack* CreateStack(){
    struct stack*s=malloc(sizeof(struct stack));
    if(!s)
    return NULL;
    s->size=MAXSIZE;
    s->top=-1;
    s->arr=malloc(s->size*sizeof(char));
    if(!s->arr)
    return NULL;
    return s;
}

int isEmpty(struct stack*s){
    return (s->top==-1);
}

int isFull(struct stack*s){
    return (s->top==s->size-1);
}

void push(struct stack*s,char data){
    if(isFull(s))
    printf("stackoverflow\n");
    else
    s->arr[++s->top]=data;
}

char pop(struct stack*s){
    if(isEmpty(s)){
        printf("stack underflow\n");
        return '\0';
    }
    else{
        return (s->arr[s->top--]);
    }
}

char peek(struct stack*s,int i){
    int id=s->top-i+1;
    if(id<0){
        printf("invalid index\n");
        return '\0';
    }
    else{
        return s->arr[id];
    }
}

int match(char*arr){
    struct stack*s=CreateStack();
    for (int i = 0; arr[i]!='\0'; i++)
    {
        if(arr[i]=='('){
            push(s,'(');
        }
        else if(arr[i]==')'){
            if(isEmpty(s))
            return 0;
            else{
                pop(s);
            }
        }
    }
    if(isEmpty(s))
    return 1;
    else
    return 0;
}

int main(){
    // struct stack*s=CreateStack();
    // push(s,23);
    // push(s,21);
    // push(s,22);
    // push(s,24);
    // push(s,25);
    // push(s,26);
    // push(s,27);
    // push(s,28);
    // push(s,29);
    // push(s,20);
    // push(s,23);
    // printf("%d\n",peek(s,8));
    char*arr="(a+(g*(h+y))";
    if(match(arr))
    printf("matched\n");
    else
    printf("not matched\n");
    printf("successful\n");
    return 0;
}