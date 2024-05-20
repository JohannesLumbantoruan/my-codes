import * as readline from "node:readline";

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function input(question: string): Promise<string> {
  return new Promise((resolve) => {
    rl.question(question, resolve);
  });
}

function binarySearch(numbers: number[], num: number): number {
  let start = 0;
  let end = numbers.length;
  let mid = Math.floor((start + end) / 2);

  while (start <= end) {
    if (numbers[mid] === num) {
      return mid;
    } else if (numbers[mid] > num) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }

    mid = Math.floor((start + end) / 2);
  }

  throw new Error("Number not found!");
}

async function main() {
  const numbers: number[] = [];
  let num = 0;
  let size = 0;

  size = parseInt(await input('Entter array size: '));

  console.log("Enter array values:");

  for (let i = 0; i < size; i++) {
    num = parseInt(await input(""));
    numbers.push(num);
  }

  num = parseInt(await input('Enter number to search: '));

  rl.close();

  console.log(`Unsorted: ${numbers}`);

  numbers.sort((a, b) => a - b);

  console.log(`Sorted: ${numbers}`);

  try {
    const index = binarySearch(numbers, num);

    console.log(`Index of ${num}: ${index}`);
  } catch (error) {
    if (error instanceof Error) {
      console.log(error.message);
    } else {
      console.log('Unknown error');
    }
  }
}

main();