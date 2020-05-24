import java.util.Random;

class Randoming{
	public static void main(String args[]){
		Random r = new Random();
		
		int n = 5;
		
		/*boolean bool;
		while(n-- > 0){
			bool = r.nextBoolean();
			System.out.println(bool);
		}*/
		/*
		int i;
		while(n-- > 0){
			i = r.nextInt(10000);
			System.out.println(i);
		}*/
		/*
		long l;
		while(n-- > 0){
			l = r.nextLong();
			System.out.println(l);
		}*/
		/*
		double d;
		while(n-- > 0){
			d = r.nextDouble();
			System.out.println(d);
		}*/
		/*
		float f;
		while(n-- > 0){
			f = r.nextFloat();
			System.out.println(f);
		}*/
		double d;
		while(n-- > 0){
			d = r.nextGaussian();
			System.out.println(d);
		}
	}
}

//Randoming