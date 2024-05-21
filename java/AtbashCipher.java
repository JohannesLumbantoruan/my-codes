import java.lang.StringBuilder;
import java.util.Scanner;

class AtbashCipher {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.println("Enter text to encode/decode:");
    String text = scanner.nextLine();

    text = text.toLowerCase();

    String result = atbashCipher(text);

    System.out.printf("Result: %s", result);

    scanner.close();
  }

  static String atbashCipher(String plainText) {
    StringBuilder sb = new StringBuilder();
    char c = 0;

    for (int i = 0; i < plainText.length(); i++) {
      char chr = plainText.charAt(i);

      if (chr >= 97 && chr <= 122) {
        c = (char)((25 - (chr - 97)) % 26 + 97);

        sb.append(c);
      } else {
        sb.append(chr);
      }
    }

    return sb.toString();
  }
}