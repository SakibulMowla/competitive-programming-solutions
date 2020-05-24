import java.util.*;

class Filing{
	public static void main(String args[]){
		/*CreateFile cf = new CreateFile();
		
		cf.open();
		cf.add();
		cf.close();*/
		
		ReadFile rf = new ReadFile();
		
		rf.open();
		rf.read();
		rf.close();
	}
}

//Filing