//Program 10
// Thread program using class "Thread"
class MyThread extends Thread {
    MyThread() {
        super("Using Thread class");
        System.out.println("Child thread:" + this);
        start();
    }
    public void run() {
        try {
            for (int i = 5; i > 0; i--) {
                System.out.println("Child thread" + i);
                Thread.sleep(500);
            }
        } catch (InterruptedException e) {
            // Do nothing
        }
        System.out.println("Exiting child thread . . .");
    }
}
public class P10Thread2 {
    public static void main(String[] args) {
        MyThread mt = new MyThread();
        try {
            for (int k = 5; k > 0; k--) {
                System.out.println("Running main thread :" + k);
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
        }
        System.out.println("Exiting main thread . . .");
    }
}