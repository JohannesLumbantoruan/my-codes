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

class VigenereCipher {
  key: string;

  constructor(key: string) {
    this.key = key;
  }

  normalizeKey(length: number) {
    const keyLength = this.key.length;
    const repeat = Math.floor(length / keyLength);
    const left = length % keyLength;
    let normalizedKey = this.key.repeat(repeat);
    normalizedKey += this.key.substring(0, left);
    this.key = normalizedKey;
  }

  encode(plainText: string): string {
    const length = plainText.length;

    if (this.key.length < length) {
      this.normalizeKey(length);
    }

    let result = '';
    let char = 0;

    for (let i = 0; i < length; i++) {
      const code = plainText.charCodeAt(i);

      if (code >= 97 && code <= 122) {
        char = ((code - 97) + (this.key.charCodeAt(i) - 97)) % 26 + 97;

        result += String.fromCharCode(char);
      } else {
        result += plainText[i];
      }
    }

    return result;
  }

  decode(cipherText: string): string {
    const length = cipherText.length;

    if (this.key.length < length) {
      this.normalizeKey(length);
    }

    let result = '';
    let char = 0;

    for (let i = 0; i < length; i++) {
      const code = cipherText.charCodeAt(i);

      if (code >= 97 && code <= 122) {
        char = ((code - 97) - (this.key.charCodeAt(i) - 97)) % 26;

        if (char < 0) char += 26;

        char += 97;

        result += String.fromCharCode(char);
      } else {
        result += cipherText[i];
      }
    }

    return result;
  }
}

async function main() {
  console.log(`VIGENERE CIPHER
1. Encode
2. Decode
  `);

  const option = parseInt(await input('Choose an option: '));
}

main();