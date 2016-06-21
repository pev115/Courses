package question1;

public class oneBuf {
	Object data=null;
	
	public oneBuf(){}
	

	
	public synchronized void put(Object value) throws InterruptedException{
		System.out.println("put in");
		while(data != null){wait();}
		data= value; 
		notify();
		System.out.println("notify put");
	}
	
	public synchronized Object get() throws InterruptedException{
		System.out.println("get in");
		while(data == null){ wait();}
		notify();
		System.out.println("notify get");
		Object o = data;
		data=null;
		return o;
	}
}
