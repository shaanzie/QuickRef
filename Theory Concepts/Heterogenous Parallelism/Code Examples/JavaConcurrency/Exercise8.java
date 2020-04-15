import java.util.ArrayDeque;
import java.util.Queue;
// import java.util.concurrent.ConcurrentLinkedQueue;


public class Exercise8 {
    
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

        Thread consumerThread = new Thread(new Consumer(), "consumer");
        consumerThread.start();
        Thread producerThread = new Thread(new Producer(), "producer");
        producerThread.start();
        consumerThread.join();
        producerThread.join();
    }
}