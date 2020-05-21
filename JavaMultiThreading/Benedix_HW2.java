/* Name: Samuel Benedix
 Course: CNT 4714 Spring 2018
 Assignment title: Project 2 – Synchronized, Cooperating Threads Under Locking
 Due Date: February 14, 2018
*/


package benedix_hw2;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/**
 *
 * @author Shadow
 */
public class Benedix_HW2 {

    /**
     * @param args the command line arguments
     */
    
  //  public int lock = 0;
            
    public static void main(String[] args) {
      // TODO code application logic here
      /*
       PrintChar printA = new PrintChar('a', 20);  
       PrintChar printB = new PrintChar('b', 20);   
       PrintNum  print20 = new PrintNum(20);
      
      // Start threads
      
        print20.start();// try {print20.sleep(5000);}catch(InterruptedException e){}
        printA.start(); // try {printA.sleep(5000);} catch(InterruptedException e) {}
	printB.start();
        */
       // PrintTask sam = new PrintTask("HELLO");
       
       
         // create new thread pool with two threads
         
         
         
         
         
         
         
         
      ExecutorService application = Executors.newFixedThreadPool( 10 );

      // create UnsynchronizedBuffer to store ints
      Buffer sharedLocation = new UnsynchronizedBuffer();
      
      System.out.println( "Deposite Threads\t \t Withdrawl Threads \t \t Balance" );
      System.out.println( "-----------------\t \t ----------------- \t \t---------\n" );

      // try to start producer and consumer giving each of them access to SharedLocation
	try  {
            
         application.execute( new Producer( sharedLocation, 1) );
         application.execute( new Consumer( sharedLocation, 1) );
         application.execute( new Producer( sharedLocation, 2) );
         application.execute( new Consumer( sharedLocation, 5) );
         application.execute( new Producer( sharedLocation, 3) );
         application.execute( new Consumer( sharedLocation, 3) );
         application.execute( new Producer( sharedLocation, 4) );
         application.execute( new Consumer( sharedLocation, 4) );
         application.execute( new Consumer( sharedLocation, 2) );
         application.execute( new Consumer( sharedLocation, 6) );
            
      } // end try
      catch ( Exception exception ) {
         exception.printStackTrace();
      } // end catch

      application.shutdown(); // terminate application when threads e
       
        
      
      
      
      
      
      
        
    }
    
}

class PrintChar extends Thread {
	  private char charToPrint;  // The character to print
	  private int times;  // The number of times to repeat the character

	  // Construct a thread with specified character and number of times to print the character
	  public PrintChar(char c, int t) {
	    charToPrint = c;
	    times = t;
	  }

	  // Override the run() method to tell the system what the thread will do
	  public void run() {
	    for (int i = 0; i < times; i++)
	      System.out.print(charToPrint);
	  }
	}

	// The thread class for printing a number n a specified number of times
	class PrintNum extends Thread {
	  private int lastNum;

	  // Construct a thread for print 1, 2, ... i 
	  public PrintNum(int n) {
	    lastNum = n;
	  }

	  // Tell the thread how to run 
	  public void run() {
	    for (int i = 1; i <= lastNum; i++)
	      System.out.print(" " + i);
	  }
	}//end class TestThread