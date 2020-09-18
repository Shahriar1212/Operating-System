package producerconsumerproblem;
import java.util.LinkedList;

public class Main {

    public static int temp = 1;
    public static int bufferSize = 10;
    public static LinkedList<Integer> buffer = new LinkedList<>();

    public static void main(String[] args) {
        Producer p1 = new Producer(1, 1000);
        Producer p2 = new Producer(2, 200);
        Producer p3 = new Producer(3, 700);
        Consumer c1 = new Consumer(1, 50);
        Consumer c2 = new Consumer(2, 1000);
        Consumer c3 = new Consumer(3, 600);
        p2.start();
        p1.start();
        p3.start();
        c1.start();
        c2.start();
        c3.start();

    }
}

class Producer extends Thread {
    int producerID, time;
    Producer(int producerID, int time) {
        this.producerID = producerID;
        this.time = time;
    }
    @Override
    public void run() {
        try {
            while (true) {
                synchronized (Main.buffer) {
                    while (Main.buffer.size() == Main.bufferSize) {
                        Main.buffer.wait();
                    }
                    System.out.println("[+] producer " + producerID + ": Data " + Main.temp + " is inserted in the buffer");
                    Main.buffer.add(Main.temp);
                    Main.temp++;
                    int emptySpace = Main.bufferSize - Main.buffer.size();
                    System.out.println("Full Space : " + Main.buffer.size() + " Empty space : " + emptySpace);
                    Main.buffer.notify();
                    Thread.sleep(time);
                }
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}

class Consumer extends Thread {
    int consumerID, time;
    Consumer(int consumerID, int time) {
        this.consumerID = consumerID;
        this.time = time;
    }
    @Override
    public void run() {
        try {
            while (true) {
                synchronized (Main.buffer) {
                    while (Main.buffer.isEmpty()) {
                        Main.buffer.wait();
                    }
                    int removedData = Main.buffer.remove();
                    System.out.println("[-] Consumer " + consumerID + ": Data " + removedData + " is consumed from the buffer");
                    int emptySpace = Main.bufferSize - Main.buffer.size();
                    System.out.println("Full Space : " + Main.buffer.size() + " Empty space : " + emptySpace);
                    Main.buffer.notify();
                    Thread.sleep(time);
                }
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
