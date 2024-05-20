class LinkedListNode {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class LinkedList {
  constructor() {
    this.head = null;
    this.length = 0;
  }

  print() {
    let node = this.head;
    const result = [];

    if (node === null) {
      return "null";
    } else {
      while (node !== null) {
        result.push(node.data);
        node = node.next;
      }
    }

    result.push("null");

    return result.join("->");
  }

  unshift(data) {
    const node = new LinkedListNode(data);

    if (this.head === null) {
      this.head = node;
    } else {
      node.next = this.head;
      this.head = node;
    }

    this.length += 1;
  }

  push(data) {
    const node = new LinkedListNode(data);

    if (this.head === null) {
      this.head = node;
    } else {
      let current = this.head;

      while (current !== null) {
        if (current.next === null) {
          current.next = node;
          break;
        } else {
          current = current.next;
        }
      }
    }

    this.length += 1;
  }

  shift() {
    const node = this.head;

    if (node === null) {
      throw new Error('ZeroLengthException: Linked list length is zero');
    } else {
      this.head = node.next;
    }

    this.length -= 1;
  }

  pop() {
    let node = this.head;

    if (node === null) {
      throw new Error('ZeroLengthException: Linked list length is zero');
    } else {
      let prev = null;

      while (node !== null) {
        if (node.next === null) {
          prev.next = null;
          break;
        } else {
          prev = node;
          node = node.next;
        }
      }
    }

    this.length -= 1;
  }
}

const ll = new LinkedList();

for (let i = 1; i <= 5; i++) {
  ll.unshift(i * 5);
}

console.log(`${ll.print()}, length: ${ll.length}`);

for (let i = 1; i <= 5; i++) {
  ll.push(i * 10);
}

console.log(`${ll.print()}, length: ${ll.length}`);

ll.shift();

console.log(`${ll.print()}, length: ${ll.length}`);

ll.pop();

console.log(`${ll.print()}, length: ${ll.length}`);