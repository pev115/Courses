/******************************************************************
 *The consumer program, removes jobs from the Queue and 
 *processes them.
 ******************************************************************/

# include "helper.h"
////////////////////////////////////////////////////////////////////////////////
int main (int argc, char *argv[])
{
  //Keep track of the time the producer has been running.
  time_t start_time = time(NULL);

  //Check if there is the correct number of parameters
  if(argc !=2){
    perror("Error, correct input format : ./consumer [Consumer ID]!");
    exit(1);
  }

  //Read in command line parameter : the consumer id.
  int consumer_id = check_arg(argv[1]);
  //Test for errors
  if(consumer_id==-1){
    perror("Incorrect argument to the consumer program!");
    exit(1);
  }
  
  //Fetch the shared memory.
  int shm_id=shmget(SHM_KEY,SHM_SIZE,  0666 | IPC_CREAT);
  QUEUE* data = (QUEUE*) shmat(shm_id, (void *)0, 0);
  //Test for errors
  if (shm_id==-1 || data == (QUEUE*)(-1)){
    perror("Could not attach the shared memory in consumer.cc");
    exit(1);
    //goto END;
  }

  //Attach the semaphore set to the consumer.
  int sem_id = sem_attach(SEM_KEY);
  //Test for errors
  if(sem_id<0){
    perror("Something went wrong while attaching the semaphore to the consumer!");
    shmdt(data);
    exit(1);
    //goto END; 
  }
  
  //If the buffer is empty, wait for ten seconds, if after 10 seconds 
  //it is still empty, quit. Semaphore used for the checking
  while(sem_timewait(sem_id,0,10) != -1){
    //Mutex to ensure mutual exclusion
    sem_wait(sem_id,2);

    //Keep track of the time the job is processed.
    time_t job_t = time(NULL);

    //Fetch the job data.
    int job_id = data->job[data->front].id;
    int job_duration =data->job[data->front].duration;

    //Change the queue indicators 
    data->front = (data->front + 1)% (data->size);
    
    //Up the full-checking semaphore (2) and the mutex (1)
    sem_signal(sem_id,2); //(1)
    sem_signal(sem_id,1); //(2)
    
    //Print the consumer process with the time passed
    int time_passed1 = (int)(job_t-start_time);
    printf("Consumer(%d) time  %d: Job id %d executing sleep duration %d \n",
	   consumer_id, time_passed1, job_id, job_duration);

    //Sleep for the durarion of the job and keep track of the time
    sleep(job_duration);
    time_t jobsleep_t = time(NULL);
    int time_passed2 = (int)(jobsleep_t-start_time);
    
    printf("Consumer(%d) time  %d: Job id %d completed\n",
	   consumer_id, time_passed2,job_id);
  }

  //Keep track of the time there is no more jobs
  time_t end_time = time(NULL);
  int total_time = (int)(end_time-start_time);
  printf("Consumer(%d) time %d: No Jobs left.\n",consumer_id, total_time);

  //END:
  //Sleep so that semaphore values are not reset while there are
  //still producers producing and consumers consuming.
  //Then detach form the shared memmory and delete the shared memory and
  //semaphores
  sleep(500);
  shmdt(data);
  
  //Delete the shared memory segment if it is the last consumer to run. 
  shmid_ds attachnumobj;
  shmid_ds* attachnum= &attachnumobj;
  shmctl(shm_id, IPC_STAT, attachnum);
  if(attachnum->shm_nattch==0){
    shmctl(shm_id, IPC_RMID, attachnum);
    sem_close(sem_id);
  }

  return 0;
}
