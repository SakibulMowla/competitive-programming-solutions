class Box{
	private double width, height, depth;
	
	Box(){
		width = height = depth = -1;
	}
	Box(double len){
		width = height = depth = len;
	}
	Box(Box ob){
		width = ob.width;
		height = ob.height;
		depth = ob.depth;
	}
	Box(double d, double h, double w){
		width = w;
		height = h;
		depth = d;
	}
	double volume(){
		return width * height * depth;
	}
}

class BoxWeight extends Box{
	double weight;
	
	BoxWeight(){
		super();
		weight = -1;
	}
	BoxWeight(BoxWeight ob){
		super(ob);
		weight = ob.weight;
	}
	BoxWeight(double d, double h, double w, double ww){
		super(d, h, w);
		weight = ww;
	}
	BoxWeight(double len, double m){
		super(len);
		weight = m;
	}
}

class Shipment extends BoxWeight{
	double cost;
	
	Shipment(){
		super();
		cost = -1;
	}
	Shipment(Shipment ob){
		super(ob);
		cost = ob.cost;
	}
	Shipment(double d, double h, double w, double ww, double c){
		super(d, h, w, ww);
		cost = c;
	}
	Shipment(double len, double m, double c){
		super(len, m);
		cost = c;
	}
}

class MultilevelInheritence{
	public static void main(String args[]){
		Shipment sm1 = new Shipment(10, 20, 15, 10, 3.41);
		Shipment sm2 = new Shipment(2, 3, 4, 0.76, 1.28);
		
		System.out.println("Volume of Shipment1 = " + sm1.volume());
		System.out.println("Weight of Shipment1 = " + sm1.weight);
		System.out.println("Cost of Shipment1 = " + sm1.cost);
		System.out.println();
		System.out.println("Volume of Shipment2 = " + sm2.volume());
		System.out.println("Weight of Shipment2 = " + sm2.weight);
		System.out.println("Cost of Shipment2 = " + sm2.cost);
	} 
}

//MultilevelInheritence