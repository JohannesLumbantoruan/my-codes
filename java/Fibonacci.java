import java.util.Scanner;

public class Fibonacci {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Enter a number: ");

    int n = scanner.nextInt();
    scanner.close();
    int result = fibonacci(n);

    System.out.println("Fibonacci of "+ n +": " + result);
  }

  static int fibonacci(int n) {
    if (n == 0) {
      return 0;
    } else if (n <= 2) {
      return 1;
    } else {
      return fibonacci(n - 1) + fibonacci(n - 2);
    }
  }
}
