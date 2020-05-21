/* Name: Samuel Benedix
 Course: CNT 4714 Spring 2018
 Assignment title: Project 2 – Synchronized, Cooperating Threads Under Locking
 Due Date: February 14, 2018
*/


package benedix_hw2;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;
import java.util.logging.Level;
import java.util.logging.Logger;




// UnsynchronizedBuffer represents a single shared integer.
public class UnsynchronizedBuffer implements Buffer {
    
   private ReentrantLock lock = new ReentrantLock();
   Condition canWithdraw = lock.newCondition();
    
   public int buffer = 0; // shared by producer and consumer threads

   // place value into buffer
   public void set( int value )   {
      System.out.printf( "Producer writes\t%2d", value );
      buffer = value;
   } // end method set

   // return value from buffer
   public int get()   {
      System.out.printf( "Consumer reads\t%2d", buffer );
      return buffer; 
   } // end method get

   
   public void producer(int num, int numOfThread)
   {
       lock.lock();
       
       try{
       buffer+=num;
       
       System.out.println("Thread D" + numOfThread + " deposits $" + num + "\t \t \t \t \t \t Balance is $" + buffer);
       
       canWithdraw.signal();
       }
       finally{
       lock.unlock();
       }
       /*
       try {
           //canWithdraw.signal();
           Thread.sleep( 500 ); // sleep thread 
       } catch (InterruptedException ex) {
           Logger.getLogger(UnsynchronizedBuffer.class.getName()).log(Level.SEVERE, null, ex);
       }
       */
  
       
   }
   
   public void consumer(int num, int numOfThread)
   {
       lock.lock();
       try{
       
       if(buffer<num)
       {
           try {
               System.out.println("\t \t \t \t Thread W" + numOfThread + " withdraws $" + num + " Withdrawl - Blocked - Insufficient Funds");
               canWithdraw.await();
           } catch (InterruptedException ex) {
               Logger.getLogger(UnsynchronizedBuffer.class.getName()).log(Level.SEVERE, null, ex);
           }
           
           
       }
       
       
       if(buffer>num)
       {
           buffer-=num;
           //System.out.println("\t \t \t \t Thread W" + numOfThread + " withdraws $" + num + "\t \t Balance is $" + buffer);
           System.out.println("\t \t \t \t Thread W" + numOfThread + " withdraws $" + num + " \t Balance is $" + buffer);
       }
       
       
       }
       finally
       {
           lock.unlock();
       }
       
   }
   
} // end class UnsynchronizedBuffer

