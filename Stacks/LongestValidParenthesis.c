#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestValidParentheses(char *s){
    int maxl=0;
    int n=strlen(s);
    int stack[n+1];
    int top=-1;
    stack[++top]=-1;

    for(int i=0;i<n;i++){
        if(s[i]=='('){
            stack[++top]=i;
        }
        else{
            if(top>0){
                top--;
                maxl=(i-stack[top])>maxl ? (i-stack[top]) : maxl;
            }
            else{
                stack[0]=i;
            }
        }
    }
    return maxl;
}

int main() {
    char str[10000];
    scanf("%s", &str);
    printf("%d\n", longestValidParentheses(str)); 
    return 0;
    }