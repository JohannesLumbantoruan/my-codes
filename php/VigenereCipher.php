<?php
declare(strict_types=1);

class VigenereCipher
{
  public string $key;

  public function __construct(string $key)
  {
    $this->key = $key;
  }

  function normalizeKey(int $length)
  {
    $keyLength = strlen($this->key);
    $repeat = intval(floor($length / $keyLength));
    $left = $length % $keyLength;
    $normalizedKey = str_repeat($this->key, $repeat);
    $normalizedKey .= substr($this->key, 0, $left);
    $this->key = $normalizedKey;
  }

  public function encode(string $plainText)
  {
    $length = strlen($plainText);

    if (strlen($this->key) < $length) {
      $this->normalizeKey($length);
    }

    $result = "";
    $char = 0;

    for ($i = 0; $i < $length; $i++) {
      $code = ord($plainText[$i]);

      if ($code >= 97 && $code <= 122) {
        $char = (($code - 97) + (ord($this->key[$i]) - 97)) % 26 + 97;

        $result .= chr($char);
      } else {
        $result .= $plainText[$i];
      }
    }

    return $result;
  }

  public function decode(string $cipherText)
  {
    $length = strlen($cipherText);

    if (strlen($this->key) < $length) {
      $this->normalizeKey($length);
    }

    $result = "";
    $char = 0;

    for ($i = 0; $i < $length; $i++) {
      $code = ord($cipherText[$i]);

      if ($code >= 97 && $code <= 122) {
        $char = (($code - 97) - (ord($this->key[$i]) - 97)) % 26;

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
VIGENERE CIPHER
1. Encode
2. Decode
EOD;

echo "\n\nChoose an option:\n";

$option = intval(trim(fgets(fopen("php://stdin", "r"))));

echo "Enter text:\n";

$text = trim(fgets(fopen("php://stdin", "r")));

$text = strtolower($text);

echo "Enter key:\n";

$key = trim(fgets(fopen("php://stdin", "r")));

$vc = new VigenereCipher($key);

if ($option === 1) {
  $result = $vc->encode($text);

  echo "Cipher text: $result";
}

if ($option === 2) {
  $result = $vc->decode($text);

  echo "Plain text: $result";
}