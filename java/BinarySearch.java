import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/**
 * BinarySearch
 */
public class BinarySearch {

  public static void main(String[] args) {
    ArrayList<Integer> numbers = new ArrayList<>();
    int number = 0;
    int size = 0;

    Scanner scanner = new Scanner(System.in);

    System.out.println("Enter array size:");
    size = scanner.nextInt();

    System.out.println("Enter array values:");

    for (int i = 0; i < size; i++) {
      number = scanner.nextInt();
      numbers.add(number);
    }

    System.out.println("Enter number to search:");

    number = scanner.nextInt();

    scanner.close();

    System.out.print("Unsorted: [");

    for (int i = 0; i < numbers.size(); i++) {
      if (i == numbers.size() - 1) {
        System.out.print(numbers.get(i) + "]\n");
      } else {
        System.out.print(numbers.get(i) + ", ");
      }
    }

    Collections.sort(numbers);

    System.out.print("Sorted: [");

    for (int i = 0; i < numbers.size(); i++) {
      if (i == numbers.size() - 1) {
        System.out.print(numbers.get(i) + "]\n");
      } else {
        System.out.print(numbers.get(i) + ", ");
      }
    }

    try {
      int index = binarySearch(numbers, number);

      System.out.println("Index of "+ number +": "+ index);
    } catch (Exception err) {
      System.out.println(err.getMessage());
    }
  }

  static int binarySearch(ArrayList<Integer> numbers, int number) throws Exception {
    int start = 0;
    int end = numbers.size() - 1;
    int mid = (start + end) / 2;

    while (start <= end) {
      if (numbers.get(mid) == number) {
        return mid;
      } else if (numbers.get(mid) > number) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }

      mid = (start + end) / 2;
    }

    throw new Exception("Number not found!");
  }
}