#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
	
	FILE* fp = fopen("students.txt" , "r");
	if(fp == NULL){
		printf("Unable to read file: students.txt");
		return 0;
	}
	char names[10][20];
	double MO[10];
	
	
	char file_names[20];
	double g1 , g2 , g3;

	
	int i = 0;
	printf("LASTNAMES\tMO\n\n");
	while(fscanf(fp , "%s %lf %lf %lf" , file_names , &g1 , &g2 , &g3) != EOF){
		strcpy(names[i] , file_names);	
		MO[i] = (g1+g2+g3)/3.0;
		i++;
	}
	for(i=0; i<10; i++)
		printf("%s %.10lf\n" , names[i] , MO[i]);
		
	// Finding Max MO
	double MAX_MO = -1;

	for(i=0; i<10; i++)
		if(MO[i] > MAX_MO)
			MAX_MO = MO[i];

	printf("\n\nMAX_MO: %.10lf\n\n" , MAX_MO);

	for(i=0; i<10; i++)
		if(MAX_MO == MO[i])
			printf("%s %lf\n" , names[i] , MO[i]);
		

	
	fclose(fp);
	return 0;
}
