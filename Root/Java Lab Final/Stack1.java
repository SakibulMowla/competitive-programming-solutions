class stack{
	int arr[];
	int top;
	stack(int n){
		top = -1;
		arr = new int[n];
	}
	void push(int n){
		if(top == 9){
			System.out.println("Overflow...");
		} else {
			arr[++top] = n;
		}
	}
	int pop(){
		if(top==-1){
			System.out.println("Underflow...");
			return 0;
		}
		return arr[top--];
	}
}

class stck1{
	public static void main(String args[]){
		stack ob = new stack(10);
		int i;
		for(i=0;i<12;i++)
			ob.push(i);
		for(i=0;i<12;i++)
			System.out.println(ob.pop());
	}
}

//Stack1