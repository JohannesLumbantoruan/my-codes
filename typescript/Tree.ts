class TreeNode {
  data: number;
  left: TreeNode | null;
  right: TreeNode | null;

  constructor(data: number) {
    this.data = data;
    this.left = null;
    this.right = null;
  }
}

class Tree {
  root: TreeNode;

  constructor(root: TreeNode) {
    this.root = root;
  }

  preorder(root: TreeNode | null, arr: number[]) {
    if (root === null) return;

    arr.push(root.data);

    this.preorder(root.left, arr);
    this.preorder(root.right, arr);
  }

  inorder(root: TreeNode | null, arr: number[]) {
    if (root === null) return;

    this.inorder(root.left, arr);

    arr.push(root.data);

    this.inorder(root.right, arr);
  }

  postorder(root: TreeNode | null, arr: number[]) {
    if (root === null) return;

    this.postorder(root.left, arr);
    this.postorder(root.right, arr);

    arr.push(root.data);
  }

  levelorder(root: TreeNode, arr: number[]) {
    const queue = [root];

    while (queue.length > 0) {
      const node = queue.shift()!;

      arr.push(node.data);

      if (node?.left !== null) {
        queue.push(node.left);
      }

      if (node?.right !== null) {
        queue.push(node.right);
      }
    }
  }

  height(root: TreeNode | null): number {
    if (root === null) {
      return 0;
    } else {
      const left = this.height(root.left);
      const right = this.height(root.right);

      if (left > right) {
        return left + 1;
      } else {
        return right + 1;
      }
    }
  }
}

const root = new TreeNode(1);
const tree = new Tree(root);

root.left = new TreeNode(2);
root.right = new TreeNode(3);

root.left.left = new TreeNode(4);
root.left.right = new TreeNode(5);

root.right.right = new TreeNode(6);

const preorder: number[] = [];

tree.preorder(root, preorder);

const inorder: number[] = [];

tree.inorder(root, inorder);

const postorder: number[] = [];

tree.postorder(root, postorder);

const levelorder: number[] = [];

tree.levelorder(root, levelorder);

console.log(`preorder: ${preorder}`);
console.log(`inorder: ${inorder}`);
console.log(`postorder: ${postorder}`);
console.log(`level order: ${levelorder}`);
console.log(`height: ${tree.height(root)}`);
