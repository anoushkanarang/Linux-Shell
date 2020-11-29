#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<unistd.h>  

int main() 
{
  while (1){
  
  char str[100];
  const char s[2] = " ";
  FILE * fp;
  fgets(str,100, stdin);
  char *token;
  char *token2;
  char *token3;
  char *token4;
  char *ptr;
  char *hpr;
  char sarr[100];
  char path[100];
  char helper1[100];
  char helper2[100];
  char helper3[100];
  char helper4[100];
  int status;
  char* fcd;

//updating history for each entered command
  fp = fopen("writehistory.txt", "a");
  fputs(str,fp);
  fclose(fp);
  token = strtok(str, s);
  token2 = strtok(NULL," ");
  strcpy(hpr,token2);
 
   // EXIT COMMAND
  if(strcmp(token,"exit")==0)
  {exit(0);}
   
  //ECHO COMMAND
  else if(strcmp(token,"echo")==0){
     
  	if (strcmp(token2,"-E")==0){  // -E flag 
	ptr= strtok(NULL, "");
        for (int i=0; i<strlen(ptr);i++){
        if (ptr[i]== '"' || ptr[i]=='//'){
          continue;
        }
      	if (ptr[i]=='\\' && ptr[i+1]=='n'){
          printf("n");
          i++;
      	  continue;}
      	printf("%c", ptr[i]);}   
  	}

  	else if (strcmp(token2,"-e")==0){  // -e flag 
  	ptr= strtok(NULL, "");
        for (int i=0; i<strlen(ptr);i++){
        if (ptr[i]== '"' || ptr[i]=='//')
        {continue;}
      	if (ptr[i]=='\\' && ptr[i+1]=='n'){
          printf("\n");
          i++;
      	  continue;
      	}
      	printf("%c", ptr[i]);} } 
  	

  	else{  //-Echo Implementation
        for (int i=0; i<strlen(token2);i++){
      	if (token2[i]== '\\'){continue;}
      	printf("%c", token2[i]);} 

        printf(" ");
        ptr= strtok(NULL, "");
        for (int i=0; i<strlen(ptr);i++){
      	  if (ptr[i]== '\\'){continue;}
      	  printf("%c", ptr[i]);} 
  	} 
  }
  
 

// HISTORY COMMAND
  else if(strcmp(token,"history")==0){  

  	if (strcmp(token2,"--help")==0){  // help flag
        fp = fopen ("history.txt", "r");
        if(fp == NULL) {
         perror("Error opening file");
        return(-1);}

    while(fgets (helper1, 600, fp)!=NULL ) {
     puts(helper1);}
     fclose(fp);}

  	else if (strcmp(token2,"-c")==0){  // clear flag     
        fp = fopen ("writehistory.txt", "w");
        if(fp == NULL) {
         perror("Error opening file");
         return(-1);}
          fclose(fp);}
 

  else{  // history implementation
  	fp = fopen ("writehistory.txt", "r");
  	if(fp == NULL) {
        perror("Error opening file");
        return(-1);
   }
   while(fgets (helper2, 600, fp)!=NULL) {
     puts(helper2);}
   fclose(fp);}
  }



// PWD COMMAND
  else if (strcmp(token,"pwd")==0){

    if (strcmp(token2,"--help")==0){  // help flag
    fp = fopen ("pwd.txt", "r");
    if(fp == NULL) {
      perror("Error opening file");
      return(-1);
   }
    while(fgets (helper3, 600, fp)!=NULL ) {
     puts(helper3);
   }
   fclose(fp);
  	}
  	else{
	int res =  getcwd(s, 100);
	if (res==NULL){printf("Error getting Directory");}
        printf("%s\n", getcwd(s, 100)); }
  }

  // CD Command
  else if (strcmp(token,"cd")==0){
  	if (strcmp(token2,"--help")==0){  // help flag
    fp = fopen ("cd.txt", "r");
    if(fp == NULL) {
      perror("Error opening file");
      return(-1);
   }
    while(fgets (helper4, 600, fp)!=NULL ) {
     puts(helper4);
   }
   fclose(fp);
  	}
  	else{
  // printf(".%s.\n",token2);

  	int res = chdir(token2);
    // printf("%d\n",res);
  	if (res!=0){
  		printf("Directory couldn't be changed\n");
  	}
  	printf("%s\n", getcwd(s, 100)); 
  	}
  }

   
   //DATE COMMAND
  else if (strcmp(token,"date")==0){
    pid_t cpid; 
    char *const argv[3];
    if (fork()== 0){
    char *args[]={"./getdate", token2, NULL}; 
    execv(args[0],args); 
    exit(0);  
   }
                   
   else{
   cpid = waitpid(0,&status,0); /* reaping parent */
  }
}


  //CAT COMMAND
  else if (strcmp(token,"cat")==0){
     pid_t cpid; 
    char *const argv[4];
    token3 = strtok(NULL," ");
  
    if (fork()== 0){
    char *args[]={"./getcat", token2, token3, NULL}; 
    execv(args[0],args); 
    exit(0);  
   }
     else if (!fork()){
     	printf("Creation of child process failed");
     }              
   else{
   cpid = waitpid(0,&status,0); /* reaping parent */
  }
}


 //REMOVE COMMAND
  else if (strcmp(token,"rm")==0){
    pid_t cpid; 
    char *const argv[4];
    token3 = strtok(NULL,"");
    if (fork()== 0){
    char *args[]={"./rem", token2, token3, NULL}; 
    execv(args[0],args); 
    exit(0);  
   }
                   
   else{
   cpid = waitpid(0,&status,0); /* reaping parent */
  }
}

// MKDIR COMMAND
  else if (strcmp(token,"mkdir")==0){
    pid_t cpid; 
    char *const argv[4];
    token3 = strtok(NULL,"");
   
   if (fork()== 0){
    char *args[]={"./md", token2, token3, NULL}; 
    execv(args[0],args); 
    exit(0);  
   }
                         
   else{
   cpid = waitpid(0,&status,0); /* reaping parent */
  }
}


// LS COMMAND
  else if (strcmp(token,"ls")==0){
    pid_t cpid; 
    char *const argv[3];
    token3 = strtok(NULL," ");

   if (fork()== 0){
    char *args[]={"./getls", hpr, token3, NULL}; 
    execv(args[0],args); 
    exit(0);  
   }
                      
   else{
   cpid = waitpid(0,&status,0); /* reaping parent */
  }
}

  else{
  	printf("Unrecognized Command Passed\n");
  }

  }

return 0;
  } 




