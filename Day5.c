// Develop a program to handle file I/O operations using c language
#include <stdio.h>
#include <string.h>

//Function for printing menu
void printMenu(){
    printf("\n***** MENU ***** \n");
    printf("Enter 1 : Reading the File\n");
    printf("Enter 2 : Writing in the File\n");
    printf("Enter 3 : To exit...\n");
    printf("Enter your choice :");
}

int main(){
    int choice;
    char content[100];
    do{
        FILE *ptr = NULL;
        printMenu();
        scanf("%d",&choice);
        switch(choice){
            case 1: 
                /*
                Case for reading the file but 
                it reads only single word 
                till first white space
                */
                ptr = fopen("temp.txt","r");
                if(ptr == NULL) {
                    printf("File Not Found..");
                }
                else {
                    fscanf(ptr,"%s",content);
                    printf("The content is :\t%s",content);
                    fclose(ptr);
                }
                break;
            case 2:
                /*
                Case for writing in the file 
                it will write on the next line every time
                as it opened in the append mode
                */
                printf("Enter your string :");
                ptr = fopen("temp.txt","a");
                scanf("%s",&content);
                fprintf(ptr,"\n%s",content);
                fclose(ptr);
                break;
            case 3: //Case to exit the loop 
                printf("\nExiting...");
                break;
            default : //For invalid input 
                printf("Invalid choice...!\n");
                printf("*** Enter valid choice ***");
        }
    }while(choice != 3);
    return 0;
}