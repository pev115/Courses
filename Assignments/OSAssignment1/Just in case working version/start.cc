/******************************************************************
 * Program for setting up semaphores/shared memory before running
 * the Producer and Consumer 
 ******************************************************************/

# include "helper.h"


int main (int argc, char **argv)
{  
  
  //printf("\n");
  
  //CREATE THE SHARED MEMORY.
  int shm_id = shmget(SHM_KEY,SHM_SIZE, 0666 | IPC_CREAT);
  QUEUE* data = (QUEUE*) shmat(shm_id, (void *)0, 0);
   
  if (data == (QUEUE*)(-1)){
    perror("Could not attach the shared memory in start.cc");
    exit(1);
  }

  if(argc !=2 ){
    perror("Correct format : start [Queue size]!");
    exit(1);
  }

  int size = check_arg(argv[1]);
  // sscanf(argv[1],"%d/n", &size); ///CONSIDEER USING CHECK ARG
  data->size = size;
  data->front = 0;////PUT TO 0
  data->end = 0;/////PUT TO 0
   
  //CREATE THE SEMAPHORES.
  int sem_id = sem_create(SEM_KEY, 3);
  if(sem_id<0){
    perror("Something went wrong while creating the semaphores!");
    exit(1);
  }
  
  //Semaphore 0 is the not empty semaphore
  if(sem_init(sem_id, 0, 0)<0){
    perror("Something went wrong while initialising a  semaphore!");
    exit(1);
  }


  //Semaphore 1 is the non full semaphore
  if(sem_init(sem_id, 1, size)<0){ ////CHECK IF size is CORRECT
    perror("Something went wrong while initialising a semaphore!");
    exit(1);
  }

  //Semaphore 3 is the mutex
  if(sem_init(sem_id, 2, 1)<0){ ////CHECK IF size is CORRECT
    perror("Something went wrong while initialising a mutex!");
    exit(1);
  }




  /*DEBUUUUGGGG!!!AAAAAAHHHHHHH!!!!!!/////////////////////
  data->job[0].id = 1;
  data->job[0].duration = 1;
  data->job[1].id = 2;
  data->job[1].duration = 2;
  data->job[2].id = 3;
  data->job[2].duration = 3;
  data->job[3].id = 4;
  data->job[3].duration = 4;
  data->job[4].id = 5;
  data->job[4].duration = 5; 
  data->job[5].id = 6;
  data->job[5].duration = 6;

  *//////////////////////////////////////////////////////
   
  /*if(argc == 1){
    data->size = 0;
    data->front = 
    }
    data.size = static_cast<int>(arv[1][0]-48);
    data.front = static_cat<int>(argv[1][0]-49);
   
  */
  //sem_create(SEM_KEY,3);
   
  // TODO
  
  //sleep(1000);
  //shmdt(data);
  return 0;
}
