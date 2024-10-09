#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "studentStruct.h"

int newA;
int newB;
int newC;
int newDnF;

int range1 = 50;
int range2 = 60;
int range3 = 70;
int range4 = 80;



float averageCalc(Student student) {

		float total = 0;
		total = (((((student.a1/40.0)+(student.a2/40.0)+(student.a3/40.0))/3.0)*(25.0/100.0))+((student.midterm/25.0)*(25.0/100.0))+((student.final/40.0)*(50.0/100.0)))*100;
		return total;
}

char* findLetterGrade(float total) {

	if (total < range1) {
		return "F";
	}

	else if (total >= range1 && total < range2 ) {
		return "D";
	}

	else if (total >= range2 && total < range3 ) {
		return "C";
	}

	else if (total >= range3 && total < range4) {
		return "B";
	}

	else if (total >= range4) {
		return "A";
	}

	else{
		return "Error reading student grade";
	}
}

void replaceLastName(Student students[], int id, char* newLastName){
	for(int i = 0; i < 10; i++) {
		if(students[i].studentNum == id) {
			strcpy(students[i].lastName, newLastName);
		}
	}

	printf("%s\n", "Last Name updated" );
}

void updateExamGrade(Student students[], int id, int newGrade){
	for(int i = 0; i < 10; i++) {
		if(students[i].studentNum == id) {
			students[i].final = newGrade;
		}
	}

	printf("%s\n", "Final exam grade updated" );
}

void changeGradeMap() {

	system ("clear");
	printf("Current Mappin: \n");
	printf("A: >= %d \n", range4);
	printf("B: >= %d \n", range3);
	printf("C: >= %d \n", range2);
	printf("D: >= %d \n", range1);
	printf("F: < %d \n", range1);

	printf("Enter new A baseline: \n");
	scanf("%d", &newA);
	printf("Enter new B baseline: \n");
	scanf("%d", &newB);
	printf("Enter new C baseline: \n");
	scanf("%d", &newC);
	printf("Enter new D baseline: \n");
	scanf("%d", &newDnF);

	range4 = newA;
	range3 = newB;
	range2 = newC;
	range1 = newDnF;

	printf("\nCurrent Mappin: \n");
	printf("A: >= %d \n", range4);
	printf("B: >= %d \n", range3);
	printf("C: >= %d \n", range2);
	printf("D: >= %d \n", range1);
	printf("F: < %d \n", range1);


}

void deleteRow(Student *students, int location, int arraySize) {
	   for (int i = location; i < arraySize - 1; i++) {
       students[i] = students[i + 1];
    }
}

int findStudent(Student *students, int studentNumber,int arraySize) {

    for (int i = 0; i < arraySize; i++) {
        if (students[i].studentNum == studentNumber) {
            return i;
        }
    }
    return -1;
}

bool deleteStudent(Student *students, int id, int arraySize) {

	int location = findStudent(students, id,arraySize);

    if (location != -1) {
        deleteRow(students, location, arraySize);
        printf("Student deleted.\n");
        return true;
    } else {
        printf("Student not found.\n");
        return false;
    }
}

void makeHistogram(Student studentList[], int arraySize){

                printf("A: ");
                for(int i = 0; i < arraySize; i++) {
                        if (strcmp(studentList[i].letterGrade,"A") == 0) {
                            printf("*");
                        }
                }
                printf("\nB: ");
                for(int i = 0; i < arraySize; i++) {
                        if (strcmp(studentList[i].letterGrade,"B") == 0) {
                            printf("*");
                        }
                }
                printf("\nC: ");
                for(int i = 0; i < arraySize; i++) {
                        if (strcmp(studentList[i].letterGrade,"C") == 0) {
                            printf("*");
                        }
                }

                printf("\nD: ");
                for(int i = 0; i < arraySize; i++) {
                        if (strcmp(studentList[i].letterGrade,"D") == 0) {
                            printf("*");
                        }
                }

                printf("\nF: ");
                for(int i = 0; i < arraySize; i++) {
                        if (strcmp(studentList[i].letterGrade,"F") == 0) {
                            printf("*");
                        }
                }
}

void menuLoop() {
	
	char proceed;
    printf("\nPress 'c' or 'C' to continue ");
        do {

            scanf("%c", &proceed);

        	} while ( (proceed != 'c') && (proceed != 'C'));
}