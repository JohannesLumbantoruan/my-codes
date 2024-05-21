<?php
declare(strict_types=1);

function atbashCipher(string $text): string {
  $result = "";
  $char = 0;

  for ($i = 0; $i < strlen($text); $i++) {
    $code = ord($text[$i]);

    if ($code >= 97 && $code <= 122) {
      $char = (25 - (ord($text[$i]) - 97)) % 26 + 97;
      $result .= chr($char);
    } else {
      $result .= $text[$i];
    }
  }

  return $result;
}

echo "Enter text to encode/decode: \n";

$text = trim(fgets(fopen("php://stdin", "r")));

$text = strtolower($text);

$result = atbashCipher($text);

echo "Result: $result";