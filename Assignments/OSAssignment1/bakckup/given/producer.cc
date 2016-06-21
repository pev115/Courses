/******************************************************************
 *The producer program, adds jobs to the Queue
 ******************************************************************/

# include "helper.h"

int main (int argc, char *argv[])
{
  //Keep track of the time the producer has been running.
  time_t start_time = time(NULL);
 
  //Check if there is the correct number of parameters
  if(argc !=3){
    perror("Error, correct input format : ./producer [Producer ID] [Nb of jobs]!");
    exit(1);
  }
  
  //Read in command line parameters : the producer id and the number of jobs.
  int producer_id = check_arg(argv[1]);
  int jobs_nb= check_arg(argv[2]);
  //Test for errors
  if(producer_id==-1|| jobs_nb ==-1){
    perror("Incorrect arguments to the producer program!");
    exit(1);
  }

  //Fetch the shared memory.
  int shm_id= shmget(SHM_KEY,SHM_SIZE,0666);
  QUEUE* data =(QUEUE*) shmat(shm_id, (void *)0, 0);
  //Test for errors
  if (shm_id== -1|| data == (QUEUE*)(-1)){
    perror("Could not attach the shared memory in producer.cc");
    exit(1);
    //goto END;
  }

  //Attach the semaphore set to the producer
  int sem_id = sem_attach(SEM_KEY);
  //Test for errors
  if(sem_id<0){
    perror("Something went wrong while attaching the semaphore to the producer!");
    shmdt(data);
    exit(1);
    //goto END;
  }
  
  //variables to keep track of the job attributes
  int job_id_produced;
  int job_duration_produced;

  //Create the Jobs in the Queue
  for(int i = 0 ; i<jobs_nb;i++){
    
    //Make sure of mutual exclusion (2) and that buffer is not full(1)
    //using the semaphores
    sem_wait(sem_id,1); //(1)
    sem_wait(sem_id,2); //(2) 
    
    //Keep track of the time the job is processed.
    time_t job_t = time(NULL);

    //Create the job.
    data->job[data->end].id = data->end + 1;
    data->job[data->end].duration = rand()%6 +2; 
    
    job_id_produced = data->job[data->end].id;
    job_duration_produced = data->job[data->end].duration;
    
    //Change the queue indicators
    data->end = (data->end +1)%data->size;
    
    //Up the empty-checking semaphore (2) and the mutex (1)
    sem_signal(sem_id,2); //(1)
    sem_signal(sem_id,0); //(2)
    
    //print the job message with the time passed when the job was processed
    int time_passed1 = (int)(job_t-start_time);
    printf("Producer (%d) time %d: Job id %d duration %d \n",
	   producer_id, time_passed1, job_id_produced,
	   job_duration_produced);

    //Sleep for a time between 2 and 4 seconds 
    int sleep_time = rand()%3+2;
    sleep(sleep_time);
  }



  
  //Keep track of the end time
  time_t end_time = time(NULL);
  int time_passed2 = (int)(end_time-start_time);
  printf("Producer(%d) time  %d: No more jobs to generate.\n",
	 producer_id,time_passed2);
  
  
  //END:
  //Sleep so that semaphore values are not reset while there are
  //still producers producing and consumers consuming and then detach
  //from the shared memory.
  sleep(500);
  shmdt(data);
  
  return 0;
}
