class Outer{
	int x = 17;
	void test(){
		int i;
		for(i=0;i<17;i++){
			class Inner{
				void show(int i){
					System.out.println("i = " + i + " Show x = " + x);
				}
			}
			Inner inner = new Inner();
			inner.show(i);
		}
	}
}

class NestedClass{
	public static void main(String args[]){
		Outer outer = new Outer();
		outer.test();
	}
}

//NestedClass