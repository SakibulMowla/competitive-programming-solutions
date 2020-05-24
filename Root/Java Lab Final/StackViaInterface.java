interface IntStack{
	void push(int item);
	int pop();
}

class FixedStack implements IntStack{
	private int stck[];
	private int top;
	
	FixedStack(int sz){
		stck = new int[sz];
		top = -1;
	}
	
	public void push(int item){
		if(top == stck.length-1){
			System.out.println("Overflow...");
		} else {
			stck[++top] = item;
		}
	}
	
	public int pop(){
		if(top == -1){
			System.out.println("Underflow...");
			return -1111111;
		} else {
			return stck[top--];
		}
	}
}

class DynStack implements IntStack{
	private int stck[];
	private int top;
	
	DynStack(int sz){
		stck = new int[sz];
		top = -1;
	}
	
	public void push(int item){
		if(top == stck.length-1){
			int tmp[] = new int[stck.length * 2];
			for(int i=0; i<stck.length; i++)
				tmp[i] = stck[i];
			stck = tmp;
		}
		stck[++top] = item;
	}
	
	public int pop(){
		if(top < 0){
			System.out.println("Underflow...");
			return -1111111;
		}
		return stck[top--];
	}
}

class StackViaInterface{
	public static void main(String args[]){
		IntStack mystack;
		DynStack ds = new DynStack(5);
		FixedStack fs = new FixedStack(8);
		
		mystack = ds;
		for(int i=0; i<12; i++) mystack.push(i);
		
		mystack = fs;
		for(int i=0; i<8; i++) mystack.push(i);
		
		mystack = ds;
		for(int i=0; i<12; i++) System.out.println(mystack.pop());
		
		mystack = fs;
		for(int i=0; i<8; i++) System.out.println(mystack.pop());
	}
}

//StackViaInterface