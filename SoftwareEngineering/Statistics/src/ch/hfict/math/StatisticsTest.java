package ch.hfict.math;

public class StatisticsTest {
  public static void main(String[] args) {
    Statistics statistics = new Statistics(3);
    statistics.addNumber(1);
    statistics.addNumber(2);
    statistics.addNumber(3);
    System.out.println("Average: " + statistics.getAverage() );
  }
}
