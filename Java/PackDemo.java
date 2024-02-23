//Package to be saved as BOX.java in folder(p1)
package p1;

public class BOX {
    int l, b;

    // Constructor without parameters
    public BOX() {
        l = 10;
        b = 10;
    }

    // Constructor with parameters
    public BOX(int l, int b) {
        this.l = l;
        this.b = b;
    }

    // Method to display the values
    public void show() {
        System.out.println("From Box\n L=" + l + "\n B=" + b);
    }
}

//Main Program
import p1.*;
class PackDemo{
    public static void main(String args[]){
        BOX b1=new BOX();
        BOX b2=new BOX(2,3);
        b1.show();
        b2.show();
    }
}
