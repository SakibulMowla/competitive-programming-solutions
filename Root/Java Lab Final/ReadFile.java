import java.io.*;
import java.util.*;

class ReadFile{
	private Scanner x;

	public void open(){
		try{
			x = new Scanner(new File("1.txt"));
		}
		catch(Exception e){
			System.out.println("Error...");
		}
	}
	
	public void read(){
		while(x.hasNext()){
			char a = x.findInLine(".").charAt(0);
			String b = x.next();
			String c = x.next();
			
			System.out.printf("%c %s %s\n",a,b,c);
		}
	}
	
	public void close(){
		x.close();
	}
}

//RedaFile