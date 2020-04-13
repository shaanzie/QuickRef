
public class Exercise4 implements Runnable{

    public void run() {
        try {
            Thread.sleep(Long.MAX_VALUE);
        } catch (InterruptedException e) {
            System.out.println(("Error in " + Thread.currentThread().getName()));
        }
        while(!Thread.interrupted()) {

        }
        System.out.println("Thread: " + Thread.currentThread().getName());
    }

    public static void main(String[] args) throws InterruptedException{

        Thread test1 = new Thread(new Exercise4(), "Test1");
        test1.start();

        System.out.println("Thread: " + Thread.currentThread().getName() + "sleeps for 5s");
        Thread.sleep(5000);

        System.out.println("Thread: " + Thread.currentThread().getName() + " interrupted");
        test1.interrupt();

        System.out.println("Thread: " + Thread.currentThread().getName() + "sleeps for 5s");
        Thread.sleep(5000);

        System.out.println("Thread: " + Thread.currentThread().getName() + " interrupted");
        test1.interrupt();


    }

}