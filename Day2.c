#include <stdio.h>

//Day 2 :Implement a simple calculator using function pointers for basic operations
//Addtion of numbers
int sum(int *a, int *b){
    return (*a)+(*b);
}

//Substraction of numbers
int sub(int *a, int *b){
    return (*a)-(*b);
}

//Division of numbers
float divide(int *a, int *b){
    return (*a)/(*b);
}

//Multiplication of numbers
int multiply(int* a, int* b){
    return (*a)*(*b);
}

int main(){
    int a,b,addition,choice,multiplication,substraction;
    float division;
    do{
        printf("\nEnter two numbers:");
        scanf("%d %d",&a,&b);
        printf("\nEnter 1: For addition\n");
        printf("Enter 2: For substraction\n");
        printf("Enter 3: For divide\n");
        printf("Enter 4: For multiplication\n");
        printf("Enter your choice :");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                //calling sum using reference
                addition = sum(&a,&b);
                printf("Addition is %d",addition);
                break;
            case 2:
                ////calling sub using reference
                 substraction = sub(&a,&b);
                 printf("Substraction is %d",substraction);
                 break;
            case 3:
                ////calling div using reference
                division = divide(&a,&b);
                printf("Division is %d",division);
                break;
            case 4:
                //calling multiply using reference
                multiplication = multiply(&a,&b);
                printf("Multiplication is %d",multiplication);
                break;
            default : 
                printf("Invalide case..\n");
        }
        printf("\nDo you want to continue (0/1) :");
        scanf("%d",&choice);
    }while(choice);
    return 0;
}