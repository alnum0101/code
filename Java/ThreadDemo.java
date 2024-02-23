// Program 11

// Create a class implementing the Runnable interface
class NewThread implements Runnable {
  // Declare a Thread object
  Thread t;

  // Constructor for the NewThread class
  NewThread() {
    // Initialize the Thread object with the current instance and a name "Demo Thread"
    t = new Thread(this, "Demo Thread");
    
    // Display information about the child thread
    System.out.println("Child Thread: " + t);
    
    // Start the child thread
    t.start();
  }

  // Entry point for the child thread
  public void run() {
    try {
      // Loop to display countdown in the child thread
      for (int i = 5; i > 0; i--) {
        System.out.println("Child thread: " + i);
        
        // Pause the thread for 500 milliseconds
        Thread.sleep(500);
      }
    } catch (InterruptedException e) {
      // Handle interruption exception
      System.out.println("Child thread interrupted:");
    }
    
    // Display a message indicating the child thread is exiting
    System.out.println("Exiting child thread.");
  }
}

// Main class for the program
class ThreadDemo {
  // Entry point for the main thread
  public static void main(String s[]) {
    // Create an instance of the NewThread class, which starts a child thread
    new NewThread();
    
    try {
      // Loop to display countdown in the main thread
      for (int i = 5; i > 0; i--) {
        System.out.println("Main thread: " + i);
        
        // Pause the main thread for 1000 milliseconds
        Thread.sleep(1000);
      }
    } catch (InterruptedException e) {
      // Handle interruption exception for the main thread
      System.out.println("Main thread interrupted");
    }
    
    // Display a message indicating the main thread is exiting
    System.out.println("Main thread exiting");
  }
}
