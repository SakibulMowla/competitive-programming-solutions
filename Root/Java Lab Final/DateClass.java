import java.util.*;
import java.text.*;

class DateClass{
	public static void main(String args[]){
		//Date dt = new Date();
		//System.out.println(dt.toString());
		
		//SimpleDateFormat ft = new SimpleDateFormat("E yyyy.MM.dd G 'at' hh:mm:ss a zzz");
		//SimpleDateFormat ft = new SimpleDateFormat("yyyy");
		//System.out.println("Current Date = "+ft.format(dt));
		
		//String str = String.format("Current Date = %tc",dt);
		//System.out.println(str);
		
		Scanner r = new Scanner(System.in); 
		
		SimpleDateFormat ft = new SimpleDateFormat("yyyy-MM-dd hh:mm");
		String s;
		s = r.nextLine();
		
		Date dt;
		
		try{
			dt = ft.parse(s);
			System.out.println(dt);
		}
		catch(ParseException e){
			System.out.println("Error");
		}
	}
}

//DateClass