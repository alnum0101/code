class Outer {
  int x = 100;
  class Inner {
    void display() {
      System.out.println("Inner_display: x=" + x);
    }
  } //end Inner
  void display() {
    System.out.println("Outer_display: x=" + x);
    Inner in = new Inner();
    in.display();
  }
} //end Outer

class InnerClassDemo {
  public static void main(String args[]) {
    Outer out = new Outer();
    out.display();
  }
} //end Demo
