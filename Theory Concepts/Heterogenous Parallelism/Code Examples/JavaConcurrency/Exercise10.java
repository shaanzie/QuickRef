import java.util.concurrent.*;
import java.util.*;
public class Exercise10 {

    // Make a concurrent data structure and compare performance

    private static final Queue queue = new ConcurrentLinkedQueue();
    private static final long startMillis = System.currentTimeMillis();

    public static class Consumer implements Runnable {
        public void run() {
            while (System.currentTimeMillis() < (startMillis + 10000)) {
                synchronized (queue) {
                    try {
                        queue.wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
                if (!queue.isEmpty()) {
                    Integer pop = Integer.parseInt(queue.poll().toString());
                    // System.out.println(Thread.currentThread().getName() + ": " + pop);
                }
            }
        }
    }
    public static class Producer implements Runnable {
        public void run() {
            int i = 0;
            while (System.currentTimeMillis() < (startMillis + 10000)) {
                
                synchronized (queue) {
                    queue.add(i++);
                    queue.notify();
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


    private static final Queue<Integer> queue2 = new ArrayDeque<Integer>();
    private static final long start = startMillis;

    public static class Consumer2 implements Runnable {

        public void run() {

            while(System.currentTimeMillis() < (start + 1000)) {

                    synchronized (queue2) {
                        try {
                            queue2.wait();
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }

                    if(!queue2.isEmpty()) {

                        String polled = queue2.poll().toString();
                        // System.out.println("Thread: " + Thread.currentThread().getName() + " " + polled);

                    }
                }
            }

        }

    }



    public static class Producer2 implements Runnable {

        public void run() {

            int i = 0; 
            while (System.currentTimeMillis() < (start + 1000)) {

                
                synchronized (queue2) {
                    queue2.add(i++);
                    queue2.notify();
                    // System.out.println("Thread producing: " + Thread.currentThread().getName());
                }
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

            synchronized (queue2) {
                queue2.notifyAll();
            }

        }

    }

    public static void main(String[] args) throws InterruptedException {
    
        long startTime = System.nanoTime();

        Thread[] consumerThreads = new Thread[5];
        for (int i = 0; i < consumerThreads.length; i++) {
            consumerThreads[i] = new Thread(new Consumer(), "consumer" + i);
            consumerThreads[i].start();
        }
        Thread[] producerThreads = new Thread[5];
        for (int i = 0; i < producerThreads.length; i++) {
            producerThreads[i] = new Thread(new Producer(), "producer" + i);
            producerThreads[i].start();
        }
        for (int i = 0; i < consumerThreads.length; i++) {
            consumerThreads[i].join();
        }
        for (int i = 0; i < producerThreads.length; i++) {
            producerThreads[i].join();
        }

        long endTime = System.nanoTime();

        System.out.println("Concurrent class: " + (endTime - startTime));

        startTime = System.nanoTime();

        Thread[] consumer2Threads = new Thread[5];
        for (int i = 0; i < consumer2Threads.length; i++) {
            consumer2Threads[i] = new Thread(new Consumer2(), "consumer2-" + i);
            consumer2Threads[i].start();
        }
        Thread[] producer2Threads = new Thread[5];
        for (int i = 0; i < producer2Threads.length; i++) {
            producer2Threads[i] = new Thread(new Producer2(), "producer2-" + i);
            producer2Threads[i].start();
        }
        for (int i = 0; i < consumer2Threads.length; i++) {
            consumer2Threads[i].join();
        }
        for (int i = 0; i < producer2Threads.length; i++) {
            producer2Threads[i].join();
        }

        endTime = System.nanoTime();

        System.out.println("Self-Built class: " + (endTime - startTime));

    }
}

