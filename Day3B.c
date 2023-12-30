// Create a program that parses command-line arguments and performs a specified operation 
// using standard library files like atoi and atof
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Accepts command-line arguments
int main(int argc, char const *argv[]){
    int a,b,choice;
    //Uses command line argument to evalute operation specified
    const char *option = argv[1];
    if(!strcmp(option,"add")){  //Performs addition
        a = atoi(argv[2]);
        b = atoi(argv[3]);
        printf("\nYour addtion is %d...",a+b);
    }
    else if(!strcmp(option,"substract")){ ////Performs substraction 
        a = atoi(argv[2]);
        b = atoi(argv[3]);
        printf("\nYour substraction is %d...",a-b);
    }
    else if(!strcmp(option,"multiply")){ //Performs muliplication
        a = atoi(argv[2]);
        b = atoi(argv[3]);
        printf("\nYour multiplication is %d...",a*b);
    }
    else if(!strcmp(option,"divide")){ //performs division
        a = atoi(argv[2]);
        b = atoi(argv[3]);
        printf("\nYour division is %f...",(float)a/b);
    }
    else{
        printf("Invalid Entry...");
    }
    return 0;
}
