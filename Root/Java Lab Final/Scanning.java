import java.util.Scanner;

class Scanning{
	public static void main(String args[]){
		Scanner scanner = new Scanner(System.in);
		/*int a = scanner.nextInt();
		int b = scanner.nextInt();
		System.out.printf("Sum of a+b = %d", a+b);
		
		boolean bool;
		bool = scanner.nextBoolean();
		System.out.println(bool);
		bool = scanner.nextBoolean();
		System.out.println(bool);
		
		byte bt;
		bt = scanner.nextByte();
		System.out.println("BT = " + bt);
		
		double d;
		d = scanner.nextDouble();
		System.out.println(d);
		
		float f;
		f = scanner.nextFloat();
		System.out.println(f);
		
		long l;
		l = scanner.nextLong();
		System.out.println(l);
		
		short s;
		s = scanner.nextShort();
		System.out.println(s);
		
		String ss;
		ss = scanner.nextLine();
		System.out.println(ss);*/
		
		char c;
		c = scanner.findInLine(".").charAt(0);
		System.out.println(c);
	}
}

//Scanning