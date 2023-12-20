#include<stdio.h>
/* logicalShift - shift x to the right by n, using a logical shift
*  can assume that 0 <=n<=31
* examples: logicalShift(0x87654321, 4) = 0x8765432
*  Legal ops:  ~ & ^ | + << >>
*Max ops: 20
*/
int logicalShift(int x, int n) {
    int mask=~(-1<<(32-n));
    return (x>>n)&mask;    
}


int main(){
    int x=0x87654321;
    int n=4;
    printf("logical shift after n bits to right x becomes: %x\n", logicalShift(x,n));
    return 0;
}