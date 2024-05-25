#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
  int data;
  struct TreeNode* left;
  struct TreeNode* right;
} TreeNode;

typedef struct {
  TreeNode* root;
} Tree;

void print_tree(int* tree, char text[], int size);
void preorder(TreeNode* root, int** arr, int* size);
void inorder(TreeNode* root, int** arr, int* size);
void postorder(TreeNode* root, int** arr, int* size);
void levelorder(TreeNode* root, int** arr, int* size);
int height(TreeNode* root);

int main() {
  TreeNode root = { 1, NULL, NULL };
  Tree tree = { &root };

  root.left = (TreeNode*)malloc(sizeof(TreeNode));

  root.left->data = 2;
  root.left->left = NULL;
  root.left->right = NULL;

  root.right = (TreeNode*)malloc(sizeof(TreeNode));
  root.right->data = 3;
  root.right->left = NULL;
  root.right->right = NULL;

  root.left->left = (TreeNode*)malloc(sizeof(TreeNode));
  root.left->left->data = 4;
  root.left->left->left = NULL;
  root.left->left->right = NULL;

  root.left->right = (TreeNode*)malloc(sizeof(TreeNode));
  root.left->right->data = 5;
  root.left->right->left = NULL;
  root.left->right->right = NULL;

  root.right->right = (TreeNode*)malloc(sizeof(TreeNode));
  root.right->right->data = 6;
  root.right->right->left = NULL;
  root.right->right->right = NULL;

  int* arr = NULL;
  int size = 0;

  preorder(&root, &arr, &size);
  print_tree(arr, "preorder", size);

  arr = NULL;
  size = 0;

  inorder(&root, &arr, &size);
  print_tree(arr, "inorder", size);

  arr = NULL;
  size = 0;

  postorder(&root, &arr, &size);
  print_tree(arr, "postorder", size);
  
  arr = NULL;
  size = 0;

  levelorder(&root, &arr, &size);
  print_tree(arr, "level order", size);

  printf("height: %d\n", height(&root));

  return 0;
}

void print_tree(int* tree, char text[], int size) {
  printf("%s: [", text);

  for (int i = 0; i < size; i++) {
    if (i == size - 1) {
      printf("%d]\n", tree[i]);
    } else {
      printf("%d, ", tree[i]);
    }
  }
}

void preorder(TreeNode* root, int** arr, int* size) {
  if (root == NULL) {
    return;
  }

  *size += 1;

  *arr = (int*)realloc(*arr, *size * sizeof(int));
  (*arr)[*size - 1] = root->data;

  preorder(root->left, arr, size);
  preorder(root->right, arr, size);
}

void inorder(TreeNode* root, int** arr, int* size) {
  if (root == NULL) return;

  inorder(root->left, arr, size);

  *size += 1;
  *arr = (int*)realloc(*arr, *size * sizeof(int));
  (*arr)[*size - 1] = root->data;

  inorder(root->right, arr, size);
}

void postorder(TreeNode* root, int** arr, int* size) {
  if (root == NULL) return;

  postorder(root->left, arr, size);
  postorder(root->right, arr, size);

  *size += 1;
  *arr = (int*)realloc(*arr, sizeof(int));
  (*arr)[*size - 1] = root->data;
}

void levelorder(TreeNode* root, int** arr, int* size) {
  TreeNode** queue = (TreeNode**)malloc(sizeof(TreeNode*));
  int queue_size = 0;
  queue[0] = root;
  queue_size += 1;

  while (queue_size > 0) {
    TreeNode* node = queue[0];

    *size += 1;
    *arr = (int*)realloc(*arr, *size * sizeof(int));
    (*arr)[*size - 1] = node->data;

    memmove(queue, queue + 1, (queue_size - 1) * sizeof(TreeNode*));

    queue_size -= 1;

    if (node->left != NULL) {
      queue = (TreeNode**)realloc(queue, (queue_size + 1) * sizeof(TreeNode*));
      queue[queue_size] = node->left;
      queue_size += 1;
    }

    if (node->right != NULL) {
      queue = (TreeNode**)realloc(queue, (queue_size + 1) * sizeof(TreeNode*));
      queue[queue_size] = node->right;
      queue_size += 1;
    }
  }
}

int height(TreeNode* root) {
  if (root == NULL) {
    return 0;
  } else {
    int left = height(root->left);
    int right = height(root->right);

    if (left > right) {
      return left + 1;
    } else {
      return right + 1;
    }
  }
}