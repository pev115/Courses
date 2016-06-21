

/**
 * Complete the implementation of this class in line with the FSP model
 */

public class PlatformAccess {
 
  /* declarations required */
  //flag to check whether there is a car in the platform
  private boolean empty = true;
  
  public synchronized void arrive() throws InterruptedException {
	  //If the platform is not empty you cannot arrive
	  while(!empty) wait();
	  
	  //Update the flag
	  empty =false;
	  
	  //notify waiting threads
	  notify();
  }

  public synchronized void depart() {
	  //Set the platform to empty
	  empty = true;
	  
	  //Notify waiting threads
	  notify(); 
  }

}