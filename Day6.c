//Program for showing the use of structures and unions
#include <stdio.h>
static int count=0; 

//Declaring a structure to store the first name and last name of employee
struct Name{
    int ID;
    char firstName[100];
    char lastName[100];
}emp[100];  

//union for selecting either of option
union salaryType{
    int monthly;
    int weekly;
    int hourly;
}sal[100];

//Function for printing menu
void printMenu(){
    printf("\n***** MENU ***** \n");
    printf("Enter 1 : To enter a new employe\n");
    printf("Enter 2 : Find Employee in ID\n");
    printf("Enter 3 : To exit...\n");
    printf("Enter your choice :");
}

//For getting the information 
void getInfo(){
    if(count < 100){
        int choice;
        printf("Enter ID of employee :");
        scanf("%d",&emp[count].ID);
        printf("\nEnter First Name :");
        scanf("%s",&emp[count].firstName);
        printf("\nEnter Last Name :");
        scanf("%s",&emp[count].lastName);
        Start:
        printf("Enter how you want to get paid type\n");
        printf("Enter 1:For monthly\n");
        printf("Enter 2:For weekly\n");
        printf("Enter 3: For hourly\n");
        printf("Enter your choice :");
        scanf("%d",&choice);
        switch(choice){  //There could be option to choose either of them  
        case 1:
            printf("Enter monthly salary you want :");
            scanf("%d",&sal[count].monthly);
            printf("\nEmployee added to list..\n");
            break;
        case 2:
            printf("Enter weekly salary you want:");
            scanf("%d",&sal[count].weekly);
            printf("\nEmployee added to list..\n");
            break;
        case 3:
            printf("Enter hourly salary you want:");
            scanf("%d",&sal[count].hourly);
            printf("\nEmployee added to list..\n");
            break;
        default :
            printf("Invalid choice ..\n");
            printf("***Enter valid choice***\n");
            goto Start;
        }
    count++;
    }
    else {
        printf("\nEmployee list is full..\n");
    }
}

// Function for finding the employee by their ID
void showInfo(){
    int id;
    printf("Enter ID to find employee :");
    scanf("%d",&id);
    for(int i=0; i<100; i++){
        if(emp[i].ID == id){
            printf("ID found he is our employee...\n");
            printf("*****Information*****\n");
            printf("Name : %s %s\n",emp[i].lastName,emp[i].firstName);
            return;
        }
    }
    printf("\nID not found...\n");
}

int main(){
    int choice;
    do{
        printMenu();
        scanf("%d",&choice);
        switch(choice){
            case 1:
                getInfo();
                break;
            case 2:
                showInfo();
                break;
            case 3:
                printf("\nExiting..");
                break;
            default :
                printf("Invalid choice...\n****Enter valid choice****");
        }
    }while(choice != 3);
    return 0;
}