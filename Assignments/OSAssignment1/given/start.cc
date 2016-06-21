/******************************************************************
 * Program for setting up semaphores/shared memory before running
 * the Producer and Consumer 
 ******************************************************************/

# include "helper.h"


int main (int argc, char **argv)
{  
  //Check if there is the correct number of parameters
  if(argc !=2){
    perror("Error, correct input format : ./start [Queue size]!");
    return 1;
  }

  //CREATE THE SHARED MEMORY SPACE
  int shm_id = shmget(SHM_KEY,SHM_SIZE, 0666 | IPC_CREAT);
  QUEUE* data = (QUEUE*) shmat(shm_id, (void *)0, 0);
  
  //Check for errors
  if (shm_id ==-1 || data == (QUEUE*)(-1)){
    perror("Could not attach the shared memory in start.cc");
    return 1;
  }
  
  //Initialise the queue values
  int size = check_arg(argv[1]);
  //Test for errors
  if(size==-1 || size > 500){
    perror("Incorect argument to the start program!");
    shmdt(data);
    return 1;
  }

  //Initialise the queue values
  data->size = size;
  data->front = 0;
  data->end = 0;
   
  //CREATE THE SEMAPHORES
  int sem_id = sem_create(SEM_KEY, 3);
  if(sem_id<0){
    perror("Something went wrong while creating the semaphores!");
    shmdt(data);
    return 1;
  }
  
  //Semaphore 0 checks whether the buffer is empty
  if(sem_init(sem_id, 0, 0)<0){
    perror("Something went wrong while initialising a  semaphore!");
    shmdt(data);
    return 1;
  }

  //Semaphore 1 is checks whether the buffer is full
  if(sem_init(sem_id, 1, size)<0){ 
    perror("Something went wrong while initialising a semaphore!");
    return 1;
  }

  //Semaphore 3 is the mutex
  if(sem_init(sem_id, 2, 1)<0){ 
    perror("Something went wrong while initialising a mutex!");
    shmdt(data);
    return 1;
  }

  //Detach from the shared memory space
  shmdt(data);

  return 0;
}
