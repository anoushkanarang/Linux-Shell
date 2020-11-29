#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>


int main(int argc, char** argv){

    char* str1;
    FILE * fp;
    char helper1[100];
    int st;
    char *pathname;
    const char s[2] = " ";
    str1 = argv[1];

 
    if (strcmp(str1, "--help")==0){  // --help flag
    fp = fopen ("mkdir.txt", "r");
      if(fp == NULL){
      perror("Error opening file\n");    // error1 reported
      return(-1);}

      while(fgets (helper1, 600, fp)!=NULL) {puts(helper1);}
      fclose(fp);
    }

    else if (strcmp(str1, "-v")==0){  //-v flag
    pathname = strtok(argv[2]," ");
    while (pathname!=NULL){
	st = mkdir(pathname, S_IRUSR|S_IRGRP|S_IROTH | S_IXUSR| S_IXGRP| S_IXOTH);

	if (st!=0){
	printf("mkdir:  File exists cannot create directory %s", pathname);
	printf("\n");}

	else{
	printf("created directory %s", pathname);
	printf("\n");}

	pathname = strtok(NULL," ");
	} 
    }


    else{
	st = mkdir(str1, S_IRUSR|S_IRGRP|S_IROTH | S_IXUSR| S_IXGRP| S_IXOTH) ;
	if (st!=0){printf("mkdir:  File exists cannot create directory %s", str1);}  // error 2
	pathname = strtok(argv[2]," ");

	 while (pathname!=NULL){
	 st = mkdir(pathname, S_IRUSR|S_IRGRP|S_IROTH | S_IXUSR| S_IXGRP| S_IXOTH) ;
	 if (st!=0){printf("mkdir:  File exists cannot create directory %s", pathname);}// error 2
	 pathname = strtok(NULL," ");
     } 	

    }

	return 0;
}
