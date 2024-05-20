import * as readline from "node:readline";

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function fibonacci(n: number): number {
  if (n === 0) {
    return 0;
  } else if (n <= 2) {
    return 1;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

rl.question("Enter a number: ", (num: string) => {
  console.log(`Fibonacci of ${num}: ${fibonacci(parseInt(num))}`);

  rl.close();
});