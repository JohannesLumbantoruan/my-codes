import java.util.ArrayList;

public class Tree {
  TreeNode root;

  Tree(TreeNode root) {
    this.root = root;
  }

  void preorder(TreeNode root, ArrayList<Integer> arr) {
    if (root == null) return;

    arr.add(root.data);

    this.preorder(root.left, arr);
    this.preorder(root.right, arr);
  }

  void inorder(TreeNode root, ArrayList<Integer> arr) {
    if (root == null) return;

    inorder(root.left, arr);

    arr.add(root.data);

    inorder(root.right, arr);
  }

  void postorder(TreeNode root, ArrayList<Integer> arr) {
    if (root == null) return;

    postorder(root.left, arr);
    postorder(root.right, arr);

    arr.add(root.data);
  }

  void levelorder(TreeNode root, ArrayList<Integer> arr) {
    final ArrayList<TreeNode> queue = new ArrayList<>();

    queue.add(root);

    while (queue.size() != 0) {
      TreeNode node = queue.get(0);

      arr.add(node.data);

      queue.remove(0);

      if (node.left != null) {
        queue.add(node.left);
      }

      if (node.right != null) {
        queue.add(node.right);
      }
    }
  }

  int height(TreeNode root) {
    if (root == null) {
      return 0;
    } else {
      int left = height(root.left);
      int right = height(root.right);

      if (left > right) {
        return left + 1;
      } else {
        return right + 1;
      }
    }
  }

  void print(ArrayList<Integer> arr, String text) {
    System.out.printf("%s: [", text);

    for (int i = 0; i < arr.size(); i++) {
      if (i == arr.size() - 1) {
        System.out.printf("%d]\n", arr.get(i));
      } else {
        System.out.printf("%d, ", arr.get(i));
      }
    }
  }
  public static void main(String[] args) {
    final TreeNode root = new TreeNode(1);
    final Tree tree = new Tree(root);

    root.left = new TreeNode(2);
    root.right = new TreeNode(3);

    root.left.left = new TreeNode(4);
    root.left.right = new TreeNode(5);

    root.right.right = new TreeNode(6);

    final ArrayList<Integer> preorder = new ArrayList<>();

    tree.preorder(root, preorder);

    tree.print(preorder, "preorder");

    final ArrayList<Integer> inorder = new ArrayList<>();

    tree.inorder(root, inorder);

    tree.print(inorder, "inorder");

    final ArrayList<Integer> postorder = new ArrayList<>();

    tree.postorder(root, postorder);

    tree.print(postorder, "postorder");

    final ArrayList<Integer> levelorder = new ArrayList<>();

    tree.levelorder(root, levelorder);

    tree.print(levelorder, "levelorder");

    final int height = tree.height(root);

    System.out.printf("height: %d\n", height);
  }
}

class TreeNode {
  int data;
  TreeNode left;
  TreeNode right;

  TreeNode(int data) {
    this.data = data;
    this.left = null;
    this.right = null;
  }
}