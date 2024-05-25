class TreeNode {
  final int data;
  TreeNode? left;
  TreeNode? right;

  TreeNode(this.data, { this.left, this.right });
}

class Tree {
  final TreeNode root;

  Tree(this.root);

  void preorder(TreeNode? root, List<int> arr) {
    if (root == null) return;

    arr.add(root.data);

    this.preorder(root.left, arr);
    this.preorder(root.right, arr);
  }

  void inorder(TreeNode? root, List<int> arr) {
    if (root == null) return;

    this.inorder(root.left, arr);
    
    arr.add(root.data);

    this.inorder(root.right, arr);
  }

  void postorder(TreeNode? root, List<int> arr) {
    if (root == null) return;

    this.postorder(root.left, arr);
    this.postorder(root.right, arr);

    arr.add(root.data);
  }

  void levelorder(TreeNode root, List<int> arr) {
    final List<TreeNode> queue = [root];

    while (queue.length > 0) {
      TreeNode node = queue.removeAt(0);

      arr.add(node.data);

      if (node.left != null) {
        queue.add(node.left!);
      }

      if (node.right != null) {
        queue.add(node.right!);
      }
    }
  }

  int height(TreeNode? root) {
    if (root == null) {
      return 0;
    } else {
      int left = this.height(root.left);
      int right = this.height(root.right);

      if (left > right) {
        return left + 1;
      } else {
        return right + 1;
      }
    }
  }
}

void main() {
  final root = TreeNode(1);
  final tree = Tree(root);

  root.left = TreeNode(2);
  root.right = TreeNode(3);

  root.left?.left = TreeNode(4);
  root.left?.right = TreeNode(5);

  root.right?.right = TreeNode(6);

  final List<int> preorder = [];

  tree.preorder(root, preorder);
  print("preorder: $preorder");

  final List<int> inorder = [];

  tree.inorder(root, inorder);
  print("inorder: $inorder");

  final List<int> postorder = [];

  tree.postorder(root, postorder);
  print("postorder: $postorder");

  final List<int> levelorder = [];

  tree.levelorder(root, levelorder);
  print("level order: $levelorder");

  print("height: ${tree.height(root)}");
}