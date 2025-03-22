//
// LinkedListGrade.c
// Grade Management program
// Linked List style
//
//
// author by HM on 2025/03/14 ~ 19
//
// update test

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_SUBJECT 2


typedef struct student {
    char Name[100];
    int ID;
    int English;
    int Math;
    float AvgScore;
    struct student * next;
}sNode;


void InsertStudent(sNode ** head);
void CalculateAvg(sNode * head);
void ViewAllStu(sNode * head);
int GetHighestIndex(sNode * head);
void ViewStuData(sNode * head, int highestI);
void ListSort(sNode ** head);
void FreeList(sNode **head);


int main(){
    sNode * head = NULL;
    int choice;

    while (1) {
        printf("\n============Select Menu============\n");
        printf("1. Insert Student\n");
        printf("2. Calculate Average\n");
        printf("3. Print all Students\n");
        printf("4. Print the Sorted Student List\n");
        printf("5. Print the Student with the highest Average\n");
        printf("0. Exit\n");
        printf("Select : ");
        scanf("%d", &choice);
        printf("\n\n");

        switch(choice){
            case 1 : InsertStudent(&head);  break;
            case 2 : CalculateAvg(head);    break;
            case 3 : {
                printf("\n       ===== Full Student List =====\n");
                printf("%-10s %-5s %-8s %-8s %7s\n\n", "Name", "ID", "English", "Math", "Avg");
                ViewAllStu(head);      
                break;
            }
            case 4 : ListSort(&head);       break;
            case 5 : {
                int highestI = GetHighestIndex(head);
                printf("\n====== Student with the Highest grade ======\n");
                printf("%-10s %-5s %-8s %-8s %7s\n\n", "Name", "ID", "English", "Math", "Avg");
                ViewStuData(head, highestI);
                break;
            }
            case 0 : FreeList(&head); return 0;
            default : printf("Invalid input. Try Again\n");
        }
    }   
}

void InsertStudent(sNode ** head) {
    sNode * newStudent = (sNode*)malloc(sizeof(sNode));
    if(!newStudent) {
        printf("Exists in the List\n");
        return;
    }
    
    printf("===================\n");
    printf("Name : ");
    scanf("%s", newStudent->Name);
    printf("ID : ");
    scanf("%d", &newStudent->ID);
    printf("English : ");
    scanf("%d", &newStudent->English);
    printf("Math : ");
    scanf("%d", &newStudent->Math);

    newStudent->AvgScore = 0;
    newStudent->next = NULL;                   // New node -> Last one
    
    if(*head == NULL){                         // Empty situation
        *head = newStudent;
    }else {                                    // Exists one or more
        sNode * temp = *head;
        while (temp->next) 
        {
            temp = temp->next;
        }
        temp->next = newStudent;               // After end the while roof next block -> new Student

    }

    
}

void CalculateAvg(sNode * head){
    sNode * temp = head;
    while (temp) {
        temp->AvgScore = (temp->English + temp->Math)/(float)NUM_SUBJECT;
        temp = temp->next;
    }
       
}

void ViewAllStu(sNode * head){
    
    if (head == NULL){
        printf("\nNo data \n");
        return;
    }

    sNode * temp = head;

    while (temp->next) {
        printf("%-10s %-5d %-8d %-8d %7.1f\n", temp->Name, temp->ID, temp->English, temp->Math, temp->AvgScore);
        printf("------------------------------------------------------\n");
        temp = temp->next;
    }
    printf("%-10s %-5d %-8d %-8d %7.1f\n", temp->Name, temp->ID, temp->English, temp->Math, temp->AvgScore);
    printf("------------------------------------------------------\n");
    
}

int GetHighestIndex(sNode * head){
    sNode * temp = head;
    int highestI = -1;
    float highestAvg = -1;

    while (temp) {
        if(temp->AvgScore > highestAvg) {
            highestAvg = temp->AvgScore;
            highestI = temp->ID;
        }
        temp = temp->next;
    }
    return highestI;
}

void ListSort(sNode ** head) {
    if (!*head || !(*head)->next) return;

    int swp;
    sNode **ptr1;
    sNode *curr, *nextNode, *prev = NULL;
    
    do{
        swp = 0;
        ptr1 = head;

        while ((*ptr1)->next) {
            curr = *ptr1;
            nextNode = curr->next;

            if (curr->AvgScore < nextNode->AvgScore){
                curr->next = nextNode->next;
                nextNode->next = curr;
                *ptr1 = nextNode;
                swp = 1;
            }
            ptr1 = &((*ptr1)->next);
        }
        
    } while (swp);  
    
    printf("\n       ===== Sorted Student List =====\n");
    printf("%-10s %-5s %-8s %-8s %7s\n\n", "Name", "ID", "English", "Math", "Avg");

    ViewAllStu(*head);
}

void ViewStuData(sNode* head, int highestI) {
    sNode* temp = head;
    while (temp) {
        if (temp->ID == highestI) {
            printf("%-10s %-5d %-8d %-8d %7.1f\n", temp->Name, temp->ID, temp->English, temp->Math, temp->AvgScore);
            printf("------------------------------------------------------\n");
            break;
        }
        temp = temp->next;
    }
}

void FreeList(sNode **head){
    sNode *temp;
    while (*head) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    *head = NULL;
}