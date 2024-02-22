interface Resizable
{
 void resizeWidth(int width);
 void resizeHeight(int height);
} //end interface


class Rectangle implements Resizable
{
  int w,h;

 public void resizeWidth(int width)
 {
   w=width;
 }

 public void resizeHeight(int height)
 {  
   h=height;
  } 

  void display()
  {
   System.out.println("width="+w);
   System.out.println("Height="+h);
   }//end display

}//end rectangle

class Resize
{
  public static void main(String args[])
    {
     Rectangle r=new Rectangle();
     r.resizeWidth(5); 
     r.resizeHeight(10);
     r.display();
     }
}//end Resize