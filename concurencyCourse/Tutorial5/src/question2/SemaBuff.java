package question2;

public class SemaBuff {

	Object data;
	Semaphore full;
	Semaphore empty;
	
	public SemaBuff(){
		full = new Semaphore(0);
		empty = new Semaphore(1);
	}
	
	public void put(Object _data){
		empty.down();
		synchronized(this){
			data= _data;
		}
		full.up();
	}
	
	public Object get(){
		full.down();
		synchronized(this){
			Object o= data;
			data = null;
			empty.up();
			
	
			return o;
		}
	
	}
	
	
	
}
