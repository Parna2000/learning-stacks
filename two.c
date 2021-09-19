// infix to postfix conversion
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
struct stack{
    int size;
    int top;
    char*arr;
};

struct stack* createStack(){
    struct stack*s=malloc(sizeof(struct stack));
    if(!s)
    return NULL;
    s->size=MAX;
    s->top=-1;
    s->arr=malloc(MAX*sizeof(struct stack));
    if(!s->arr)
    return NULL;
    return s;
}

void push(struct stack*s,char c){
    if(s->top==MAX-1){
        printf("stack overflow\n");
    }
    else{
        s->top++;
        s->arr[s->top]=c;
    }
}

char pop(struct stack*s){
    if(s->top==-1){
        printf("stack underflow\n");
        return '\0';
    }
    else{
        char c;
        c=s->arr[s->top];
        s->top--;
        return c;
    }
}

int isOperand(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')'){
        return 0;
    }
    else
    return 1;
}

int isOperator(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'){
        return 1;
    }
    else
    return 0;
}

int precedence(char c){
    if(c=='*'||c=='/')
    return 3;
    else if(c=='+'||c=='-')
    return 2;
    else 
    return 0;
}

char* infixToPostfix(char*infix){
    struct stack*s=createStack();
    char* postfix=malloc((strlen(infix)+1)*sizeof(char));
    int j=0,i=0;
    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else if(isOperator(infix[i])){
            while(precedence(s->arr[s->top])>=precedence(infix[i])&&s->arr[s->top]!='('&&s->top!=-1){
                postfix[j]=pop(s);
                j++;
            }
            push(s,infix[i]);
            i++;
        }
        else if(infix[i]=='('){
            push(s,infix[i]);
            i++;
        }
        else if(infix[i]==')'){
            while(s->arr[s->top]!='('){
                postfix[j]=pop(s);
                j++;
            }
            char c= pop(s);
            i++;
        }

    }
    while(s->top!=-1){
        postfix[j]=pop(s);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}

int main(){
    char infix[MAX];
    printf("Enter the infix expression:\n");
    scanf("%s",infix);
    char*i=infix;
    char*postfix=infixToPostfix(i);
    printf("The postfix expression is:\n");
    printf("%s\n",postfix);
    printf("success!!\n");
    return 0;
}
