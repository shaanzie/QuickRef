import java.util.ArrayDeque;
import java.util.Queue;
// import java.util.concurrent.ConcurrentLinkedQueue;


public class Exercise9 {
    
    private static final Queue<Integer> queue = new ArrayDeque<Integer>();
    private static final long startMillis = System.currentTimeMillis();

    public static class Consumer implements Runnable {

        public void run() {

            while(System.currentTimeMillis() < (startMillis + 1000)) {

                    synchronized (queue) {
                        try {
                            queue.wait();
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }

                    if(!queue.isEmpty()) {

                        String polled = queue.poll().toString();
                        System.out.println("Thread: " + Thread.currentThread().getName() + " " + polled);

                    }
                }
            }

        }

    }



    public static class Producer implements Runnable {

        public void run() {

            int i = 0; 
            while (System.currentTimeMillis() < (startMillis + 1000)) {

                
                synchronized (queue) {
                    queue.add(i++);
                    queue.notify();
                    System.out.println("Thread producing: " + Thread.currentThread().getName());
                }
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

            synchronized (queue) {
                queue.notifyAll();
            }

        }

    }


    public static void main(String[] args) throws InterruptedException {
        // N consumers and producers

        // Command line
        int consumers = Integer.parseInt(args[0]);
        int producers = Integer.parseInt(args[1]);
        
        Thread[] consumerThread = new Thread[consumers];
        for(int i = 0; i<consumers; i++)
        {    consumerThread[i] = new Thread(new Consumer(), "Consumer" + i);
            consumerThread[i].start();
        }
        
        Thread[] producerThread = new Thread[producers];
        for(int i = 0; i<producers; i++)
        {    
            producerThread[i] = new Thread(new Producer(), "producer" + i);
            producerThread[i].start();
        }
        for (int i = 0; i < consumerThread.length; i++) {
            consumerThread[i].join();
        }
        for (int i = 0; i < producerThread.length; i++) {
            producerThread[i].join();
        }
    }
}