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

void setXY()
{
Scanner sc=new Scanner(System.in);
System.out.println("Enter the X value");
x=sc.nextInt();
System.out.println("Enter the yvalue");
y=sc.nextInt();
}

int[] getXY()
{
int a[]=new int[2];
a[0]=x;
a[1]=y;
return (a);
}

public String toString()
{
 String st= "(" + x + "," + y + ")" ;
 return(st);
}

}//end MyPoint

class PointDemo
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

 }//end main
}//end Demo
   