class Test{
	int a, b;
	Test(int p, int q){
		a = p;
		b = q;
	}
	boolean equals(Test ob){
		if(ob.a == a && ob.b == b)
			return true;
		else
			return false;
	}
}

class ObjectParameter{
	public static void main(String args[]){
		Test ob1 = new Test(100,200);
		Test ob2 = new Test(1,2);
		Test ob3 = new Test(100,200);
		System.out.println("ob1 == ob2 " + ob1.equals(ob2));
		System.out.println("ob1 == ob3 " + ob1.equals(ob3));
	}
}

//ObjectParameter