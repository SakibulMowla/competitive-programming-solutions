import java.util.*;
import java.io.*;
import java.lang.*;

class CreateFile{
	private Formatter x;
	
	public void open(){
		try{
			x = new Formatter("Out.txt");
		}
		catch(Exception e){
			System.out.println("Error");
		}
	}
	
	public void add(){
		x.format("%s %s %s\n","I ", " am" , " me");
		x.format("%d %d %d\n",2,3,4);
		x.format("%f %f %f\n",1.23,.32323,43.24);
		x.format("%.12f %.12f %.12f\n",1.23,.32323,43.24);
		x.format("This is file\n");
	}
	
	public void close(){
		x.close();
	}
}

//CreateFile