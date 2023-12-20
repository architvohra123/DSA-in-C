#include<stdio.h>
/*
* sign - return 1 if positive, 0 if zero, and -1 if negative
* Examples: sign(130) = 1, sign(-23) = -1
* Legal ops: ! ~ & ^ | + << >>
* Max ops : 10
*/
int sign(int x) {
   //TODO
    int sign=x>>31; //will be -1 if x is neg and 0 otherwise
    int mag=(!!x);  //will be 0 if x is 0 and 1 other wise
    return sign|mag;
}
int main(){
    int n = 67;
    printf("sign of n is %d\n", sign(n));
    return 0;
}