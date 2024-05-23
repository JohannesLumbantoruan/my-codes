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

class VigenereCipher {
  constructor(key) {
    this.key = key;
  }

  normalizeKey(length) {
    const keyLength = this.key.length;
    const repeat = Math.floor(length / keyLength);
    const left = length % keyLength;
    let normalizedKey = this.key.repeat(repeat);
    normalizedKey += this.key.substsring(0, left);
    this.key = normalizedKey;
  }

  encode(plainText) {
    
  }
}