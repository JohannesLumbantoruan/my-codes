<?php
declare(strict_types=1);

class CaesarCipher
{
  static public function encode(string $plainText, int $shift): string
  {
    $result = "";
    $char = 0;

    for ($i = 0; $i < strlen($plainText); $i++) {
      $code = ord($plainText[$i]);

      if ($code >= 97 && $code <= 122) {
        $char = (($code - 97) + $shift) % 26 + 97;

        $result .= chr($char);
      } else {
        $result .= $plainText[$i];
      }
    }

    return $result;
  }

  static public function decode(string $cipherText, int $shift): string
  {
    $result = "";
    $char = 0;

    for ($i = 0; $i < strlen($cipherText); $i++) {
      $code = ord($cipherText[$i]);

      if ($code >= 97 && $code <= 122) {
        $char = (($code - 97) - $shift) % 26;

        if ($char < 0) $char += 26;

        $char += 97;

        $result .= chr($char);
      } else {
        $result .= $cipherText[$i];
      }
    }

    return $result;
  }
}

echo <<<EOD
CAESAR CIPHER
1. Encode
2. Decode

EOD;

echo "\nChoose an option:\n";

$option = intval(trim(fgets(fopen("php://stdin", "r"))));

echo "Enter text:\n";

$text = trim(fgets(fopen("php://stdin", "r")));

$text = strtolower($text);

echo "Enter shift:\n";

$shift = intval(trim(fgets(fopen("php://stdin", "r"))));

if ($option === 1) {
  $result = CaesarCipher::encode($text, $shift);

  echo "Cipher text: $result";
}

if ($option == 2) {
  $result = CaesarCipher::decode($text, $shift);

  echo "Plain text: $result";
}