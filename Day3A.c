// Create a program that parses command-line arguments and performs a specified operation 
// without using standard library files like atoi and atof
#include <stdio.h>
#include <string.h>

//Function to convert string characters into integer
int toString(const char *num){
    int i,x=0;
    for ( i = 0; num[i] ; i++){
        if(num[i] >= '0' && num[i] <= '9'){
            x = (x*10) + (num[i] - 48);
        }
        else{
            break;
        }
    }
    return x;
}

//Accepts command-line arguments
int main(int argc, char const *argv[]){
    int a,b,choice;
    //Uses command line argument to evalute operation specified
    const char *option = argv[1];
    if(!strcmp(option,"add")){  //Performs addition
        a = toString(argv[2]);
        b = toString(argv[3]);
        printf("\nYour addtion is %d...",a+b);
    }
    else if(!strcmp(option,"substract")){ ////Performs substraction 
        a = toString(argv[2]);
        b = toString(argv[3]);
        printf("\nYour substraction is %d...",a-b);
    }
    else if(!strcmp(option,"multiply")){ //Performs muliplication
        a = toString(argv[2]);
        b = toString(argv[3]);
        printf("\nYour multiplication is %d...",a*b);
    }
    else if(!strcmp(option,"divide")){ //performs division
        a = toString(argv[2]);
        b = toString(argv[3]);
        printf("\nYour division is %f...",(float)a/b);
    }
    else{
        printf("Invalid Entry...");
    }
    return 0;
}
