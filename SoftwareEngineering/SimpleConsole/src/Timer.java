
public class Timer implements Runnable {
	
	private Thread thread;

	public void start() {
		thread = new Thread(this);
		thread.start();
	}

	public void stop() {
		thread = null;
	}

	@Override
	public void run() {
		while(thread !=null) {
			display();
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
	}
	
	private void display() {
		System.out.println(new java.util.Date());
	}

}
