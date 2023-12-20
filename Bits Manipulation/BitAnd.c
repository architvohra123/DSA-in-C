#include<stdio.h>

/*
/*  bitAnd - x & y using only ~ and |
/* Example bitAnd(6, 5) = 4
/* Legal ops:  ~ |  
/*Max ops: 8
*/
int bitAnd (int x, int y) {
    return ~(~x | ~y);
}



int main(){
    int x=5;
    int y=6;
    printf("x&y is: %d \n", bitAnd(x,y));
    return 0;
}