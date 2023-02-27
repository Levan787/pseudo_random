#include <stdio.h>

extern unsigned long lfsr32C(unsigned long seed);
extern unsigned long lfsr32A(unsigned long seed);

void printBits(unsigned long n){
    for(int i=0;i<32;i++){
        printf("%d",getBit(n,i));
    }
    printf("\n");
}

int main()
{

    long int num;
    num = lfsr32C(0x5AA5FF00);

    printf("Output of c generator\n");

    for(int i=0;i<10;i++){
        num = lfsr32C(0);
        printBits(num);
    }

    num = lfsr32A(0x5AA5FF00);

    printf("\n\n\n\nOutput of asm generator\n");

    for(int i=0;i<10;i++){
        num = lfsr32A(0);
        printBits(num);
    }

    return 0;
}
