class Test{
	void cal(int i, int j){
		i *= 2;
		j /= 2;
	}
}

class PassByVal{
	public static void main(String args[]){
		Test ob = new Test();
		int a = 15, b = 10;
		
		System.out.println("a & b before call " + a + " " + b);
		
		ob.cal(a, b);
		
		System.out.println("a & b after call " + a + " " + b);
	}
}

//PassByValue