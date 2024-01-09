#include <stdio.h>
#include <stdlib.h>
static int top=-1;
//Stack Implementation using array

//Function to print menu
void printMenu(){
    printf("\n*****MENU*****\n");
    printf("\nEnter 0 : To exit...\n");
    printf("Enter 1 : To push element in stack\n");
    printf("Enter 2 : TO pop element\n");
    printf("Enter 3 : To view the stack\n");
    printf("Enter your choice :");
}

//Function to check to if stack is empty
int isEmpty(int size){
    if(top == -1){
        return 1;
    }
    else {
        return 0;
    }
}

//Function to check if stack is full
int isFull(int size){
    if(size-1 == top){
        return 1;
    }
    else {
        return 0;
    }
}

//Function to pop element from stack
int popElement(int *array, int size){
    if(isEmpty(size)){ //to Check stack is empty
        printf("\nStack underflow..\n");
        return -1;
    }
    else {
        int temp=array[top];
        top--;
        return temp;
    }
}

//Function to push element to the stack
int pushElement(int *array, int size, int element){
    if(isFull(size)){ //to Check if stack is full
        printf("\nStack Overflow...\n");
        return 0;
    }
    else {
        top++;
        array[top] = element;
        return 1;
    }
}

//Function to display the stack
void viewStack(int *array, int size){
    if(isEmpty(size)){
        printf("\nStack is empty..\n");
    }
    else {
        printf("Your stack is :");
        for(int i=0; i<=top; i++){
            printf("\t%d",array[i]);
        }
    }
}

int main(){
    int *array,size,choice,element;
    printf("Enter approx size of array :");
    scanf("%d",&size);
    array = (int *)malloc(size * (sizeof(int)));
    do{
        printMenu();
        scanf("%d",&choice);
        switch(choice){
            case 0:
                printf("Exiting...\n");
                break;
            case 1:
                printf("Enter element to push :");
                scanf("%d",&element);
                if(pushElement(array,size,element)){
                    printf("Element %d pushed successfully..\n",element);
                }
                else{
                    printf("Pushing element %d failed...\n",element);
                }
                break;
            case 2:
                element = popElement(array,size);
                if(element != -1){
                    printf("The element %d is popped.\n",element);
                }
                else {
                    printf("Unable to pop element..\n");
                }
                break;
            case 3:
                viewStack(array,size);
                break;
            default:
                printf("\nInvalid choice...\n***Enter valid choice***\n");
        }
    }while(choice); //if choice=0 then will exit 
    free(array);
    return 0;
}