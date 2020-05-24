import java.text.*;
import java.util.*;
import java.io.*;

class GenerateDate{
	public static void main(String args[]){
		Calendar cal = Calendar.getInstance();
		cal.set(2014, Calendar.MARCH, 5, 3, 5, 0);
		Date dt = cal.getTime();
		
		System.out.println(dt.toString());
	}
}

//GenerateDate