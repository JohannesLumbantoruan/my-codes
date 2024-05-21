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

class CaesarCipher {
  static encode(plainText, shift) {
    let result = '';
    let char = 0;

    for (let i = 0; i < plainText.length; i++) {
      const code = plainText.charCodeAt(i);

      if (code >= 97 && code <= 122) {
        char = ((code - 97) + shift) % 26 + 97;

        result += String.fromCharCode(char);
      } else {
        result += plainText[i];
      }
    }

    return result;
  }

  static decode(cipherText, shift) {
    let result = '';
    let char = 0;

    for (let i = 0; i < cipherText.length; i++) {
      const code = cipherText.charCodeAt(i);

      if (code >= 97 && code <= 122) {
        char = ((code - 97) - shift) % 26;

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
  console.log(`CAESAR CIPHER
  1. Encode
  2. Decode
  `);

  const option = parseInt(await input('Choose an option: '));
  let text = await input('Enter text: ');
  const shift = parseInt(await input('Enter shift: '));

  text = text.toLowerCase();

  rl.close();

  if (option === 1) {
    const result = CaesarCipher.encode(text, shift);

    console.log(`Cipher text: ${result}`);
  }

  if (option === 2) {
    const result = CaesarCipher.decode(text, shift);

    console.log(`Plain text: ${result}`);
  }
}

main();