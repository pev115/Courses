package question2;
import question1.*;
public class testthreadget extends Thread{

	oneBuf buf;
	
	public testthreadget(oneBuf buffer){
		buf= buffer;
	}
	
	public void run(){
		int i =0;
		while(i<40){
			try {buf.get(); } catch (InterruptedException e) {}
			System.out.println("Gotten"); i++;
		}
		
		
	}
	
	
}
