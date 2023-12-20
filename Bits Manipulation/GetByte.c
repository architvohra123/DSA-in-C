#include<stdio.h>
/*
* getByte - extract byte n from word x
* Examples: getByte(0x12345678, 1)  = 0x56
*Legal ops: ! ~ & ^| + << >>
Max ops: 6
*/
int getByte(int x, int n) {
    int mask= 0b11111111; //size of 1 byte or 8 bits in binary
    return mask&(x>>(n<<3));
}
int main(){
    int x = 0x12345678;
    int n=1;
    printf("the nth byte in x is: %d\n", getByte(x, n));
    return 0;
}