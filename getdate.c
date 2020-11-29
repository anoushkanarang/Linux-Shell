#include <stdio.h>
#include <time.h> 
#include <string.h>



int main(int argc, char** argv ) 
{   
	char* str1;
	FILE * fp;
	char helper1[100];
	str1 = argv[1];

	if (strcmp(str1, "--help")==0){  // --help flag
	fp = fopen ("date.txt", "r");
	if(fp == NULL) {
	perror("Error opening file");
	return(-1);
	}
	while(fgets (helper1, 600, fp)!=NULL) {
	puts(helper1);
	}
	fclose(fp);
	}

	else if (strcmp(str1, "-u")==0){ //-u flag
	time_t t = time(&t);
	struct tm *gt = gmtime(&t);
	printf("UTC %s", asctime(gt));
	}

	else if ( (strcmp(str1, "\n")!=0) && (strcmp(str1, "-u")!=0) && (strcmp(str1, "--help")!=0)){
	printf("invalid command\n");
	} 

	else{    
	time_t t = time(&t);
	struct tm lt = {0};
	localtime_r(&t, &lt);
	printf("%s %s", lt.tm_zone ,ctime(&t));
	}

    return 0; 
} 
