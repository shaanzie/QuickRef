import java.util.Random; 

public class Exercise5 implements Runnable {
    // Join example

    private Random rand = new Random(System.currentTimeMillis());
    
    
    public void run() {

        for(int i=0; i<100000000; i++) {
            rand.nextInt();
        }

        System.out.println("Thread: " + Thread.currentThread().getName());
    }
    public static void main(String[] args) throws InterruptedException {
        Thread[] threads = new Thread[5];
        
        for(int i=0; i<threads.length; i++) {
            threads[i] = new Thread(new Exercise5(), "thread-"+i);
            threads[i].start();
        }
        
        for(int i=0; i<threads.length; i++) {
            threads[i].join();
        }
        
        System.out.println("All threads have finished");
    }

}