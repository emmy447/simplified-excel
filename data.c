#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "studentStruct.h"

void storeData(Student students[]) {

	FILE *file;

	file = fopen("student.txt", "r");

	if(file == NULL) {
		printf("Error: File could not be opened\n");
	}

	char record[50];
	char *data;

	int index = 0;
	while (fgets(record, 50, file) != NULL){
		data = strtok(record, "|");
		if(data != NULL) {
			students[index].studentNum = atoi(data);
			data = strtok(NULL, "|");
			strcpy(students[index].lastName, data);
			data = strtok(NULL, "|");
			strcpy(students[index].firstName, data);
			data = strtok(NULL, "|");
			students[index].a1 = atoi(data);
			data = strtok(NULL, "|");
			students[index].a2 = atoi(data);
			data = strtok(NULL, "|");
			students[index].a3 = atoi(data);
			data = strtok(NULL, "|");
			students[index].midterm = atoi(data);
			data = strtok(NULL, "|");
			students[index].final = atoi(data);
			index++;
		}
	}

	fclose(file);
}

void displaySpreadsheet(Student studentList[], int arraySize) {

    system("clear");
    printf("\nCOMP 348 GRADE SHEET\n");
	printf("%-10s %-12s %-12s %-2s %-2s %-3s %-10s %-7s %-7s %-10s\n", "Student #", "Last Name", "First Name", "a1", "a2", "a3", "Midterm", "Final", "Total", "Grade");
	printf("%-10s %-12s %-12s %-2s %-2s %-3s %-10s %-7s %-7s %-10s\n", "---------", "---------", "----------", "--", "--", "--", "-------", "-----", "-----", "-----");

	for (int i = 0; i < arraySize; i++) {

	        
	        printf("%-10d %-12s %-12s %-2d %-2d %-3d %-10d %-7d %-7.2f %-10s\n", studentList[i].studentNum, studentList[i].lastName, studentList[i].firstName , studentList[i].a1, studentList[i].a2, studentList[i].a3, studentList[i].midterm, studentList[i].final, studentList[i].total, studentList[i].letterGrade);
	}
}