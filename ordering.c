#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_ints_Ascending(const void *a, const void *b) {
    int *x = (int *)a;
    int *y = (int *)b;
    return *x - *y;
}

int compare_ints_Descending(const void *a, const void *b) {
    const Student *x = (const Student *)a;
    const Student *y = (const Student *)b;
    return y->final - x->final;
}

int compare_floats(const void *a, const void *b) {
    const Student *x = (const Student *)a;
    const Student *y = (const Student *)b;
     if (y->total < x->total)
      	return -1  ;
               
        else if(y->total > x->total)
                return 1;
        return 0;
}

 int compare_String(const void *a, const void *b) {
    const Student *e1 = (const Student *)a;
    const Student *e2 = (const Student *)b;

    return strcmp(e1->lastName, e2->lastName);
}

void sortData(Student students[], int sortColumn, int arraySize){

	switch(sortColumn){
	case 1:
		qsort(students, arraySize, sizeof(Student), compare_ints_Ascending);
    	printf("\n");
    	break;
	case 2:
		qsort(students, arraySize, sizeof(Student), compare_String);
    	printf("\n");
    	break;
	case 3:
		qsort(students, arraySize, sizeof(Student), compare_ints_Descending);
    	printf("\n");
    	break;
	case 4:
		qsort(students, arraySize, sizeof(Student), compare_floats);
    	printf("\n");
    	break;
	default:
		printf("\nOption is incorrect.\n");
		exit(0);

	}
}