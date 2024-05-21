import java.util.Scanner;

public class CaesarCipher {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.println(
      """
      CAESAR CIPHER
      1. Encode
      2. Decode
      """
    );

    System.out.println("Choose an option:");

    int option = scanner.nextInt();

    scanner.nextLine();

    System.out.println("Enter text:");

    String text = scanner.nextLine();

    text = text.toLowerCase();

    System.out.println("Enter shift:");

    int shift = scanner.nextInt();

    scanner.close();

    if (option == 1) {
      String result = encode(text, shift);

      System.out.println("Cipher text: " + result);
    }

    if (option == 2) {
      String result = decode(text, shift);

      System.out.println("Plain text: " + result);
    }
  }

  static String encode(String plainText, int shift) {
    char[] result = new char[plainText.length()];
    char chr = 0;

    for (int i = 0; i < plainText.length(); i++) {
      char code = plainText.charAt(i);

      if (code >= 97 && code <= 122) {
        chr = (char)(((code - 97) + shift) % 26 + 97);

        result[i] = chr;
      } else {
        result[i] = code;
      }
    }

    return String.valueOf(result);
  }

  static String decode(String cipherText, int shift) {
    char[] result = new char[cipherText.length()];
    char chr = 0;

    for (int i = 0; i < cipherText.length(); i++) {
      char code = cipherText.charAt(i);

      if (code >= 97 && code <= 122) {
        chr = (char)(((code - 97) - shift) % 26);

        if (chr < 0) chr += 26;

        chr += 97;

        result[i] = chr;
      } else {
        result[i] = code;
      }
    }

    return String.valueOf(result);
  }
}
