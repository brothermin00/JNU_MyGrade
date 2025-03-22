//
// MgmtGrade.c
// Grade Management program
// Sturct Style
//
// 
// Original author : Prof. Hur, JNU
// edited by HM on 2025/03/12 ~ 14
//

#include <stdio.h>
#include <string.h>

#define NUM_STUDENT 3 
#define NUM_SUBJECT 2 
// #define MAX_SUBJECT 2                    // Remove it and unify it as NUM_SUBJECT.



typedef struct student{ 
  char Name[100];                           // Execise 1-1 : Add a member to the structure
  int ID; 
  int English; 
  int Math; 
  float AvgScore; 
  int scores[NUM_SUBJECT];                  // Add array working for store subjects
}sNode; 


//void CalculateAverage(sNode * stu);             // Calculate average of all persons 
void SelecMenu(sNode * stu, sNode * stuSort);     // Exercise 2-2 : Add SelecMenu
void InsertStudent(sNode * stu);
void CalculateAvg(sNode * stu);                   // Exercise 1-2 : Calculate the average in AddStudent(). Calculate average of all person
int GetHighestIndex(sNode* stu);                  // Find the person with the highest average  
void ViewStuData(sNode * stu, int highestI);      // Exercise 1-3 : Print in the ViewStuData function. Print the scores of the Best student.
void ViewAllStu(sNode * stu);                     // Print Student List
void ListSort(sNode * stu, sNode * stuSort);      // Exercise 2-1 : Add Prototype
// void BinarySort(sNode * stuSort);              // version 1
// void BubbleSort(sNode * stuSort, int size);    // version 2
void BubbleSort(sNode ary[], int len);            // Exercise 3 (version 3)
void ListStudent(sNode * stu);                    // Exercise 4

int main() { 
    sNode stu[NUM_STUDENT];                       // Node stuSort[NUM_STUDENT]; 
    sNode stuSort[NUM_STUDENT];                   // Store Sorting List

    SelecMenu(stu, stuSort);                      // Move to SelecMenu and act everything

    /*
    int i; 
    
    for (i=0; i<NUM_STUDENT; i++) { 
      // Get information using scanf 
      printf("====================\n");
      printf("Name="); 
      scanf("%s", stu[i].Name); 
      printf("ID="); 
      scanf("%d", &stu[i].ID); 
      printf("English="); 
      scanf("%d", &stu[i].English); 
      printf("Math="); 
      scanf("%d", &stu[i].Math); 
      printf("====================\n");
      printf("\n");
    } 
  
    // Calculate average of all persons   
    // CalculateAverage(stu);
    
    // Calculate average of all persons   
    AddStudent(stu);

    // Find the person who has the highest average
    int highestI = GetHighestIndex(stu); 
  
    printf("*****************************************\n");
    printf("Who has the highest average score : \n");
    ViewStuData(stu, highestI);

    
    printf("Who has the highest average score: \n"); 
    printf(" Name: %s \n", stu[highestI].Name); 
    printf(" ID: %d \n", stu[highestI].ID); 
    printf(" English: %d \n", stu[highestI].English); 
    printf(" Math: %d \n", stu[highestI].Math); 
    printf(" Average: %.2f \n", stu[highestI].AvgScore); 
    */
    

    return 0; 
}
  
  /*
  void CalculateAverage(sNode * stu){ 
    int i; 
    for(i = 0; i < NUM_STUDENT; i++) { 
      stu[i].AvgScore = (stu[i].English + stu[i].Math) / NUM_SUBJECT ; 
    } 
  } */

  void InsertStudent(sNode * stu) {
    for (int i=0; i<NUM_STUDENT; i++) { 
      // Get information using scanf 
      printf("====================\n");
      printf("Name="); 
      scanf("%s", stu[i].Name); 
      printf("ID="); 
      scanf("%d", &stu[i].ID); 
      printf("English="); 
      scanf("%d", &stu[i].English); 
      printf("Math="); 
      scanf("%d", &stu[i].Math); 
      printf("====================\n");
      printf("\n");
    } 
  }

  void CalculateAvg(sNode * stu) {
    for (int i = 0; i < NUM_STUDENT; i++) {
      int SumScore = 0;
      stu[i].scores[0] = stu[i].English;
      stu[i].scores[1] = stu[i].Math;

      for (int s=0; s < NUM_SUBJECT; s++) {
        SumScore += stu[i].scores[s];
      }
      stu[i].AvgScore = (float)SumScore/NUM_SUBJECT;
    }
  }
  
  int GetHighestIndex(sNode * stu) { 
    int highestI = 0; 
    int i; 
    float highestA = stu[0].AvgScore; 
    for(i = 1; i < NUM_STUDENT; i++) { 
      if(stu[i].AvgScore > highestA) { 
        highestA = stu[i].AvgScore; 
        highestI = i; 
      } 
    } 
    return highestI; 
  }
  
  void ViewStuData(sNode * stu, int highestI) {

    printf("%-10s %-5d %-8d %-8d %7.1f\n", 
      stu[highestI].Name, stu[highestI].ID, stu[highestI].English, stu[highestI].Math, stu[highestI].AvgScore);
    printf("---------------------------------------------------------------------\n");
  }

  void ViewAllStu(sNode * stu) {
    printf("\n      ==== Full Student List ====\n");
    printf("%-10s %-5s %-8s %-8s %7s\n\n", "Name", "ID", "English", "Math", "Avg");
    for(int i = 0; i<NUM_STUDENT; i++){
      printf("%-10s %-5d %-8d %-8d %7.1f\n", 
        stu[i].Name, stu[i].ID, stu[i].English, stu[i].Math, stu[i].AvgScore);
      printf("---------------------------------------------------------------------\n");
    }
  }

  /*                                                              // Original version
  void ViewStuData(sNode * stu, int highestI){
    printf("***********************\n");
    printf("Name: %s\n", stu[highestI].Name);
    printf("ID: %d\n", stu[highestI].ID);
    printf("English: %d\n", stu[highestI].English);
    printf("Math: %d\n", stu[highestI].Math);
    printf("Average: %7.1f\n", stu[highestI].AvgScore);
    printf("***********************\n");
    printf("\n");
  } 

  void ViewAllStu(sNode * stu){
    for(int i = 0; i<NUM_STUDENT; i++){
      printf("--------------------\n");
      printf("Name: %s\n", stu[i].Name);
      printf("ID: %d\n", stu[i].ID);
      printf("English: %d\n", stu[i].English);
      printf("Math: %d\n", stu[i].Math);
      printf("Average: %7.1f\n", stu[i].AvgScore);
      printf("--------------------\n\n");
    }
  } */
  


  void ListSort(sNode * stu, sNode * stuSort) {                          // Sort in descending order.
    for (int i = 0; i < NUM_STUDENT; i++) {
      stuSort[i] = stu[i];
    }


    BubbleSort(stuSort, NUM_STUDENT);                       // version 2, 3
    // BinarySort(stuSort);                                 // Binary Search. version 1

    printf("\n==== Student sorting results (based on avg score) ====\n");
    printf("%-10s %-5s %-8s %-8s %7s\n\n", "Name", "ID", "English", "Math", "Avg");

    for (int i = 0; i < NUM_STUDENT; i++) {
      ViewStuData(stuSort, i);
    }
  }

  
  void BubbleSort(sNode ary[], int len) {                                // Version 3 (Exercise 3)
    char TempName[100];  
    float TempAvgScore;
    int TempID, TempScore;
    int TempEngligh, TempMath;

    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (ary[j].AvgScore < ary[j + 1].AvgScore) {

                // Swap Avg score
                TempAvgScore = ary[j].AvgScore;
                ary[j].AvgScore = ary[j + 1].AvgScore;
                ary[j + 1].AvgScore = TempAvgScore;

                // Swap name
                strcpy(TempName, ary[j].Name);
                strcpy(ary[j].Name, ary[j + 1].Name);
                strcpy(ary[j + 1].Name, TempName);

                // Swap ID
                TempID = ary[j].ID;
                ary[j].ID = ary[j + 1].ID;
                ary[j + 1].ID = TempID;

                TempEngligh = ary[j].English;
                ary[j].English = ary[j + 1].English;
                ary[j + 1].English = TempEngligh;

                TempMath = ary[j].Math;
                ary[j].Math = ary[j + 1].Math;
                ary[j + 1].Math = TempMath;

                /*
                // Swap score each                                     // Not Work
                for (int k = 0; k < NUM_SUBJECT; k++) {
                    TempScore = ary[j].scores[k];
                    ary[j].scores[k] = ary[j + 1].scores[k];
                    ary[j + 1].scores[k] = TempScore;
                } */
            }
        }
    }
}


 /*                                                                // Version 2
  void BubbleSort(sNode * stuSort, int size) {

    for (int i =0; i<size-1; i++){
      for(int j = 0; j < size - i - 1; j++){
        if (stuSort[j].AvgScore < stuSort[j+1].AvgScore){
          sNode temp = stuSort[j];
          stuSort[j] = stuSort[j+1];
          stuSort[j+1] = temp;
        }
      }
    }
  }*/

  /*                                                                  // Version 1
  void BinarySort(sNode * stuSort){                                                                  
    for (int i = 0; i < NUM_STUDENT - 1; i++) {
      for (int j = 0; j < NUM_STUDENT - i - 1; j++) {
          if (stuSort[j].AvgScore < stuSort[j + 1].AvgScore) {
              sNode temp = stuSort[j];
              stuSort[j] = stuSort[j + 1];
              stuSort[j + 1] = temp;
          }
      }
    } 
  } */

  void SelecMenu(sNode * stu, sNode * stuSort) {
    int choice;
    while (1)
    {
      printf("\n==========Select Menu==============\n");
      printf("1. Insert Student\n");
      printf("2. Calculation Average\n");
      printf("3. Print all Students\n");
      printf("4. Print the Sorted Student List\n");
      printf("5. Print the Student with the highest Average\n");
      printf("6. Output the result file\n");
      printf("0. Exit\n");
      printf("Select : ");
      scanf("%d", &choice);
      printf("\n\n");

      switch (choice)
      {
      case 1: InsertStudent(stu);   break;
      case 2: CalculateAvg(stu);   break;
      case 3: ViewAllStu(stu);   break;
      case 4: ListSort(stu, stuSort);   break;
      case 5: {
        printf("\n==== Student with the Highest grade ====\n");
        printf("%-10s %-5s %-8s %-8s %-7s\n\n", "Name", "ID", "English", "Math", "Avg");
        int highestI = GetHighestIndex(stu);
        ViewStuData(stu, highestI);
        break;
      }
      case 6: ListStudent(stu);     break;
      case 0: return;
      default:  printf("Invalid input. Try Again.");     
      }
    }    
  }

  void ListStudent(sNode * stu){
    
    FILE *fp = fopen("ListFileOut.txt", "wt");
    if (fp == NULL){
      printf("Can't open the File\n");
      return;
    }

    fprintf(fp, "%-5s %-10s", "ID", "Name");
    for(int s = 0; s < NUM_SUBJECT; s++){
      fprintf(fp, " %-8s", (s == 0) ? "English" : "Math");
    }
    fprintf(fp, "%-7s\n", "Avg");

    for (int i = 0; i < NUM_STUDENT; i++){
      if(stu[i].ID > 0){
        fprintf(fp, "%-5d %-10s", stu[i].ID, stu[i].Name);
        for(int s = 0; s < NUM_SUBJECT; s++){
          fprintf(fp, "%-8d", stu[i].scores[s]);
        }
        fprintf(fp, "%-7.1f\n", stu[i].AvgScore);
      }
    }

    fclose(fp);
    printf("The student list has been saved in the [ListFileOut.txt] file\n");

  }





