// Demonstration of  abstract class
abstract class Shape
{
 int a;
 abstract void calculateArea();
 abstract void calculatePerimeter();
}// end Shape


class Circle extends Shape // sub/derived/child class of Shape
{

Circle()  //default constructor
{
a=0;
}

Circle(int r)  // parameterized constructor
{
a=r ;
}

void calculateArea() // method overdriding
{
double area=3.14*a*a;
System.out.println("Area of Circle is " + area);
}

void calculatePerimeter()
{
double p=2*3.14*a;
System.out.println("Perimeter of Circle is "+p);
}

}// end Circle

class Triangle extends Shape // sub/derived/child class of Shape
{

int b,c;

Triangle()  //default constructor
{
a=b=c=0;
}

Triangle(int a,int b, int c)  // parameterized constructor
{
this.a=a;
this.b=b;
this.c=c;
}

void calculateArea() // method overdriding
{
double s=(a+b+c)/2.0;
double area=Math.sqrt(s*(s-a)*(s-b)*(s-c));
System.out.println("Area of Triangle is " + area);
}

void calculatePerimeter()
{
double p=a+b+c;
System.out.println("Perimeter of  Triangle is "+p);
}

}// end Triangle

class AbsShapeDemo
{
public static void main(String s[])
{

Circle c1= new Circle(5);
Triangle t1=new Triangle(2,3,4);

c1.calculateArea();
c1.calculatePerimeter();

t1.calculateArea();
t1.calculatePerimeter();

} // end main
}// ShapeDemo
