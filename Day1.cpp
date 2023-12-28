//Day 1: Write a program that swaps two integers using pointers

#include <stdio.h>

//Function getting refernce call and swapping number
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int a,b;

    //User input 
    printf("Enter two numbers :");
    scanf("%d %d",&a,&b);

    //Values before swapping 
    printf("Values before swapping are :\n");
    printf("a=%d,b=%d",a,b);

    //Using call by refernce 
    swap(&a,&b);

    //Values after swapping using pointer 
    printf("\nValues after swapping are :\n");
    printf("a=%d,b=%d",a,b);

    return 0;
}