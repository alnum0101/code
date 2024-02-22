import java.util.*;
class MyPoint
{
int x, y;

MyPoint() // default constructor
{
 x=y=0;
}

MyPoint(int x, int y) //pzrmeterized constructor
{
 this.x=x;
 this.y=y;
}

void setXY() // set x and y value
{
Scanner sc=new Scanner(System.in);
System.out.println("Enter the X value");
x=sc.nextInt();
System.out.println("Enter the yvalue");
y=sc.nextInt();
}

int[] getXY()  // return x and y value
{
int a[]=new int[2];
a[0]=x;
a[1]=y;
return (a);
}

double distance(int x, int y) // between object and point
{
  double d=Math.sqrt((x-this.x)*(x-this.x)+(y-this.y)*(y-this.y));
  return(d);
}


double distance(MyPoint p) // between objects
{
  double d=Math.sqrt((p.x-x)*(p.x-x)+(p.y-y)*(p.y-y));
  return(d);
}

double distance() // from origin
{
  double d=Math.sqrt(x*x+y*y);
  return(d);
}

public String toString()  // print object
{
String st= "(" + x + "," + y + ")" ;
return(st);
}

}//end MyPoint

class TestMyPoint
{
  public static void main(String s[])
 {
  MyPoint m1=new MyPoint();
  MyPoint m2=new MyPoint(3,4);
  MyPoint m3=new MyPoint();

  m3.setXY();

  int a[]=new int[2];
  a=m1.getXY();
 System.out.println("x="+a[0]+",y="+a[1]);
  a=m2.getXY();
  System.out.println("x="+a[0]+",y="+a[1]);
  a=m3.getXY();
  System.out.println("x="+a[0]+",y="+a[1]);
  System.out.println(m1);
 System.out.println(m2);
 System.out.println(m3);

 double d=m2.distance(5,6);
 System.out.println("Distance between 2 points is "+d);

 d=m2.distance(m3);
 System.out.println("Distance between m2 and m3 points is "+d);

 d=m2.distance();
 System.out.println("Distance between origin and point is "+d);
 }//end main
}//end Demo
   