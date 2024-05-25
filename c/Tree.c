#include <stdio.h>
#include <stdlib.h>

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

int main() {
  TreeNode root = { 1, NULL, NULL };
  Tree tree = { &root };

  root.left = (struct TreeNode*)malloc(sizeof(TreeNode));

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