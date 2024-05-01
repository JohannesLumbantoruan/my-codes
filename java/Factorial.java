import java.util.Scanner;

class Factorial {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Enter a number: ");

    int n = scanner.nextInt();
    scanner.close();
    int result = factorial(n);
    
    System.out.println("Factorial of "+ n +": " + result);
  }

  static int factorial(int n) {
    if (n == 1) {
      return 1;
    } else {
      return n * factorial(n - 1);
    }
  }
}