#include <stdio.h>
#include <string.h>


int main(int argc, char** argv) 
{ 
    char* str1;
    char* fname1;
    FILE * fp;
    char helper1[100];
    str1 = argv[1];
    fname1 = argv[2];
    char response[4];
    
  
    if (strcmp(str1, "--help")==0){  // --help flag
       fp = fopen ("rm.txt", "r");
       if(fp == NULL){
       perror("Error opening file\n"); // error1 reported
       return(-1);}

       while(fgets (helper1, 600, fp)!=NULL) {puts(helper1);}
       fclose(fp);
    }


    else if (strcmp(str1,"-i")==0){ //-i flag	
    fname1 = strtok(argv[2]," ");
    while (fname1!=NULL){
    printf("rm: remove regular file? %s",fname1);
    scanf("%s", response);
    if (response[0]=='y' || response[0]=='Y'){
      int rm = remove(fname1);
      if (!rm){printf("Deletion successful\n");}   
      else
        {printf("Deletion failed.\n"); }   // error2 reported
    } 
    fname1 = strtok(NULL," ");   
    } 
}

    
    else{	
     int rm = remove(str1);
     if (!rm){printf("Deletion successful\n");}
     else
     {printf("Error deleting.\n");}

     fname1 = strtok(argv[2]," ");
     while (fname1!=NULL){
     int rm = remove(fname1);
     if (!rm)
     {printf("Deletion successful\n");}
     else
     {printf("Error deleting.\n");}
     fname1 = strtok(NULL," ");  
    }
    
}

return 0;
}
