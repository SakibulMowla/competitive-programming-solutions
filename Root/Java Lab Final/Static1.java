class Static1{
	static int a = 5;
	static int b;
	static void print(int x){
		System.out.println("x = " + x);
		System.out.println("a = " + a);
		System.out.println("b = " + b);
	}
	static {
		System.out.println("Initializing...");
		b = a * 5;
	}
	public static void main(String args[]){
		print(17);
	}
}

//Static1