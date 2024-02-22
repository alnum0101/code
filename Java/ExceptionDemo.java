// Custom exception type.

import java.util.*;

class DivisionByZero extends Exception
{
 public String toString()
 {
  return ("Divide By Zero Error");
  }
}// end divison

class ExceptionDemo 
{
public static void main(String args[]) 
{
Scanner sc=new Scanner(System.in);
System.out.println("Enter the first value");
int a=sc.nextInt();
System.out.println("Enter the second value");
int b=sc.nextInt();
try 
{
   if(b==0)
        throw new DivisionByZero();  
    int c=a/b;
    System.out.println(a+"/"+b+"="+c);
 } catch (DivisionByZero e)
  {
   System.out.println("Exception: " + e);
  }finally
  {
    System.out.println("After Exception");
  }


}//end main
}//end class