#include <stdio.h>
#include <string.h>
#include <dirent.h> 
#include <sys/types.h>

int main(int argc, char** argv){

	char* str1;
	FILE * fp;
	struct dirent *ptr;  
	char helper1[100];
	int st;
	char *p;
	str1 = argv[1];
	DIR *dr;

	if (strcmp(str1, "--help")==0){  // --help flag
	fp = fopen ("ls.txt", "r");
	if(fp == NULL) {
	perror("Error opening file\n");    // error1 reported
	return(-1);
	}
	while(fgets (helper1, 600, fp)!=NULL) {
	puts(helper1);
	}
	fclose(fp);
	}


	else if (strcmp(str1, "-1")==0){ 
	dr = opendir(argv[2]);

	if (dr == NULL)  { 
	printf("Error: The directory cannot be opened\n" ); 
	return 0;} 

	while ((ptr = readdir(dr)) != NULL){printf("%s \n", ptr->d_name); }
	}


	else{
	dr = opendir(str1);
	if (dr == NULL){ printf("Error: The directory cannot be opened\n"); //error2 reported
	return 0;} 

	while ((ptr = readdir(dr)) != NULL){printf("%s  ", ptr->d_name);}
	printf("\n"); 
	}
  
	closedir(dr);     
	return 0;
	}
  
