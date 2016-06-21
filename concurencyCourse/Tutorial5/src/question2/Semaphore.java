package question2;

public class Semaphore {
int value;



public Semaphore(int init){
	value = init;
}


synchronized void up(){
	value++;
	notifyAll();
	
}

synchronized void down(){
	while(value==0) try{wait();}catch(InterruptedException e){}
	--value;
	

}

}
