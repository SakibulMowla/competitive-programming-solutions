import java.io.File;

class FileExists{
	public static void main(String args[]){
		File x = new File("1.txt");
		
		if(x.exists())
			System.out.println(x.getName() + " exists");
		else
			System.out.println("Doesn't exists");
	}
}

//FileExists