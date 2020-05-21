/* Name: Samuel Benedix
 Course: CNT 4714 Spring 2018
 Assignment title: Project 2 – Synchronized, Cooperating Threads Under Locking
 Due Date: February 14, 2018
*/
package benedix_hw2;

// Consumer's run method loops ten times reading a value from buffer.
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Consumer implements Runnable 
{ 
   private static Random generator = new Random();
   private Buffer sharedLocation; // reference to shared object
   public int numberThread;
   // constructor
   public Consumer( Buffer shared, int numOfThread )
   {
      sharedLocation = shared;
      numberThread = numOfThread;
      
   } // end Consumer constructor
 
   public void run()
   {
     
//int count = 1; count <= 10; count++ 
      for ( ; ; ) 
      {
          /*
          try {
              Thread.sleep( generator.nextInt( 30 ) ); // sleep thread
          } catch (InterruptedException ex) {
              Logger.getLogger(Consumer.class.getName()).log(Level.SEVERE, null, ex);
          }
*/
          int randomNumber = generator.nextInt(49) + 1;
          sharedLocation.consumer(randomNumber, numberThread);
          
          try {
              Thread.sleep(  generator.nextInt( 20 ) );
          } catch (InterruptedException ex) {
              Logger.getLogger(Consumer.class.getName()).log(Level.SEVERE, null, ex);
          }
          
          
      } // end for

   } // end method run
} // end class Consumer