class ChildThread extends Thread {
    @Override
    public void run() {
        try {
            System.out.println("Child thread starting.");
            Thread.sleep(2000); // Sleep for 2 seconds
            System.out.println("Child thread finishing.");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class MainWaitsForChild {
    public static void main(String[] args) {
        ChildThread childThread = new ChildThread();
        childThread.start();

        try {
            System.out.println("Main thread waiting for child to complete.");
            childThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Child thread has completed. Main thread resumes.");
    }
}
