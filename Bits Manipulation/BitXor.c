#include <stdio.h>
int bitXor(int x, int y){
    int n1 = ~(x&y);
    int n2 = ~(~x & ~y);
    return (n1&n2);
}
int main(){
    int x=3;
    int y=6;
    printf("x^y is: %d \n", bitXor(x,y));
    return 0;
}