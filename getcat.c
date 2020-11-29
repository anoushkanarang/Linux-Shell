#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) 
{ 

	char *str1;
	char *fname;
	FILE * fp;
	char helper1[100];
	char helper2[100];
	char helper3[100];
	str1 = argv[1];
	fname = argv[2];


	if (strcmp(str1, "--help")==0){  // --help flag

	fp = fopen ("cat.txt", "r");
	if(fp == NULL) {
	perror("Error opening file");
	return(-1);
	}
	while(fgets (helper1, 600, fp)!=NULL) {
	puts(helper1);
	}
	fclose(fp);
	}

	else if (strcmp(str1, "-n")==0){	
	fp = fopen (fname,"r");
	if(fp == NULL) {
	perror("Error opening file");
	return(-1);
	}
	int i =1;
	char res[1000]; 
	sprintf(res, "%d  ", i); 
	while(fgets (helper2, 600, fp)!=NULL) {
	puts(strcat(res, helper2));
	i++;
	sprintf(res, "%d  ", i); 
	}
	fclose(fp);
	}   

	else{

	fp = fopen (str1, "r");
	if(fp == NULL) {
	perror("Error opening file");
	return(-1);
	}
	while(fgets (helper3, 600, fp)!=NULL) {
	puts(helper3);
	}
	fclose(fp);
	}

	return 0;
	}
