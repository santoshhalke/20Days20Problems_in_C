#include <stdio.h>
#include <stdlib.h>
/*
Day 8 - Multi-dimensional arrays(Matrix arithmatic)
1.Matrix Addition 
2.Matrix Substraction
3.Display matrix
*/

//Function for menu printing
void printMenu(){
    printf("\n*****Menu*****\n");
    printf("\nEnter 0 : To exit\n");
    printf("Enter 1 : To edit A matrix\n"); 
    printf("Enter 2 : To edit B matrix\n");
    printf("Enter 3 : To add both matrix\n");
    printf("Enter 4 : For substracting A-B\n");
    printf("Enter 5 : For substracting B-A\n");
    printf("Enter your choice :");
}

//Showing the matrix 
void showMatrix(int rows, int columns, int **arr){
    // printf("\nYour matrix is :\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}

//Funstion for addition of two matrices
void addMatrix(int **arr1,int rows1,int columns1,int **arr2,int rows2,int columns2){
    //Declaring a matrix for addition 
    int **sum;
    sum = (int **)malloc(rows1 * sizeof(int *));
    for(int i=0; i<rows1; i++){
        sum[i] = (int *)malloc(columns1 * sizeof(int));
    }

    //adding to matrices
    for(int i=-0; i<rows1; i++){
        for(int j=0; j<columns1; j++){
            sum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    //Showing the result of addition 
    printf("\nThe addition matrix is :\n");
    showMatrix(rows1,columns1,sum);
}

//Function for substracting matrix arr2 from arr2
void substractMatrix(int **arr1, int rows1, int columns1, int **arr2, int rows2, int columns2){
    //Declaring a matrix for substraction 
    int **sub;
    sub = (int **)malloc(rows1 * sizeof(int *));
    for(int i=0; i<rows1; i++){
        sub[i] = (int *)malloc(columns1 * sizeof(int));
    }

    //Substracting matrix arr2 from matrix arr1
    for(int i=0; i<rows1; i++){
        for(int j=0; j<columns1; j++){
            sub[i][j] = arr1[i][j] - arr2[i][j];
        }
    }

    //Showing the result of subsatrction 
    printf("\nThe substraction matrix is :\n");
    showMatrix(rows1,columns1,sub);
}

int main(){
    int choice;

    //For first matrix 
    int **arr1,rows1,columns1;
    printf("Enter the rows for A matrix:");
    scanf("%d",&rows1);
    printf("Enter the columns for A matrix:");
    scanf("%d",&columns1);

    //Allocating memory to rows first 
    arr1 = (int **)malloc(rows1 * sizeof(int *));

    //Allocating memory for columns for each row
    for(int i=0; i<rows1; i++){
        arr1[i] = (int *)malloc(columns1 * sizeof(int));
    }

    //Inputting the elements 
    printf("Enter the array elements for A matrix:\n");
    for(int i=0; i<rows1; i++){
        for(int j=0; j<columns1; j++){
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("You entered the A Matrix as:\n");
    showMatrix(rows1, columns1, arr1);

    //For second matrix
    int **arr2,rows2,columns2;
    printf("Enter the rows for B matrix:");
    scanf("%d",&rows2);
    printf("Enter the columns for B matrix:");
    scanf("%d",&columns2);

    //Allocating memory to rows first 
    arr2 = (int **)malloc(rows2 * sizeof(int *));
    //Allocating memory for columns for each row

    for(int i=0; i<rows2; i++){
        arr2[i] = (int *)malloc(columns2 * sizeof(int));
    }
    //Inputting the elements 

    printf("Enter the array elements for B matrix:\n");
    for(int i=0; i<rows2; i++){
        for(int j=0; j<columns2; j++){
            scanf("%d",&arr2[i][j]);
        }
    }
    printf("You entered the B Matrix as:\n");
    showMatrix(rows2, columns2, arr2);
    do{

        printMenu();
        scanf("%d",&choice);
        switch(choice){
            case 0:
                printf("\nExiting...\n");
                break;
            case 1:
                 printf("Enter the array elements for A matrix:\n");
                for(int i=0; i<rows1; i++){
                    for(int j=0; j<columns1; j++){
                        scanf("%d",&arr1[i][j]);
                    }
                }
                printf("You entered the A Matrix as:\n");
                showMatrix(rows1, columns1, arr1);
                break;
            case 2:
                printf("Enter the array elements for B matrix:\n");
                for(int i=0; i<rows2; i++){
                    for(int j=0; j<columns2; j++){
                        scanf("%d",&arr2[i][j]);
                    }
                }
                printf("You entered the B Matrix as:\n");
                showMatrix(rows2, columns2, arr2);
                break;
            case 3:
                if(rows1 == rows2 && columns1 == columns2){
                    addMatrix(arr1,rows1,columns1,arr2,rows2,columns2);
                }
                else{
                    printf("\nAddtion is not possible\n");
                }
                break;
            case 4:
                if(rows1 == rows2 && columns1 == columns2){
                    substractMatrix(arr1,rows1,columns1,arr2,rows2,columns2);
                }
                else{
                    printf("\nSubstraction is not possible\n");
                }
                break;
            case 5:
                if(rows1 == rows2 && columns1 == columns2){
                    substractMatrix(arr2,rows2,columns2,arr1,rows1,columns1);
                }
                else{
                    printf("\nSubstraction is not possible\n");
                }
                break;
            default :
                printf("\nInvalid Choice...\n***Enter valid choice***\n");
        }
    }while(choice);

    //Deallocating the memory for A matrix 
    for (int i = 0; i < rows1 ; i++) {
       free(arr1[i]);
    }
    free(arr1);

    //Deallocating the memory for B matrix
    for (int i = 0; i < rows2 ; i++) {
       free(arr2[i]);
    }
    free(arr2);
    
    return 0;
}