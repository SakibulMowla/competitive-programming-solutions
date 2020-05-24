import java.util.*;
import java.text.*;
 
class DateFormat{
	public static void main(String args[]){
		Date date = new Date();
		SimpleDateFormat ft = new SimpleDateFormat("y");
		int i;
		i = Integer.parseInt(ft.format(date));
		System.out.println(ft.format(date));
		System.out.println(i);
	}
}

//DateFormat