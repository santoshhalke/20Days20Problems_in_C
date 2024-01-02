#include <stdio.h>
//Recursion in c - Fibonacci Sequence 

//Function for getting the nth number in fibonacci series using recursion 
int Fibonacci(int n){
    if(n == 1 || n == 2) {
        return 1;
    }
    else if(n == 0){
        return 0;
    }
    else {
        return Fibonacci(n-1)+Fibonacci(n-2);
    }
}

int main(){
    int number;
    printf("Enter number :");
    scanf("%d",&number);
    //loop for printing the series one by one 
    for(int i=0; i<number; i++){
        printf("%d\t",Fibonacci(i));
    }
    return 0;
}