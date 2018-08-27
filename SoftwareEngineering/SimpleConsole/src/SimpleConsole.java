
public class SimpleConsole {

	public static void main(String[] args) {
		Timer timer = new Timer();
		int c=' ';
		while (c != 's') {
			System.out.println("Enter s to stop:");
			try {
				c = System.in.read();
			}
			catch (Exception ex) {
				
			}
		}
		
		timer.stop();

	}

}
