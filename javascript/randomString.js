/*
** This code generate random string that consist of only
** uppercase and lowercase letter, and also number.
** You simply pass amount of string you want and 
** the function will return random string with
** the same amount
*/

const chars = [];

for (let i = 48; i < 123; i++) {
  if (i === 58) i = 65;
  if (i === 91) i = 97;
  
  chars.push(i);
}

function randomString(n) {
  let res = [];
  for (let i = 0; i < n; i++) {
    const code = Math.floor(Math.random() * chars.length);
    
    res.push(chars[code]);
  }
  
  return String.fromCharCode(...res);
}

console.log(randomString(16));