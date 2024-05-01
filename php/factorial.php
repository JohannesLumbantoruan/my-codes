<?php
function factorial($n) {
  if ($n === 1) {
    return 1;
  } else {
    return $n * factorial($n - 1);
  }
}

echo "Enter number: ";

$input = fopen("php://stdin", "r");
$number = trim(fgets($input));

echo "Factorial of $number: " . factorial($number);