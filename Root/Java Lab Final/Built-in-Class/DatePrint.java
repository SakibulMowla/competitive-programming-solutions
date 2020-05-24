import java.util.Date;

class DatePrint {
	public static void main(String args[]) {
		Date date = new Date();
		//Date date1 = new Date();
		System.out.println(date.toString());
		int i, j=0;
		for(i=0;i<1000000000;i++) j = j^j;
		Date date1 = new Date();
		System.out.println(date1.toString());
	}
}

//DatePrint