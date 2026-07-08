#include <stdio.h>
#include<stdlib.h>
#include <string.h>
struct stack{
    int size;
    int top;
    int *s;
};

void create(struct stack *st, int size){
    st->size = size;
    st->top = -1;
    st->s = (char *)malloc(size*sizeof(char));
}
void push(struct stack *st, int x){
    if(st->top == st->size-1){
        printf("Stack Overflow");
    }else{
        st->s[++st->top] = x;
    }
}
char pop(struct stack *st){
    if(st->top==-1){
        printf("Stack Empty");
    }else{
        return st->s[st->top--];
    }
}
char stackTop(struct stack st){
    if(st.top == -1){
        printf("stack empty");
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
    if(x=='*'||x=='/')
        return 2;
    if(x=='^')
        return 3;
    return 0;
}
char *InfixtoPostfix(char *infix){
    struct stack st;
    create(&st, strlen(infix));
    char *postfix = (char*)malloc((strlen(infix) + 1)*sizeof(char));
    int i = 0, j = 0;
    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j++] = infix[i++];
        }else if(infix[i] == '('){
            push(&st, infix[i]);
            i++;
        }else if(infix[i] == ')'){
            while(stackTop(st)!='('){
                postfix[j++] ==pop(&st);
        }
        pop(&st);
        i++;
    }
    else{
        while(st.top!=-1 && precedence(infix[i])>precedence(stackTop(st))){
            push(&st, infix[i++]);
        }
        postfix[j++] = pop(&st);
    }
    postfix[j] = '\0';
    return postfix;
    }
}
int main()
{
    char infix[]="((A+B)*C-D)/E";

    printf("Infix   : %s\n",infix);
    printf("Postfix : %s\n",InfixToPostfix(infix));

    return 0;
}