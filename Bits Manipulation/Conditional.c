#include<stdio.h>
/*
* conditional - same as x ? y : z
* example conditional (2, 4, 5) = 4
* ! ~ & ^ | + << >>
* Max ops: 16
*/
int conditional(int x, int y, int z) {
    int mag=(!!x)-1;      //will be 0  if x is 0 and 1 otherwise;
    return (y & ~mag) | (z & mag);
}
int main(){
    int x=2;
    int y=4;
    int z=5;
    printf("conditional of x gives: %d\n", conditional(x,y,z));
}
