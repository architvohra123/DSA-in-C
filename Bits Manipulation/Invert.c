#include<stdio.h>

/* 
/* Return x with the n bits that begin at position p inverted (i.e. turn 0 /* into 1 and vice versa)
/* and the rest left unchanged. Consider the indices of x to begin with the /* lower -order bit   numbered
/* Legal ops: ~ & ^ | << >>
/* as zero
*/
int invert (int x, int p, int n) {
    //TODO
    int mask = ((1 << n) - 1) << p;
    return x ^ mask;
}

int main(){
    int x=9;
    int p=1;
    int n=2;
    printf("Invert of x starting from pth bit upto n bits is : %d\n", invert(x,p,n));
    return 0;
}