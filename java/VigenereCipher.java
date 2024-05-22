import java.util.Scanner;

public class VigenereCipher {
  String key;

  VigenereCipher(String key) {
    this.key = key;
  }
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.println("""
      VIGENERE CIPHER
      1. Encode
      2. Decode
      """);
    
    System.out.println("Choose an option:");

    final int option = scanner.nextInt();

    scanner.nextLine();

    System.out.println("Enter text:");

    String text = scanner.nextLine();

    text = text.toLowerCase();

    System.out.println("Enter key:");

    final String key = scanner.nextLine();

    scanner.close();

    final VigenereCipher vc = new VigenereCipher(key);

    if (option == 1) {
      final String result = vc.encode(text);

      System.out.printf("Cipher text: %s", result);
    }

    if (option == 2) {
      final String result = vc.decode(text);

      System.out.printf("Plain text: %s", result);
    }
  }

  void normalizeKey(int length) {
    final int keyLength = this.key.length();
    final int repeat = length / keyLength;
    final int left = length % keyLength;
    String normalizedKey = "";

    for (int i = 0; i < repeat; i++) {
      normalizedKey += this.key;
    }

    normalizedKey += this.key.substring(0, left);

    this.key = normalizedKey;
  }

  String encode(String plainText) {
    final int length = plainText.length();

    if (this.key.length() < length) {
      this.normalizeKey(length);
    }

    char[] result = new char[length];
    int chr = 0;

    for (int i = 0; i < length; i++) {
      final int code = plainText.codePointAt(i);

      if (code >= 97 && code <= 122) {
        chr = ((code - 97) + (this.key.codePointAt(i) - 97)) % 26 + 97;

        result[i] = (char)chr;
      } else {
        result[i] = (char)code;
      }
    }

    return String.valueOf(result);
  }

  String decode(String cipherText) {
    final int length = cipherText.length();

    if (this.key.length() < length) {
      this.normalizeKey(length);
    }

    char[] result = new char[length];
    int chr = 0;

    for (int i = 0; i < length; i++) {
      final int code = cipherText.codePointAt(i);

      if (code >= 97 && code <= 122) {
        chr = ((code - 97) - (this.key.codePointAt(i) - 97)) % 26;

        if (chr < 0) chr += 26;

        chr += 97;

        result[i] = (char)chr;
      } else {
        result[i] = (char)code;
      }
    }

    return String.valueOf(result);
  }
}
