public class Exercise3 implements Runnable {

    public void run() {
        System.out.println("Executing thread: " + Thread.currentThread().getName());
    }

    public static void main(String[] args) {

        Thread test1 = new Thread(new Exercise3(), "test1");
        Thread test2 = new Thread(new Exercise3(), "test2");
        Thread test3 = new Thread(new Exercise3(), "test3");
        Thread test4 = new Thread(new Exercise3(), "test4");
        Thread test5 = new Thread(new Exercise3(), "test5");
        
        test1.start();
        test2.start();
        test3.start();
        test4.start();
        test5.start();

    }

}