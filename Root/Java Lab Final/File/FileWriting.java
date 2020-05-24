import java.util.*;
import java.io.*;
import java.lang.*;

class Filing{
	Formatter x;
	
	public void OpenFile(){
		try{
			x = new Formatter("output.txt");
		}
		catch(Exception e){
			System.out.println("Error Occured");
		}
	}
	
	public void AddRecord(){
		Random rand = new Random();
		int i, j;
		String s;
		for(i=0;i<26;i++){
			s = "";
			for(j=0;j<5;j++){
				s += (char)('A'+rand.nextInt(26));
			}
			x.format("%s\n",s);
		}
	}
	
	public void CloseFile(){
		x.close();
	}
}

class Filing1{
	Formatter x;
	
	public void OpenFile(){
		try{
			x = new Formatter("output.txt");
		}
		catch(Exception e){
			System.out.println("Error Occured");
		}
	}
	
	public void AddRecord(String s){
		x.format("%s\n",s);
	}
	
	public void CloseFile(){
		x.close();
	}
}


class Filing2{
	Formatter x;
	
	public void OpenFile(){
		try{
			x = new Formatter("output.txt");
		}
		catch(Exception e){
			System.out.println("Error Occured");
		}
	}
	
	public void AddRecord(String s){
		x.format("%s\n",s);
	}
	
	public void CloseFile(){
		x.close();
	}
}

class FileWriting{
	public static void main(String args[]){
		Filing f = new Filing();
		
		f.OpenFile();
		f.AddRecord();
		f.CloseFile();
		
		Scanner sc = new Scanner(new File(RandomDNA.txt));
		Filing1 f1 = new Filing();
		
		f1.OpenFile();
		
		while(sc.hasNwxt()){
			f1.AddRecord();
		}
	}
}

//FileWriting