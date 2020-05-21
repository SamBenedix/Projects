/* Name: Samuel Benedix
 Course: CNT 4714 Spring 2018
 Assignment title: Project 2 – Synchronized, Cooperating Threads Under Locking
 Due Date: February 14, 2018
*/

package benedix_hw2;
// Buffer interface specifies methods called by Producer and Consumer.

public interface Buffer 
{
   public void set( int value ); // place int value into Buffer
   public int get(); // return int value from Buffer
   public void producer(int num, int numOfThread);
   public void consumer(int num, int numOfThread);
} // end interface Buffer
