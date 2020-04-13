public class Exercise1 {

    public static void main(String[] args) {

        long id = Thread.currentThread().getId();
        String name = Thread.currentThread().getName();
        int priority = Thread.currentThread().getPriority();
        String threadGroupName = Thread.currentThread().getThreadGroup().getName();
        System.out.println("id = " + id + "; name="+name+"; priority="+priority+"; threadGroupName="+threadGroupName);

    }

}