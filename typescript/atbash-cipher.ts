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

function atbashCipher(text: string): string {
  let result = "";
  let char = 0;

  for (let i = 0; i < text.length; i++) {
    const code = text.charCodeAt(i);

    if (code >= 97 && code <= 122) {
      char = (25 - (code - 97)) % 26 + 97;

      result += String.fromCharCode(char);
    } else {
      result += text[i];
    }
  }

  return result;
}

async function main() {
  const text = await input("Enter text to encode/decode: ");

  rl.close();

  text.toLocaleLowerCase();

  const result = atbashCipher(text);

  console.log(`Result: ${result}`);
}

main();