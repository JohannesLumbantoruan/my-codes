const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function input(question) {
  return new Promise((resolve) => {
    rl.question(question, resolve);
  });
}

function binarySearch(numbers, number) {
  let start = 0;
  let end = numbers.length;
  let mid = Math.floor((start + end) / 2);

  while (start <= end) {
    if (numbers[mid] === number) {
      return mid;
    } else if (numbers[mid] > number) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }

    mid = Math.floor((start + end) / 2);
  }

  throw new Error('Number not found!');
}

async function main() {
  const numbers = [];
  let number = 0;
  const size = parseInt(await input("Enter array size: "));

  console.log("Enter array values:");

  for (let i = 0; i < size; i++) {
    number = parseInt(await input(""));
    numbers.push(number);
  }

  number = parseInt(await input("Enter number to search: "));

  rl.close();

  console.log(`Unsorted: ${numbers}`);

  numbers.sort((a, b) => a - b);

  console.log(`Sorted: ${numbers}`);

  try {
    const index = binarySearch(numbers, number);

    console.log(`Index of ${number}: ${index}`);
  } catch (error) {
    console.log(error.message);
  }
}

main();