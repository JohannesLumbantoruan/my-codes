#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
  public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
      this->data = data;
      this->left = NULL;
      this->right = NULL;
    }
};

class Tree {
  public:
    TreeNode* root;

    Tree(TreeNode* root) {
      this->root = root;
    }

    void print_tree(vector<int> tree, string text) {
      cout << text << ": [";

      for (int i = 0; i < tree.size(); i++) {
        if (i == tree.size() - 1) {
          cout << tree[i] << "]\n";
        } else {
          cout << tree[i] << ", ";
        }
      }
    }

    void preorder(TreeNode* root, vector<int>* arr) {
      if (root == NULL) return;

      (*arr).push_back(root->data);

      this->preorder(root->left, arr);
      this->preorder(root->right, arr);
    }

    void inorder(TreeNode* root, vector<int>* arr) {
      if (root == NULL) return;

      this->inorder(root->left, arr);

      (*arr).push_back(root->data);

      this->inorder(root->right, arr);
    }

    void postorder(TreeNode* root, vector<int>* arr) {
      if (root == NULL) return;

      this->postorder(root->left, arr);
      this->postorder(root->right, arr);

      (*arr).push_back(root->data);
    }

    void levelorder(TreeNode* root, vector<int>* arr) {
      vector<TreeNode*> queue;

      queue.push_back(root);

      while (queue.size() > 0) {
        TreeNode* node = queue[0];

        (*arr).push_back(node->data);

        queue.erase(queue.begin());

        if (node->left != NULL) {
          queue.push_back(node->left);
        }

        if (node->right != NULL) {
          queue.push_back(node->right);
        }
      }
    }

    int height(TreeNode* root) {
      if (root == NULL) {
        return 0;
      } else {
        int left = this->height(root->left);
        int right = this->height(root->right);

        if (left > right) {
          return left + 1;
        } else {
          return right + 1;
        }
      }
    }
};

int main() {
  TreeNode root(1);
  Tree tree(&root);

  root.left = new TreeNode(2);
  root.right = new TreeNode(3);

  root.left->left = new TreeNode(4);
  root.left->right = new TreeNode(5);

  root.right->right = new TreeNode(6);

  vector<int> preorder;

  tree.preorder(&root, &preorder);
  tree.print_tree(preorder, "preorder");

  vector<int> inorder;

  tree.inorder(&root, &inorder);
  tree.print_tree(inorder, "inorder");

  vector<int> postorder;

  tree.postorder(&root, &postorder);
  tree.print_tree(postorder, "postorder");

  vector<int> levelorder;

  tree.levelorder(&root, &levelorder);
  tree.print_tree(levelorder, "level order");

  cout << "height: " << tree.height(&root) << endl;

  return 0;
}