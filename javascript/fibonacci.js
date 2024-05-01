const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function fibonacci(n) {
  if (n === 0) {
    return 0;
  } else if (n <= 2) {
    return 1;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

rl.question("Enter a number: ", (n) => {
  console.log(`Fibonacci of ${n}: ${fibonacci(n)}`);
  rl.close();
});