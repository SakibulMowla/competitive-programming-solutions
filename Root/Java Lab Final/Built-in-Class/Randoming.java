import java.util.*;

class Randoming{
	public static void main(String args[]){
		Random rd = new Random();
		String s;
		
		for(int i=0;i<5;i++){
			s = "";
			for(int j=0;j<5;j++)
				if(j == 0)
					s += (char)('A'+ rd.nextInt(26));
				else
					s += (char)('a'+ rd.nextInt(26));
			System.out.println(s);
		}
	}
}

//Randoming