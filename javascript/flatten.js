function flatten(arr, res = []) {
  for (const el of arr) {
    if (Array.isArray(el)) {
      flatten(el, res);
    } else {
      res.push(el);
    }
  }

  return res;
}

const arr = [1, [2, [3, 4, [5, [[6]]]]], [7, [[8, 9, [[10]]]]]];
const res = flatten(arr);

console.log(res);