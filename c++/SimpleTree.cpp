#include <iostream>
#include <vector>
using namespace std;

void print_traversal(vector<int> arr);

void preorder(int start, vector<int*> tree, vector<int>* arr) {
  if (tree[start] == NULL) return;
  
  arr->push_back(*tree[start]);
  
  int left = 2 * start + 1;
  int right = 2 * start + 2;
  
  if (left < tree.size()) {
    preorder(left, tree, arr);
  }
  
  if (right < tree.size()) {
    preorder(right, tree, arr);
  }
}

void inorder(int start, vector<int*> tree, vector<int>* arr) {
  if (tree[start] == NULL) return;
  
  int left = start * 2 + 1;
  int right = start * 2 + 2;
  
  if (left < tree.size()) {
    inorder(left, tree, arr);
  }
  
  arr->push_back(*tree[start]);
  
  if (right < tree.size()) {
    inorder(right, tree, arr);
  }
}

void postorder(int start, vector<int*> tree, vector<int>* arr) {
  if (tree[start] == NULL) return;

  int left = start * 2 + 1;
  int right = start * 2 + 2;

  if (left < tree.size()) {
    postorder(left, tree, arr);
  }

  if (right < tree.size()) {
    postorder(right, tree, arr);
  }

  arr->push_back(*tree[start]);
}

void levelorder(int start, vector<int*> tree, vector<int>* arr) {
  vector<int> queue;

  queue.push_back(start);

  while (queue.size() > 0) {
    int node = queue[0];

    queue.erase(queue.begin());

    arr->push_back(*tree[node]);

    int left = node * 2 + 1;
    int right = node * 2 + 2;

    if (left < tree.size() && tree[left] != NULL) {
      queue.push_back(left);
    }

    if (right < tree.size() && tree[right] != NULL) {
      queue.push_back(right);
    }
  }
}

int height(int start, vector<int*> tree) {
  if (tree[start] == NULL) {
    return 0;
  } else {
    int left = 2 * start + 1;
    int right = 2 * start + 2;

    int leftHeight = 0;
    int rightHeight = 0;

    if (left < tree.size()) {
      leftHeight = height(left, tree);
    }

    if (right < tree.size()) {
      rightHeight = height(right, tree);
    }

    if (leftHeight > rightHeight) {
      return leftHeight + 1;
    } else {
      return rightHeight + 1;
    }
  }
}

int main() 
{
    vector<int*> tree;
    
    for (int i = 1; i <= 7; i++) {
      if (i == 6) {
        tree.push_back(NULL);
      } else if (i == 7) {
        tree.push_back(new int(6));
      } else {
        tree.push_back(new int(i));
      }
    }
    
    vector<int> arr;
    
    preorder(0, tree, &arr);
    
    cout << "preorder: ";
    
    print_traversal(arr);
    
    arr.clear();
    
    inorder(0, tree, &arr);
    
    cout << "inorder: ";
    
    print_traversal(arr);

    arr.clear();

    postorder(0, tree, &arr);

    cout << "postorder: ";

    print_traversal(arr);

    arr.clear();

    levelorder(0, tree, &arr);

    cout << "level order: ";

    print_traversal(arr);

    cout << "height: " << height(0, tree);
    
    return 0;
}

void print_traversal(vector<int> arr) {
  for (int i = 0; i < arr.size(); i++) {
    if (i == arr.size() - 1) {
      cout << arr[i] << endl;
    } else {
      cout << arr[i] << "->";
    }
  }
}