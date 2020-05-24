class Box{
	double height, width, length;
	Box(double height, double width, double length){
		this.height = height;
		this.width = width;
		this.length = length;
	}
	double volume(){
		return height*length*width;
	}
}

class BoxDemo{
	public static void main(String args[]){
		Box mybox1 = new Box(10, 10, 10);
		Box mybox2 = new Box(-1, -1, -1);
		System.out.println("Volume of mybox1 " + mybox1.volume());
		System.out.println("Volume of mybox2 " + mybox2.volume());
	}
}