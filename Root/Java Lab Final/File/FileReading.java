import java.io.*;
import java.util.*;
import java.lang.*;

class Read{
	Scanner x;
	
	public void OpenFile(){
		try{
			x = new Scanner(new File("output.txt"));
		}
		catch(Exception e){
			System.out.println("Error occured");
		}
	}
	
	public void ReadFile(){
		String s;
		char ch;
		int i;
		
		while(x.hasNext()){
			i = x.nextInt();
			s = x.next();
			System.out.println("sjdhcb " + i + " " + s);
		}
	}
	
	public void FileClose(){
		x.close();
	}
}

class FileReading{
	public static void main(String args[]){
		
		Read r = new Read();
		
		r.OpenFile();
		r.ReadFile();
		r.FileClose();
		
	}
}

//FileReading