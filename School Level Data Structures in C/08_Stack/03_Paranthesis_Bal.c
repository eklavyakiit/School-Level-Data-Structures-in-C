#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct stack{
    int size;
    int top;
    char *s;
};

void push(struct stack *st,char x){
    if(st->top==st->size-1){
        printf("Stack Overflow\n");
    }else{
        st->top++;
        st->s[st->top]=x;
    }
}

char pop(struct stack *st){
    char x=-1;
    if(st->top==-1){
        printf("Stack Underflow\n");
    }else{
        x=st->s[st->top];
        st->top--;
    }
    return x;
}

int isEmpty(struct stack *st){
    if(st->top==-1)
        return 1;
    return 0;
}

int isBalance(char *exp){
    struct stack st;
    st.size = strlen(exp);
    st.top = -1;
    st.s = (char *)malloc(sizeof(char)*st.size);

    for(int i = 0; exp[i]!='\0'; i++){
        if(exp[i] == '('){
            push(&st, exp[i]);
        }else if(exp[i] == ')'){
            if(isEmpty(&st)){
                return 0;
            }
            pop(&st);
        }
    }

    return isEmpty(&st)?1:0;
}

int main(){
    char str[] = "((a+b)*(c-d))";

    if(isBalance(str))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}