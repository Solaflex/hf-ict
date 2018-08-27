public class StatisticsTest {
	public static void main(String[] args) {
		Statistics statistics = new Statistics(3);
		statistics.addNumber(10);
		statistics.addNumber(20);
		statistics.addNumber(30);
		System.out.println("Average: " + statistics.getAverage());	
	}	
}