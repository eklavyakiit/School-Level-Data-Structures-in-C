#include <stdio.h>
#include <stdlib.h>
struct stack{
    int size;
    int top;
    int *s;
};
void push(struct stack *st, int x){
    if(st->top == st->size-1){
        printf("Stack Overflow!");
    }else{
        st->top++;
        st->s[st->top] = x;
    }
}
int pop(struct stack *st){
    int x = -1;
    if(st->top == -1){
        printf("Stack Empty!");
    }else{
        x = st->s[st->top];
        st->top--;
    }
    return x;
}
void display(struct stack st){
    for(int i = st.top; i>=0; i--){
        printf("%d ", st.s[i]);
    }
    printf("\n");
}
int peek(struct stack st, int pos){
    int x = -1;
    if((st.top) - pos + 1 < 0){
        printf("Invalid Position!");
    } else{
        x = st.s[st.top - pos + 1];
        return x;
    }
}
int main(){
    struct stack st;
    printf("Enter size of stack: ");
    scanf("%d", &st.size);
    st.top = -1;
    st.s = (int *)malloc(st.size*(sizeof(int)));
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);
    push(&st, 60);
    display(st);
    pop(&st);
    display(st);
}