package question2;
import question1.*;
public class testthreadput extends Thread{
	static Integer superint;
	oneBuf buf;
	
	public testthreadput(oneBuf buffer){
		buf= buffer;
		superint = 5;
	}
	
	public void run(){
		int i =0;
		while(i<40){
			try {buf.put(superint);} catch (InterruptedException e) {} 
			System.out.println("PUTTED"); i++;
		}
	}
	
	
}
