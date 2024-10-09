#ifndef studentstruct
#define studentstruct

typedef struct {
	int studentNum;
	char lastName[20];
	char firstName[20];
	int a1;
	int a2;
	int a3;
	int midterm;
	int final;
	float total;
	char letterGrade[1];
} Student;

#endif