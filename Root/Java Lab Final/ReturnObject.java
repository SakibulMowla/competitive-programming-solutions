class Test{
	int a;
	Test(int a){
		this.a = a;
	}
	Test incr100(Test ob){
		Test tmp = new Test(ob.a+100);
		return tmp;
	}
}

class ReturnObject{
	public static void main(String args[]){
		Test ob1 = new Test(17);
		Test ob2;
		ob2 = ob1.incr100(ob1);
		System.out.println("ob1 & ob2 = " + ob1.a + " " + ob2.a);
		ob2 = ob2.incr100(ob2);
		System.out.println("ob1 & ob2 = " + ob1.a + " " + ob2.a);
	}
}

//ReturnObject