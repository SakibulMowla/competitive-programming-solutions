class A{
	A(){
		System.out.println("Inside A...");
	}
}

class B extends A{
	B(){
		System.out.println("Inside B...");
	}
}

class C extends B{
	C(){
		System.out.println("Inside C...");
	}
}

class CallingConstructors{
	public static void main(String args[]){
		C c = new C();
	}
}

//CallingConstructors