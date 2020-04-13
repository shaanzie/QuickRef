
public class Exercise2 extends Thread {

    public Exercise2(String name) {
        super(name);
    }

    @Override
    public void run() {
        System.out.println("Executing thread " + Thread.currentThread().getName());
    }

    public static void main(String[] args) {
        Exercise2 test1 = new Exercise2("Testing-1");
        Exercise2 test2 = new Exercise2("Testing-2");
        Exercise2 test3 = new Exercise2("Testing-3");
        Exercise2 test4 = new Exercise2("Testing-4");
        Exercise2 test5 = new Exercise2("Testing-5");
        test1.start();
        test2.start();
        test3.start();
        test4.start();
        test5.start();
    }

}