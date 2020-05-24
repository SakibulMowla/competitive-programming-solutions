import java.util.*;

class FileCreating{
	public static void main(String args[]){
		Formatter x;
		
		try{
			x = new Formatter("File.txt");
			System.out.println("File created");
		}
		catch(Exception e){
			System.out.println("Exception occured");
		}
	}
}

//FileCreating