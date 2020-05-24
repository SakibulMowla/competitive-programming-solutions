class A{
	void call(){
		System.out.println("Inside A...");
	}
}

class B extends A{
	void call(){
		System.out.println("Inside B...");
	}
}

class C extends B{
	void call(){
		System.out.println("Inside C...");
	}
}

class DynamicMethodDispatch{
	public static void main(String args[]){
		A a = new A();
		B b = new B();
		C c = new C();
	
		A r;
		
		r = a;
		r.call();
		r = b;
		r.call();
		r = c;
		r.call();
	}
}

//DynamicMethodDispatch