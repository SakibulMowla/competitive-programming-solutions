class A{
	int a, b;
	A(int a, int b){
		this.a = a;
		this.b = b;
	}
	void show(){
		System.out.println("a = " + a + " b = " + b);
	}
}

class B extends A{
	int c;
	B(int a, int b, int c){
		super(a, b);
		this.c = c;
	}
	void show(){
		super.show();
		System.out.println("c = " + c);
	}
}

class Overriding{
	public static void main (String args[]){
		B b = new B(1, 2, 3);
		b.show();
	}
}

//Overriding