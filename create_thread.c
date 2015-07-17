#include<stdio.h>
#include<unistd.h>
#include<pthread.h>


void *thread_execution(void *args){
  int i =0;
  for(i=0;i<10;i++){
    printf("I am in loop %d \n",i);
    printf("going to sleep \n");
    i++;
  }
  pthread_exit(0);
  return 0;
}

int main(){
  int thread_create_id;
  int thread_join;
  pthread_t thread_t;
  // creating a thread using posix
  thread_create_id = pthread_create(&thread_t,NULL,thread_execution,NULL);
  if(thread_create_id>0){
    fprintf(stdout,"thread creation failed");
    return 1;
  }else{
    printf("thread has been started to execute in background \n");
  }
  
  printf("parent is working for waiting the child process \n");
  thread_join = pthread_join(thread_t,NULL);
  if(thread_join>0){
    fprintf(stdout,"Join failed");
    return 1;
  }
return 0;
}


