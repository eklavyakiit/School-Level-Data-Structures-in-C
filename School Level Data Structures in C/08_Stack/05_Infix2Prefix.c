#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    int top;
    int size;
    char *s;
};
void create(struct stack *st, int size){
    st->size = size;
    st->top = -1;
    st->s = (char*)malloc(size*sizeof(char));
}
void push(struct stack *st, int x){
    if(st->top == st->size-1){
        ("stack overflow!!");
    }else{
        st->s[++st->top] = x;
    }
}
char pop(struct stack *st){
    if(st->top == -1){
        printf("Stack empty!!");
    }else{
        return st->s[st->top--];
    }
}
char stackTop(struct stack st){
    if(st.top == -1){
        printf("Stack Empty!!");
    }else{
        return st.s[st.top];
    }
}
int isOperand(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^'||x=='('||x==')')
        return 0;
    return 1;
}
int precedence(char x)
{
    if(x=='+'||x=='-')
        return 1;
    else if(x=='*'||x=='/')
        return 2;
    else if(x=='^')
        return 3;
    return 0;
}

int main()
{
    char infix[]="((A+B)*C-D)/E";
    return 0;
}