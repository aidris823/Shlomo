#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>


#define KEY 24601
#define SEG_SIZE 200 


int main(){
  //Pretty obvious but got this code from class...
  int shmd = shmget(KEY,SEG_SIZE,IPC_CREAT | 0644);
  char * data = shmat(shmd,0,0);
  if (!(*data)){
    printf("Currently no data.\n");
  }
  else{
    printf("Current data: %s \n",data);
  }
  printf("Would you like to modify the data? [y/k] (y = יאָ, k =קיין)\n");
  char * s;
  s = scanf(s);
  if (s == 'y'){
    printf("Okay cool just enter the new data: \n");
    fgets(data,200,stdin);
    printf("Current data modified as: %s \n",data);
  }
  if (s == 'k'){
    printf("Fine, then don't.\n");
  }
  printf("Delete a segment? [y/k]\n");
  s = scanf(s);
  if (s == 'y'){
    shmctl(shmd,IPC_RMID,0);
    printf("Deleted.  Current data: %s\n",data);
  }
  if (s == 'k'){
    printf("Fine, then don't.");
  }
  return 0;
}

 

  

  

