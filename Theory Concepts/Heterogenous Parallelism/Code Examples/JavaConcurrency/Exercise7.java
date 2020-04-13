
import java.util.Random; 

public class Exercise7 {

    private static int account = 0;

    public static class Withdrawer implements Runnable {

        public synchronized void run() {
            
            Random rand = new Random();

                if(account < 1000) {
                    System.out.println("Below Minimum balance, cannot withdraw");
                }
                else {
                    account -= rand.nextInt(1000);
                    System.out.println("Account balance is: " + account);
                }

        }
        
    }

    public static class Depositor implements Runnable{

        Random rand = new Random();
        
        public synchronized void run() {
                account += rand.nextInt(1000);
                System.out.println("Account balance is: " + account);
        }
    }

    

    public static void main(String[] args) throws InterruptedException {

        Thread[] withdrawers  = new Thread[5];
        Thread[] depositors = new Thread[6];

        for(int i = 0; i < withdrawers.length; i++)
        {
            withdrawers[i] = new Thread(new Withdrawer(), "withdraw-"+i);
        }
        for(int i = 0; i < depositors.length; i++)
        {
            depositors[i] = new Thread(new Depositor(), "depositors-"+i);
        }
        for(int i = 0; i < withdrawers.length; i++)
        {
            depositors[i].join();
        }
        for(int i = 0; i < depositors.length; i++)
        {
            depositors[i].join();
        }

        depositors[5].start();
        depositors[0].start();
        withdrawers[0].start();
        depositors[1].start();
        withdrawers[1].start();
        depositors[2].start();
        withdrawers[2].start();
        depositors[3].start();
        withdrawers[3].start();
        depositors[4].start();
        withdrawers[4].start();
        
    }
}

/*

    Speed improvement:

    Exercise 7: 
    real	0m0.063s
    user	0m0.075s
    sys	0m0.018s

    Exercise 6:
    real	0m0.072s
    user	0m0.089s
    sys	0m0.020s

*/