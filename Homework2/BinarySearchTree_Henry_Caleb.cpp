#include <iostream>

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

    int data; 
    Node* left;
    Node* right;

};

class BST {
  public:
    BST() {
      root = NULL;
    }

    void InsertBelow(Node* root, int data) {
      if(data > root->data) {
        if(root->right) {
          InsertBelow(root->right, data);
        } else {
          root->right = new Node(data);
        }
      } else if(data < root->data) {
        if(root->left) {
          InsertBelow(root->left, data);
        } else {
          root->left = new Node(data);
        }
      } else {
        std::cout << "Duplicate Node" << std::endl;
      }
    }

    void Insert(int data) {
      if(!root) {
        root = new Node(data);
      } else {
        InsertBelow(root, data);
      }
    }

    void Delete(int data) {
      Node* del = root;
      Node* delParent = NULL;
      while(del->data != data) {
        if(del->data < data) {
          delParent = del;
          del = del->right;
        } else {
          delParent = del;
          del = del->left;
        }
      }
      if(!del->right && !del->left) {
        if(delParent->data < data) {
          delParent->right = NULL;
        } else {
          delParent->left = NULL;
        }
      } else if(del->right && del->left) {
        Node* swap = del->right;
        Node* swapParent = NULL;
        while(swap->left) {
          swapParent = swap;
          swap = swap->left;
        }
        del->data = swap->data;
        if(!swapParent) {
          del->right = NULL;
        } else {
          swapParent->left = NULL;
        }
      } else {
        if(del->right) {
          delParent->right = del->right;
        } else {
          delParent->left = del->left;
        }
      }
    }

    void Search(int data) {
      Node* del = root;
      while(del && del->data != data) {
        std::cout << del->data << " -> ";
        if(del->data < data) {
          del = del->right;
        } else {
          del = del->left;
        }
      }
      if(!del) {
        std::cout << "search key not found" << std::endl;
      } else {
        std::cout << del->data << std::endl;
      }
    }

    int Smallest() {
      Node* min = root;
      while(min->left) {
        min = min->left;
      }
      return min->data;
    }

    int Largest() {
      Node* max = root;
      while(max->right) {
        max = max->right;
      }
      return max->data;
    }

    void Print() {
      printInOrder(root);
      std::cout << std::endl;
    }

    Node* root;

  private:
    void printInOrder(Node* root) {
      if(!root) {
        return;
      }
      printInOrder(root->left);
      std::cout << root->data;
      printInOrder(root->right);
    }
};

int main(int argc, char *argv[]) {
  BST bTree = BST();
  bTree.Insert(5);
  bTree.Insert(3);
  bTree.Insert(1);
  bTree.Insert(4);
  bTree.Insert(7);
  bTree.Insert(8);
  bTree.Print();
  bTree.Delete(4);
  bTree.Print();
  bTree.Insert(2);
  bTree.Print();
  bTree.Insert(7);
  bTree.Print();
  bTree.Search(9);
  std::cout << bTree.Smallest() << std::endl;
  std::cout << bTree.Largest() << std::endl;
}


