#include<stdio.h>

/*
/*  bitOr - x | y using only ~ and &
/* Example bitOr(6, 5) = 7
/* Legal ops:  ~ &  
/*Max ops: 8
*/
int bitOr (int x, int y) {
    return ~(~x & ~y);
}



int main(){
    int x=5;
    int y=6;
    printf("x|y is: %d \n", bitOr(x,y));
    return 0;
}