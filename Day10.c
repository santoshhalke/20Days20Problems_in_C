#include <stdio.h>
/*
Day 10 - Bitwise Operations in c
1)bitwise AND(&)
2)bitwise OR(|)
3)Left shift(<<)
4)Right shift(>>)
5)XOR(^)
6)Bitwise not(~)
*/

int main(){
    //Bitwise AND
    int a=10,b=20;
    int result = a&b;
    printf("\nBitwise AND operation result : %d\n",result);

    //Bitwise OR
    a=10,b=20;
    result = a|b;
    printf("Bitwise OR operation result : %d\n",result);

    //left shift - multiplies 2 raised power no of shift bits
    a=10,b=20;
    result = a<<1;
    printf("Left shift operation result : %d\n",result);

    //Right shift - divides 2 raised power no of shift bits
    a=10,b=20;
    result = a>>1;
    printf("Right shift operation result : %d\n",result);

    //XOR - It will result in 1 if and only if one of two bit is 1
    //XOR could be used for swapping two numbers 
    a=10,b=20;
    result = a^b;
    printf("XOR operation result : %d\n",result);

    //Bitwise not will change bit opposite to it
    a=10,b=20;
    result = ~a;
    printf("Bitwise not operation result : %d\n",result);

    return 0;
}