

/**
 * Complete the implementation of this class in line with the FSP model
 */

import display.*;

public class Controller {

  public static int Max = 9;
  protected NumberCanvas passengers;

  // declarations required
  //Number of passengers in the platform
  int platform_passengers=0;


  public Controller(NumberCanvas nc) {
    passengers = nc;
  }

  public synchronized void newPassenger() throws InterruptedException {
	//if there are Max passengers in the platform block
	 while (platform_passengers>=Max) wait();

	//Update the number of passengers in the platform 
	 platform_passengers+=1

	//And display the change
         passengers.setValue(platform_passengers);

         notifyAll();
  }

  public synchronized int getPassengers(int mcar) throws InterruptedException {
  	//If the platform does not have enough passengers wait
	  while(platform_passengers<mcar) wait();

	//Update the number of passengers in the platform
	  platform_passengers-=mcar;
	
	//Display the value and return it
          passengers.setValue(platform_passengers);
	  notifyAll();
          return mcar; 
  }

  public synchronized void goNow() {
    // complete implementation for part II
  }

}
