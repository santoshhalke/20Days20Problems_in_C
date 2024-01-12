#include <stdio.h>
#include <stdlib.h>
static int front=-1,rear=-1;

//function for printing menu 
void printMenu(){
    printf("\n*****MENU*****\n");
    printf("\nEnter 0 : To exit...\n");
    printf("Enter 1 : To enqueue\n");
    printf("Enter 2 : TO dequeue\n");
    printf("Enter 3 : To view the queue\n");
    printf("Enter your choice :");
}

//To check if queue is full
int isFull(int size){
    if(size-1 == rear){
        return 1;
    }
    else{
        return 0;
    }
}

//To check if queue is empty
int isEmpty(){
    if(front==-1 || front>rear){
        return 1;
    }
    else {
        return 0;
    }
}

//To add a element into queue
void enqueue(int *array,int size){
    if(isFull(size)){
        printf("\nQueue is full..\n");
        return;
    }
    int element;
    printf("\nEnter element you want to enqueue :");
    scanf("%d",&element);
    if(front == -1){
        front++;
    }
    rear++;
    array[rear] = element;
    printf("%d added to queue\n",element);
    return;
}

//To delete a element from queue
void dequeue(int *array, int size){
    if(isEmpty()){
        printf("\nQueue is empty can't delete..\n");
        return;
    }
    int element = array[front];
    front++;
    printf("\n%d deleted from queue\n",element);
    return;
}

//To view the queue
void viewQueue(int *array, int size){
    if(isEmpty()){
        printf("\nQueue is empty..\n");
        return;
    }
    printf("\nQueue is :");
    for(int i=front; i<=rear; i++){
        printf("\t%d",array[i]);
    }
}

//Driver code
int main(){
    int *array,size,choice;
    printf("Enter approx length of array :");
    scanf("%d",&size);
    array = (int *)malloc(size * sizeof(int));
    do{
        printMenu();
        scanf("%d",&choice);
        switch(choice){
            case 1:
                enqueue(array,size);
                break;
            case 2:
                dequeue(array,size);
                break;
            case 3:
                viewQueue(array,size);
                break;
            default:
                printf("\nInvalid choice...\n***Enter valid choice***\n");
        }
    }while(choice);
    free(array);
    return 0;
}