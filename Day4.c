//Use macros to create a generic swap function that works for any data type.
#include <stdio.h>
#define int float //macro to swap integer with float 
#define char double //macro to swap float with double 

int main(){
    int number;  // swaps integer with float
    number = 1.23;  //assingment doesnot throw an error as integer is replaced with float
    printf("The value number is %f",number);  //Successfully prints the float value 
    char number2; //swaps character with double 
    number2 = 1200000; //assingment doesnot throw an error as character is replaced with double
    printf("\nThe value number2 is %lf",number2);//Successfully prints the double value 
    return 0;
}