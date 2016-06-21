package question2;
import question1.*;


public class test  {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		System.out.println("hello statin the mofo program");
		oneBuf buf = new oneBuf();
		testthreadget t1 = new testthreadget(buf);
		testthreadput t2 = new testthreadput(buf);
		
		t1.start();
		t2.start();
		
	}

	public void run(){

		
		
		
	}
	
}
