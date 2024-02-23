// Autoboxing/unboxing occurs inside expressions.
class AutoBox 
{
 public static void main(String args[]) 
 {
  Integer iOb, iOb2;
  int i;
  iOb = 100;
  System.out.println("Original value of iOb: " + iOb);

  // automatically unboxes iOb, performs the increment, reboxes result back into iOb.
  ++iOb;
  System.out.println("After ++iOb: " + iOb);

  //  iOb is unboxed,expression is evaluated,  the result is reboxed and assigned to iOb2.
  iOb2 = iOb + (iOb / 3);
  System.out.println("iOb2 after expression: " + iOb2);

   // The same expression is evaluated, but the result is not reboxed.
   i = iOb + (iOb / 3);
  System.out.println("i after expression: " + i);
  }//end main
}//end class