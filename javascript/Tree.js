class TreeNode {
  constructor(data) {
    this.data = data;
    this.left = null;
    this.right = null;
  }
}

class Tree {
  constructor(root) {
    this.root = root;
    this._height = null;
  }

  get height() {
    if (this._height === null) {
      this._height = this.getHeight(this.root);
    }

    return this._height;
  }

  getHeight(root) {
    if (root === null) {
      return 0;
    } else {
      const left = this.getHeight(root.left);
      const right = this.getHeight(root.right);

      if (left > right) {
        return left + 1;
      } else {
        return right + 1;
      }
    }
  }
  
  preorder(root, arr) {
    if (root === null) {
      return;
    }
    
    arr.push(root.data);
    
    this.preorder(root.left, arr);
    this.preorder(root.right, arr);
  }
  
  inorder(root, arr) {
    if (root === null) return;
    
    this.inorder(root.left, arr);
    
    arr.push(root.data);
    
    this.inorder(root.right, arr);
  }
  
  postorder(root, arr) {
    if (root === null) return;
    
    this.postorder(root.left, arr);
    this.postorder(root.right, arr);
    
    arr.push(root.data);
  }
  
  levelorder(root, arr) {
    const queue = [root];
    
    while (queue.length !== 0) {
      const node = queue.shift();
      
      arr.push(node.data);
      
      if (node.left !== null) queue.push(node.left);
      if (node.right !== null) queue.push(node.right);
    }
  }
}

const root = new TreeNode(1);
const tree = new Tree(root);

tree.root.left = new TreeNode(2);
tree.root.right = new TreeNode(3);

tree.root.left.left = new TreeNode(4);
tree.root.left.right = new TreeNode(5);

tree.root.right.right = new TreeNode(6);

const preorder = [];

tree.preorder(root, preorder);

console.log(`preorder: ${preorder.join('->')}`);

const inorder = [];

tree.inorder(root, inorder);

console.log(`inorder: ${inorder.join('->')}`);

const postorder = [];

tree.postorder(root, postorder);

console.log(`postorder: ${postorder.join('->')}`);

const levelorder = [];

tree.levelorder(root, levelorder);

console.log(`levelorder: ${levelorder.join('->')}`);
console.log(`height: ${tree.height}`);