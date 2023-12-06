/*add two matrices*/
import java.util.*;
class AddMat
{
   public static void main(String args[])
   {
     if (args.length<2)
     {    
       System.out.println(" No Input");
       System.exit(0); 
      }
 
     Scanner sc=new Scanner(System.in);
     int m=Integer.parseInt(args[0]);
     int n=Integer.parseInt(args[1]);

     int i,j;
     int a[][]=new int[m][n]; // declare array
     int b[][]=new int[m][n]; // declare array
     int c[][]=new int[m][n]; // declare array

    System.out.println("Enter the elements of Matrix 1");
    for(i=0;i<m;i++)
      for(j=0;j<n;j++)
         a[i][j]=sc.nextInt();
    
    System.out.println("Enter the elements of Matrix 2");
    for(i=0;i<m;i++)
      for(j=0;j<n;j++)
      {
         b[i][j]=sc.nextInt();
         c[i][j]=a[i][j]+b[i][j];
       }

      System.out.println("Matrix 1");
      for(i=0;i<m;i++)
      {
         for(j=0;j<n;j++)
            System.out.print(a[i][j]+" ");
         System.out.println();
       }
     
      System.out.println("Matrix 2");
      for(i=0;i<m;i++)
      {
         for(j=0;j<n;j++)
            System.out.print(b[i][j]+" ");
         System.out.println();
       }

      System.out.println("Resultant Matrix ");
      for(i=0;i<m;i++)
      {
         for(j=0;j<n;j++)
            System.out.print(c[i][j]+" ");
         System.out.println();
       }  
 }// end main
} // end class
  