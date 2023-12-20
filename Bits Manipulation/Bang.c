#include<stdio.h>
/* bang - Compute !x without using !
*  Examples: bang(3)=0, bang(0)=1
*  Legal ops: ~ & ^ | + << >>
*  Max ops: 12
*/ 
int bang(int x) {
    return ((x | (~x + 1)) >> 31) + 1;  //get 2s comp of x and | it with x , it will give  negative if not zero
}
int main(){
    int n=3;
    printf("Bang of n is: %d\n", bang(n));
    return 0;
}