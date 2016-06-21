// Producer

# include "helper.h"

int main (int argc, char *argv[])
{
  //printf("\n");
  time_t start_time = time(NULL);
 

  int producer_id = check_arg(argv[1]);
  //sscanf(argv[1],"%d/n", &producer_id);   ////CONSIDER USING ACHEKC ARG
  int jobs_nb= check_arg(argv[2]);
  //sscanf(argv[2],"%d/n", &jobs_nb);


  int sem_id = sem_attach(SEM_KEY);
  if(sem_id<0){
    perror("Something went wrong while attaching the semaphore to the producer!");
    exit(1);
  }

  

  // int semId;
  // TODO
  int shm_id= shmget(SHM_KEY,SHM_SIZE,0666);
  //sem_attach(SEM_KEY);
  QUEUE* data =(QUEUE*) shmat(shm_id, (void *)0, 0);
  
  if (data == (QUEUE*)(-1)){
    perror("Could not attach the shared memory in producer.cc");
    exit(1);
  }
  for(int i = 0 ; i<jobs_nb;i++){
    
    
    //int sleep_time = rand()%3+2;
    // sleep(2);
    
    time_t t = time(NULL);
    int time_passed1 = (int)(t-start_time);
    // printf("time passed %d\n", time_passed);//////?DEBUUUUGGGGG!!!AHHHHH
    
    sem_wait(sem_id,1);
    sem_wait(sem_id,2);  
      
    data->job[data->end].id = data->end + 1;
    data->job[data->end].duration = rand()%6 +2; 
    
      
    printf("Producer (%d) time %d: Job id %d duration %d \n",
	   producer_id, time_passed1,  data->job[data->end].id, data->job[data->end].duration);
    
    data->end = (data->end +1)%data->size;
    
    sem_signal(sem_id,2);
    sem_signal(sem_id,0);
 

    int sleep_time = rand()%3+2;
    sleep(sleep_time);
  }
  time_t t2 = time(NULL);
  int time_passed2 = (int)(t2-start_time);
  printf("Producer(%d) time  %d: No more jobs to generate.\n",producer_id,time_passed2);
  
  sleep(500);
  shmdt(data);
  return 0;
}
