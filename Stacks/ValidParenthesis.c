#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX_SIZE 100000 

char bracketMap(char ch) {
    switch(ch) {
        case ')': return '(';
        case '}': return '{';
        case ']': return '[';
        default: return '\0'; 
    }
}

bool isValid(char *s) {
    char stack[MAX_SIZE];
    int top = -1; 
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i]; 
        } else {
            if (top == -1 || stack[top] != bracketMap(s[i])) {
                return false;
            } else {
                top--; 
            }
        }
    }
    
    return top == -1; 
}
int main(){
    int TC;
    scanf("%d", &TC);
    for(int i=0;i<TC;i++){
        char str[MAX_SIZE];
        scanf("%s", &str);
        if (isValid(str)) {
            printf("The string has valid brackets.\n");
        } else {
            printf("The string has invalid brackets.\n");
        }

    }
    return 0;
}
