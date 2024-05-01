const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function factorial(n) {
  if (n === 1) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

rl.question('Enter a number: ', (number) => {
  console.log(`Factorial of ${number}: ${factorial(number)}`);
  rl.close();
});