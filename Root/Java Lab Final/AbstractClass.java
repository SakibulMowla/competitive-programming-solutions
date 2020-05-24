abstract class Figure{
	double dim1, dim2;
	Figure(double a, double b){
		dim1 = a;
		dim2 = b;
	}
	abstract double area();
}

class Rectangle extends Figure{
	Rectangle(double a, double b){
		super(a, b);
	}
	double area(){
		System.out.println("Area of Rectangle...");
		return dim1 * dim2;
	}
}

class Triangle extends Figure{
	Triangle(double a, double b){
		super(a, b);
	}
	double area(){
		System.out.println("Area of Triangle...");
		return dim1 * dim2 / 2;
	}
}

class AbstractClass{
	public static void main(String args[]){
		Rectangle r = new Rectangle(10, 10);
		Triangle t = new Triangle(10, 10);
		
		Figure ff;
		
		ff = r;
		System.out.println(ff.area());
		
		ff = t;
		System.out.println(ff.area());
	}
}

//AbstractClass