#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100
typedef struct{
          int top;
          int items[MAX_SIZE];
}stack;

void push(stack *s,int value){
    if(s->top==MAX_SIZE){
        printf("stack overflow\n");
    }
    else{
        s->items[(++(s->top))]=value;
    }
}

int pop(stack *s){
    if(s->top==-1){
        printf("stack underflow\n");
        return -1;
    }
    else{
        return s->items[(s->top)--];
    }
}


int evaluatepostfix(char *exp){
    stack s;
    s.top = -1;
    int num = 0;
    for (int i = 0; exp[i] != '?'; i++) {
        if (exp[i] == ' ') {
            if (num != 0) {
                push(&s, num);
                num = 0;
            }
        } else if (isdigit(exp[i])) {
            num = num * 10 + (exp[i] - '0');
        } else {
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            switch (exp[i]) {
                case '+':
                    push(&s, operand1 + operand2);
                    break;
                case '-':
                    push(&s, operand1 - operand2);
                    break;
                case '*':
                    push(&s, operand1 * operand2);
                    break;
                case '/':
                    push(&s, operand1 / operand2);
                    break;
            }
        }
    }
    return pop(&s);
}

int main() {
    char exp[MAX_SIZE]="31 4 50 + * ?";
   
    int result = evaluatepostfix(exp);
    printf("Result: %d\n", result);
    return 0;
}