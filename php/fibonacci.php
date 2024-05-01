<?php
function fibonacci($n) {
  if ($n === 0) {
    return 0;
  } else if ($n <= 2) {
    return 1;
  } else {
    return fibonacci($n - 1) + fibonacci($n - 2);
  }
}

echo "Enter a number: ";
$input = fopen("php://stdin", "r");
$n = trim(fgets($input));

echo "Fibonacci of $n: " . fibonacci($n);