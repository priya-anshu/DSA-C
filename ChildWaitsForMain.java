class ChildThread extends Thread {
    private Thread mainThread;

    public ChildThread(Thread mainThread) {
        this.mainThread = mainThread;
    }

    @Override
    public void run() {
        try {
            System.out.println("Child thread waiting for main thread to complete.");
            mainThread.join();
            System.out.println("Main thread has completed. Child thread resumes.");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class ChildWaitsForMain {
    public static void main(String[] args) {
        Thread mainThread = Thread.currentThread();
        ChildThread childThread = new ChildThread(mainThread);
        childThread.start();

        try {
            System.out.println("Main thread sleeping for 2 seconds.");
            Thread.sleep(2000); // Sleep for 2 seconds
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Main thread finishing.");
    }
}