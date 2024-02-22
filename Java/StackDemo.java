import java.util.*;
class Stack
{
  int size=10, top=-1;
  int s[]=new int[size];

void push(int item)
{ 
  if(top==size-1)
      System.out.println("Stack is Full");
  else
       s[++top]=item;
} // end push

int pop()
{
 if(top<0)
{
     System.out.println("Stack is Empty");
     return(-1);
 }
else
    return(s[top--]);
}//end pop

void display()
{ 
  if(top<0)
      System.out.println("Stack is Empty");
  else
    {
       System.out.println("Stack Elements are:");
       for(int i=top;i>=0;i--)
            System.out.println(s[i]);
    }
}//end display

} //stack class end


class StackDemo
{
   public static void main(String args[])
   {
     int item, ch;
     Stack st=new Stack();
     Scanner sc=new Scanner(System.in);
     while(true)
     {
      System.out.println("\nStack\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
      System.out.println("Enter your choice");
      ch=sc.nextInt();
      switch(ch)
      {
        case 1:  System.out.println("Enter the element to be inserted into stack");
                     item=sc.nextInt();
                      st.push(item);        
                      break;
      
       case 2:   item=st.pop();
                      if(item!=-1) System.out.println("Popped Element is "+item);
                      break;
   
      case 3:  st.display();
                    break;
 
      case 4: System.exit(0);
    } //end switch
  } //end while
 }//end main
} //end StackDemo