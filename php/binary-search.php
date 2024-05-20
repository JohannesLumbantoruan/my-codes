<?php
declare(strict_types=1);

function binarySearch(array $numbers, int $number): int
{
  $start = 0;
  $end = count($numbers);
  $mid = intval(floor(($start + $end) / 2));

  while ($start <= $end) {
    if ($numbers[$mid] === $number) {
      return $mid;
    } else if ($numbers[$mid] > $number) {
      $end = $mid - 1;
    } else {
      $start = $mid + 1;
    }

    $mid = intval(floor(($start + $end) / 2));
  }

  throw new Exception("Number not found!");
}

$numbers = [];
$number = 0;
$size = 0;

echo "Enter array size:\n";

$size = intval(trim(fgets(fopen("php://stdin", "r"))));

echo "Enter array values:\n";

for ($i = 0; $i < $size; $i++) {
  $number = intval(trim(fgets(fopen("php://stdin", "r"))));
  array_push($numbers, $number);
}

echo "Enter number to search:\n";

$number = intval(trim(fgets(fopen("php://stdin", "r"))));

echo "Unsorted: [";

for ($i = 0; $i < count($numbers); $i++) {
  if ($i === count($numbers) - 1) {
    echo "{$numbers[$i]}]\n";
  } else {
    echo "{$numbers[$i]}, ";
  }
}

sort($numbers);

echo "Sorted: [";

for ($i = 0; $i < count($numbers); $i++) {
  if ($i === count($numbers) - 1) {
    echo "{$numbers[$i]}]\n";
  } else {
    echo "{$numbers[$i]}, ";
  }
}

try {
  echo "Index of $number: " . binarySearch($numbers, $number);
} catch (Exception $err) {
  echo $err->getMessage();
}