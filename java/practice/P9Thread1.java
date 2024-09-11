//Program 9
// Thread program using runnable class(interface program)
class mythread1 implements Runnable {
    public void run() {
        for (int i = 1; i < 5; i++) {
            System.out.println(i);
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
class mythread2 implements Runnable {
    public void run() {
        for (int i = 10; i < 15; i++) {
            System.out.println(i);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
public class P9Thread1 {
    public static void main(String[] args) {
        mythread1 mt1 = new mythread1();
        Thread t1 = new Thread(mt1);
        t1.start();
        mythread2 mt2 = new mythread2();
        Thread t2 = new Thread(mt2);
        t2.start();
    }
}
