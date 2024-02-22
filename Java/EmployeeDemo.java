import java.util.*;
class Employee
{
int Empid;
String  Ename;
float Esalary,incr=0;

void assign()
{
Scanner sc=new Scanner(System.in);
System.out.println("Enter the Employee Id");
Empid=sc.nextInt();
System.out.println("Enter the Employee Name");
Ename=sc.next();
System.out.println("Enter the Employee Salary");
Esalary=sc.nextFloat();
}//end assign

void raiseSalary(float p)
{
incr=Esalary*p/100; 
}//end raisesalary

void display()
{
System.out.println("Employee Info");
System.out.println("Employee ID: "+ Empid);
System.out.println("Name: "+ Ename);
System.out.println("Salary: Rs."+ Esalary);
System.out.println("Salary Increment: Rs."+ incr);
Esalary=Esalary+incr;
System.out.println("Revised Salary: Rs."+ Esalary);
}// end display
}//end Employee Class

class EmployeeDemo
{
 public static void main(String s[])
{
  Scanner sc=new Scanner(System.in);
  Employee e1=new Employee();
  e1.assign();

  System.out.println("Enter the percentage of salary increment");
  float p=sc.nextFloat();
  e1.raiseSalary(p);
  e1.display();
 }//end main
}// demo class