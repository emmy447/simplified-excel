#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "data.c"
#include "ordering.c"
#include "calc.c"

int main(int argc, char *argv[]) {

        Student studentList[20];
        storeData(studentList);

        if(studentList == NULL){
                printf("Error reading student list.\n");
                return 1;
        }

        int menuOption;
        int sortOption = 1;
        int idOption;
        char newLastName[10];
        int newFinalExamGrade;
        int arraySize = 10;

        for (int i = 0; i < arraySize; i++){
        float total = averageCalc(studentList[i]);
        studentList[i].total = total;
        char* letterGrade = findLetterGrade(total);
        strcpy(studentList[i].letterGrade, letterGrade);

        }

        do {

        system("clear");
        printf("\nSpreadsheet Menu\n");
        printf("-------------------\n");
        printf("1. Display Spreadsheet\n");
        printf("2. Display Histogram\n");
        printf("3. Set sort column\n");
        printf("4. Update Last Name\n");
        printf("5. Update Exam Grade\n");
        printf("6. Update Grade Mapping\n");
        printf("7. Delete Student\n");
        printf("8. Exit\n\n");

        printf("Selection: ");

        scanf("%d", &menuOption);

        switch (menuOption) {
        case 1:

                sortData(studentList, sortOption, arraySize);

                displaySpreadsheet(studentList, arraySize);
                
                menuLoop();

                break;
        case 2: 

                system("clear");
                printf("COMP 348 Grade Distribution\n");
                makeHistogram(studentList, arraySize);

                menuLoop();
                break;

        case 3:

                system("clear");
                printf("\nColumn Option");
                printf("\n-------------\n");
                printf("\n1. Student ID");
                printf("\n2. Last name");
                printf("\n3. Final");
                printf("\n4. Total\n");
                printf("\nSort Option: ");

                scanf("%d", &sortOption);
                sortData(studentList, sortOption, arraySize);
                break;

        case 4:

                displaySpreadsheet(studentList, arraySize);

                printf("\nEnter Student ID: ");
                scanf("%d", &idOption);

                printf("\nEnter Updated last name: ");
                scanf("%s", &newLastName);

                replaceLastName(studentList, idOption, newLastName);

                menuLoop();

                break;

        case 5:

                displaySpreadsheet(studentList, arraySize);

                printf("\nEnter Student ID: ");
                scanf("%d", &idOption);

                printf("\nEnter Updated Final exam grade: ");
                scanf("%d", &newFinalExamGrade);

                updateExamGrade(studentList, idOption, newFinalExamGrade);

                menuLoop();

                for (int i = 0; i < arraySize; i++){

                        float total = averageCalc(studentList[i]);
                        studentList[i].total = total;
                        char* letterGrade = findLetterGrade(total);
                        strcpy(studentList[i].letterGrade, letterGrade);
                }

                break;

        case 6:
                
                changeGradeMap();

                menuLoop();

                for (int i = 0; i < arraySize; i++){

                float total = averageCalc(studentList[i]);
                studentList[i].total = total;
                char* letterGrade = findLetterGrade(total);
                strcpy(studentList[i].letterGrade, letterGrade);
                }

                break; 

        case 7: 

                displaySpreadsheet(studentList, arraySize);

                bool yesdel;
                printf("\nEnter Student ID: ");
                scanf("%d", &idOption);
                yesdel = deleteStudent(studentList, idOption, arraySize);

                if(yesdel) {
                        arraySize--;
                } else {
                        printf("if bool-- arraySize is %d\n", arraySize);
                }

                menuLoop();
                break;

        case 8:
                system("clear");
                printf("\nGoodbye and thanks for using our spreadsheet app.\n");
                break;

        default:
                system("clear");
                printf("\nSorry, please select one of the options on the menu.\n");
                
                menuLoop();

                break;

        }

        } while (menuOption != 8);
}