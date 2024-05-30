function permutation(arr) {
  const result = [];

  if (arr.length < 2) {
    return [arr];
  }

  for (let i = 0; i < arr.length; i++) {
    const current = arr[i];
    const left = arr.slice(0, i).concat(arr.slice(i+1));
    const leftPermutation = permutation(left);

    for (let j = 0; j < leftPermutation.length; j++) {
      result.push([current].concat(leftPermutation[j]));
    }
  }

  return result;
}

const arr = ['a', 'b', 'c'];
const result = permutation(arr);

console.log(result);