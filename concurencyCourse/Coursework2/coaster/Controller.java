

/**
 * Complete the implementation of this class in line with the FSP model
 */

import display.*;

public class Controller {

  public static int Max = 9;
  protected NumberCanvas passengers;

  // declarations required
  int platform_passengers=0;
  boolean go_now_flag = false;


  public Controller(NumberCanvas nc) {
    passengers = nc;
  }

  public synchronized void newPassenger() throws InterruptedException {
     // if there are Max passengers in the platform block
	 while (platform_passengers>=Max)wait();
	 platform_passengers+=1;
     passengers.setValue(platform_passengers);
     notifyAll();
  }

  public synchronized int getPassengers(int mcar) throws InterruptedException {
     //If the platform does not have enough passengers wait
	  while(platform_passengers<mcar) {
		  wait(); 
		  //If the go button is pressed, the go_now_flag is true, so break
		  if(go_now_flag){
			  break;
		  }
	  }
	  //If there are more passengers in the platform than the capacity of the car
	  if( platform_passengers>= mcar){
		  
		  //Update the number of passengers in the platform and display it
		  platform_passengers-=mcar;
		  passengers.setValue(platform_passengers);
		  
		  go_now_flag = false;
		  
		  //return the number of passengers on board the car
		  notifyAll();
		  return mcar; 
     }else{
    	 //get the number of passengers that are on board
    	 int on_board = platform_passengers;
    	 
    	 //update the platform passenger number and display it
    	 platform_passengers = 0;
    	 passengers.setValue(platform_passengers);
    	 
    	 go_now_flag = false;
    	 notifyAll();
    	 //return the number of passengers on board
    	 return on_board;
     }
	
  }

  public synchronized void goNow() {
  if(platform_passengers > 0){
	 notifyAll();
	 go_now_flag = true;
  }
  }
  
  
}