// Demonstrate an inner class.
class Outer 
{
  int x = 100;

 class Inner 
 {
  void display() 
 {
   System.out.println("Inner_display: x = " + x);
  }// inner class display
 } //end inner class

 void display()
 {
   System.out.println("Outer_display: x = " + x);
   Inner in = new Inner();
   in.display();
 }// outer class display

}// end outer class

class InnerClassDemo 
{
 public static void main(String args[])
 {
   Outer out = new Outer();
   out.display();

}
}