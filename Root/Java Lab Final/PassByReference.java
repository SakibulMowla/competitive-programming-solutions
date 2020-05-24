class Test{
	int i, j;
	Test(int i, int j){
		this.i = i;
		this.j = j;
	}
	void cal(Test ob){
		ob.i *= 2;
		ob.j /= 2;
	}
}

class PassByRef{
	public static void main(String args[]){
		Test ob = new Test(15, 10);
		
		System.out.println("i & j before call "+ ob.i +" "+ ob.j);
		
		ob.cal(ob);
		
		System.out.println("i & j after call "+ ob.i +" "+ ob.j);
	}
}

//PassByReference