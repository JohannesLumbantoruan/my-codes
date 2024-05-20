import * as readline from "node:readline";

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function factorial(n: number): number {
  if (n === 1) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

rl.question("Enter a number: ", (num: string) => {
  console.log(`Factorial of ${num}: ${factorial(parseInt(num))}`);

  rl.close();
});