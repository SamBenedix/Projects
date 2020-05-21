/* Name: Samuel Benedix
 Course: CNT 4714 Spring 2018
 Assignment title: Project 2 – Synchronized, Cooperating Threads Under Locking
 Due Date: February 14, 2018
*/

package benedix_hw2;
// Producer's run method stores the values 1 to 10 in buffer.
import java.util.Random;

public class Producer implements Runnable 
{
   private static Random generator = new Random();
   private Buffer sharedLocation; // reference to shared object
   public int producerlock;
   // constructor
   
  public int numberThread;
   
   public Producer( Buffer shared, int numOfThread)
   {
      sharedLocation = shared;
      numberThread = numOfThread;
     
      
   } // end Producer constructor
  
   public void run()
   {
      for ( ; ;) 
      {  
          
         try // sleep 0 to 3 seconds, then place value in Buffer
         {
             
           int randomNumber = generator.nextInt(199) + 1;
           
           sharedLocation.producer(randomNumber, numberThread);
           
           Thread.sleep(  generator.nextInt(70) ); // sleep thread 
           
       
            
            
         } // end try
         // if sleeping thread interrupted, print stack trace
         catch ( InterruptedException exception ) 
         {
            exception.printStackTrace();
         } // end catch

      } // end for

   } // end method run
} // end class Producer