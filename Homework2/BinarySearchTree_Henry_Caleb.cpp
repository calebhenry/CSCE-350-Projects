#include <iostream>

class Node;

class Node{
  public:
    Node() {
      data = 0;
      left = NULL;
      right = NULL;
    }

    Node(int data) {
      this->data = data;
      left = NULL;
      right = NULL;
    }

    static void InsertBelow(Node root, int data) {
      if(data > root.data && root.right != NULL) {
        InsertBelow(*root.right, data);
      } else if(data < root.data && root.left != NULL) {
        InsertBelow(*root.left, data);
      } else if(data > root.data) {
        root.right = new Node(data);
      } else {
        root.left = new Node(data);
      }
    }

    int data; 
    Node* left;
    Node* right;

};

class BST {
  public:
    BST() {
      root = NULL;
    }

    void Insert(int data) {
      if(root == NULL) {
        root = new Node(data);
      } else {
        Node::InsertBelow(*root, data);
      }
    }

    void Print() {
      
    }

    Node* root;
};

int main(int argc, char *argv[]) {
  BST bTree = BST();
  bTree.Insert(5);
  bTree.Insert(3);
  bTree.Insert(1);
  bTree.Insert(7);
}


