#include <stdio.h>
#include <limits.h>

void decimalToBinary(int value);
void binaryToDecimal();
void decimalToHexadecimal(int value);
void hexadecimalToDecimal();



int main(int argc, char** argv){
    // printf("%d\n",(200*300*400*500)); //results in integer overflow
    unsigned int ui = 100;
    int si = 100;
    printf("unsigned int size: %ld signed int size: %ld\n",sizeof(ui),sizeof(si));
    printf("Maximum value for int: %d\n", INT_MAX);
    printf("Maximum value for long: %ld\n", LONG_MAX);
    printf("Maximum value for short: %d\n", SHRT_MAX);
    printf("Maximum value for unsigned int: %u\n", UINT_MAX);

    int a = 1;
    int bb = a << 30;
    printf("a = %d and b = %d\n",a,bb);

    int* p;
    int b = 10;
    p = &b;
    printf("The address of b is %p\n",&b);
    printf("The pointer variable p resides in address (%p) and holds the address (%p) with the value %d\n",&p,p,*p);

    

}