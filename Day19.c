#include <stdio.h>
#include <stdlib.h>
// Day 19 - Implementation of Doubly Linked List

// Structure of node of doubly linked list
struct Node{
    int data;
    struct Node *previous;
    struct Node *next;
};

// Function to print menu
void printMenu(){
    printf("\n\t*****Menu*****\t\n");
    printf("Enter 1 : To insert at beginning\n");
    printf("Enter 2 : To insert at end\n");
    printf("Enter 3 : To insert at index\n");
    printf("Enter 4 : To delete from start\n");
    printf("Enter 5 : To delete from end\n");
    printf("Enter 6 : To delete from index\n");
    printf("Enter 7 : To display list\n");
    printf("\nEnter your choice :");
}

// Function to count the number of nodes
int countNodes(struct Node *head){
    int count=0;
    if(head == NULL){
        return count;
    }
    struct Node *ptr;
    // ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr = head;
    while(ptr != NULL){
        ptr = ptr->next;
        count++;
    }
    return count;
}

// Function for printing the list 
void printLinkedList(struct Node *ptr){
    if(ptr == NULL){
        printf("\nYour List is empty..\n");
    }
    else {
        printf("\nYour list is :");
        while(ptr != NULL){
            printf("\t%d",ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

// Function to insert at beginning
struct Node* insertAtBegin(struct Node *ptr){
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data :");
    scanf("%d",&node->data);
    if(ptr == NULL){
        node->next = node->previous = NULL;
    }
    else {
        node->previous = NULL;
        node->next = ptr;
    }
    printf("Inserted Successfully...\n");
    printLinkedList(node);
    return node;
}

// Function to insert element at ending of linked list
struct Node* insertAtEnd(struct Node *ptr){
    if(ptr == NULL){ // Checking if list is empty
        ptr = insertAtBegin(ptr);
    }
    else{
        struct Node *node,*temp;
        node = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data :");
        scanf("%d",&node->data);
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp = ptr;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = node;
        node->previous = temp;
        node->next = NULL;
        printf("Inserted Successfully...\n");
        printLinkedList(ptr);
        // free(node);
        // free(temp);
    }
    
    return ptr;
}

// Function to insert at particular index
struct Node* insertAtIndex(struct Node *head){
    int index;
    printf("Enter index:");
    scanf("%d",&index);
    if(index == 0){
        head = insertAtBegin(head);
    }
    else if(index == countNodes(head)){
        head = insertAtEnd(head);
    }
    else if(index < countNodes(head)){
        struct Node *node,*ptr;
        node = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data :");
        scanf("%d",&node->data);
        ptr = head;
        while(--index){
            ptr = ptr->next;
        }
        node->next = ptr->next;
        ptr->next = node;
        printf("Inserted Successfully...\n");
        printLinkedList(head);
    }
    else{
        printf("Invalid Index...\n");
    }
    return head;
}

// Function to delete node from start
struct Node* deleteFromBegin(struct Node *head){
    if(head == NULL){
        printf("List is empty..\nCan't Delete...!\n");
        return head;
    }
    head = head->next;
    printf("Deleted Successfully..\n");
    printLinkedList(head);
    return head;
}

// Function to delete node from end 
struct Node* deleteFromEnd(struct Node *head){
    if(countNodes(head) == 1){
        head = deleteFromBegin(head);
        return head;
    }
    struct Node *ptr;
    ptr = head;
    while(ptr->next->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = NULL;
    printf("Deleted Successfully..\n");
    printLinkedList(head);
    return head;
}

// Function for deleting from given index
struct Node* deleteFromIndex(struct Node *head){
    int index;
    printf("Enter index :");
    scanf("%d",&index);
    if(index == 1){
        head = deleteFromBegin(head);
    }
    else if(index == countNodes(head)){
        head = deleteFromEnd(head);
    }
    else if(index < countNodes(head)){
        struct Node *ptr = head;
        // index -= 1;
        while(--index){
            ptr = ptr->next;
        }
        ptr->previous->next = ptr->next;
        ptr->next->previous = ptr->previous;
        printf("Deleted Successfully...\n");
        printLinkedList(head);
    }
    return head;
}

int main(){
    struct Node *head = NULL;
    int choice;
    printf("Linked List created....\n");
    do{
        printMenu();
        scanf("%d",&choice);
        switch(choice){
            case 0:
                printf("Exiting...\n");
                break;
            case 1:
                head = insertAtBegin(head);
                break;
            case 2:
                head = insertAtEnd(head);
                break;
            case 3:
                head = insertAtIndex(head);
                break;
            case 4:
                head = deleteFromBegin(head);
                break;
            case 5:
                head = deleteFromEnd(head);
                break;
            case 6:
                head = deleteFromIndex(head);
                break;
            case 7:
                printLinkedList(head);
                break;
            default :
                printf("Invalid Choice...\n***Enter valid choice***\n");
        }
    }while(choice);
    return 0;
}