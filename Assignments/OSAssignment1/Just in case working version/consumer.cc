// Consumer

# include "helper.h"

int main (int argc, char *argv[])
{
  // TODO 
  time_t start_time = time(NULL);

  int sem_id = sem_attach(SEM_KEY);
  if(sem_id<0){
    perror("Something went wrong while attaching the semaphore to the consumer!");
    exit(1);
  }
  
  int shm_id=shmget(SHM_KEY,SHM_SIZE,  0666 | IPC_CREAT);
 

  int consumer_id = check_arg(argv[1]);
  // sscanf(argv[1],"%d/n", &consumer_id); //CONSIDER USING CHECKAR



  QUEUE* data = (QUEUE*) shmat(shm_id, (void *)0, 0);
 
  if (data == (QUEUE*)(-1)){
    perror("Could not attach the shared memory in consumer.cc");
    exit(1);
  }
  
 
  while(sem_timewait(sem_id,0,10) != -1){

   

    
    
    //  sem_timewait(sem_id, 0, 10);
    sem_wait(sem_id,2);
    

    //if(data->front == data->end){
    // time_t end_time = time(NULL);
    // int total_time = (int)(end_time-start_time);
    // printf("Consumer(%d) time %d: No Jobs left.\n",consumer_id, total_time);
      //NEED TO DEALOCATE ALL MEMORY AND WHATEVER HEEREEEEE!!!!!!
    // goto END;
    //  }
    

    time_t t = time(NULL);
    int time_passed1 = (int)(t-start_time);
    //printf("time passed %d\n", time_passed); ///////////////DEBUUUUGGGG!!! AAAHHHHH
    

    int job_id = data->job[data->front].id;
    int job_duration =data->job[data->front].duration;
    printf("Consumer(%d) time  %d: Job id %d executing sleep duration %d \n",
	   consumer_id, time_passed1, job_id, job_duration);


    //int duration = data->job[data->front].duration;
      
    data->front = (data->front + 1)% (data->size);
    
   
    
    sem_signal(sem_id,2);
    sem_signal(sem_id,1);

    
    sleep(job_duration);
    time_t t2 = time(NULL);
    int time_passed2 = (int)(t2-start_time);
    
    printf("Consumer(%d) time  %d: Job id %d completed\n",consumer_id, time_passed2,job_id);
    // printf("\n data front now : %d \n", data->front);

    //BEFORE SEMAPHORES, REMOVE LATER!!!!!!//////////////////
    //if (data->front == data->end){
    //  printf("AAAAAARGGGGGGGG!!!!!... --- ... ... --- ... ... --- ...\n");
    // exit(1);
    //}
    ////////////////////////////////////////////////////////
  }

  //END:
  time_t end_time = time(NULL);
  int total_time = (int)(end_time-start_time);
  printf("Consumer(%d) time %d: No Jobs left.\n",consumer_id, total_time);
    
  sleep(500);
  sem_close(sem_id);
  
  shmdt(data);
  shmctl(shm_id, IPC_RMID, NULL);
  
  return 0;
}
