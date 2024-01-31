interface Resizable {
  void resizeHeight(int height);
  void resizeWidth(int width);
}

class Rectangle implements Resizable {
  int w,h;

  public void resizeHeight(int height) {
    h = height;
  }

  public void resizeWidth(int width) {
    w = width;
  }

  void display() {
    System.out.println("Height =" + h);
    System.out.println("Width =" + w);
  }
}

class Resize {
  public static void main(String args[]) {
    Rectangle r = new Rectangle();
    r.resizeHeight(10);
    r.resizeWidth(5);
    r.display();
  }
}