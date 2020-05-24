import java.util.Random;

interface ifc{
	int no = 1;
	int yes = 2;
	int vgood = 3;
}

class qsn implements ifc{
	Random rand = new Random();
	int ask(){
		int n = (int)(100 * rand.nextDouble());
		//System.out.println("Random = " + n);
		if(n < 30)
			return no;
		else if(n < 60)
			return yes;
		else
			return vgood;
	}
}

class InterfacePlusStatic implements ifc{
	static void answer(int r){
		switch(r){
			case no:
				System.out.println("NO");
				break;
			case yes:
				System.out.println("YES");
				break;
			case vgood:
				System.out.println("Very Good");
				break;
		}
	}
	
	public static void main(String args[]){
		qsn ob = new qsn();
		
		answer(ob.ask());
		answer(ob.ask());
		answer(ob.ask());
		answer(ob.ask());
		answer(ob.ask());
		answer(ob.ask());
	}
}


//InterfacePlusStatic