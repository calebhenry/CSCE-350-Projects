#include <iostream>
#include <string>

/**
 * @brief The node class holds an integer and two pointers to its children
 * 
 */
class Node{
  public:
    /**
     * @brief Construct a new Node object
     * 
     */
    Node() {
      data = 0;
      left = NULL;
      right = NULL;
    }

    /**
     * @brief Construct a new Node object using a parameter
     * 
     * @param data The value stored in the node
     */
    Node(int data) {
      this->data = data;
      left = NULL;
      right = NULL;
    }

    int data; 
    Node* left;
    Node* right;

};

/**
 * @brief The bst class holds a root node and functions to interact with the tree
 * 
 */
class BST {
  public:
    /**
     * @brief Construct a new BST object
     * 
     */
    BST() {
      root = NULL;
    }

    /**
     * @brief Inserts the data into the tree
     * 
     * @param data The data that will be inserted
     */
    void Insert(int data) {
      if(!root) {
        root = new Node(data);
        std::cout << "Node " << data << " has been inserted." << std::endl;
      } else {
        InsertBelow(root, data);
      }
    }

    /**
     * @brief Deletes the data from the tree
     * 
     * @param data The data that will be inserted
     */
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
          if(delParent) {
            delParent->right = del->right;
          } else {
            root = del->right;
          }
        } else {
          if(delParent) {
            delParent->left = del->left;
          } else {
            root = del->left;
          }
        }
      }
      std::cout << "Node " << data << " has been deleted." << std::endl;
    }

    /**
     * @brief Searched for data in the tree and prints the path it took to get there
     * 
     * @param data The data that is being searched for
     */
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

    /**
     * @brief Finds the smallest value in the tree
     * 
     * @return int The smallest value in the tree
     */
    int Smallest() {
      Node* min = root;
      while(min->left) {
        min = min->left;
      }
      return min->data;
    }

    /**
     * @brief Finds the largest value in the tree
     * 
     * @return int The largest value in the tree
     */
    int Largest() {
      Node* max = root;
      while(max->right) {
        max = max->right;
      }
      return max->data;
    }

    /**
     * @brief Prints the values in the tree in order
     * 
     */
    void Print() {
      std::cout << "BST nodes are: ";
      printInOrder(root);
      std::cout << std::endl;
    }

    Node* root;

  private:
    /**
     * @brief Recursively prints the nodes of the tree
     * 
     * @param root The node that will be printed
     */
    void printInOrder(Node* root) {
      if(!root) {
        return;
      }
      printInOrder(root->left);
      std::cout << root->data << " ";
      printInOrder(root->right);
    }

    /**
     * @brief Recursively inserts the node into the tree
     * 
     * @param root The node that the data will be inserted below
     * @param data The data that will be inserted
     */
    void InsertBelow(Node* root, int data) {
      if(data > root->data) {
        if(root->right) {
          InsertBelow(root->right, data);
        } else {
          root->right = new Node(data);
          std::cout << "Node " << data << " has been inserted." << std::endl;
        }
      } else if(data < root->data) {
        if(root->left) {
          InsertBelow(root->left, data);
        } else {
          root->left = new Node(data);
          std::cout << "Node " << data << " has been inserted." << std::endl;
        }
      } else {
        std::cout << "Node " << data << " is a duplicate node. Cannot insert node " << 
          data <<" again." << std::endl;
      }
    }
};

int main(int argc, char *argv[]) {
  BST bTree = BST();
  std::cout << "Welcome! Here are the available commands: " <<
    "\n\tInsert node (node #): Inserts the node with the supplied number " << 
    "\n\tDelete node (node #): Deletes the node that matches the supplied number" << 
    "\n\tSearch node (node #): Searches for the supplied number in the tree and prints the path" << 
    "\n\tBST node with the smallest value: Returns the smallest value in the BST" << 
    "\n\tBST node with the largest value: Returns the largest value in the BST" <<std::endl;
  while(true) {
    std::string input;
    std::getline(std::cin, input);
    if(input.c_str()[0] =='I') {
      bTree.Insert(atof(input.substr(input.find_last_of(' ')).c_str()));
      bTree.Print();
    } else if(input.c_str()[0] =='D') {
      bTree.Delete(atof(input.substr(input.find_last_of(' ')).c_str()));
      bTree.Print();
    } else if(input.substr(0, input.find(" ")) == "Search") {
      bTree.Search(atof(input.substr(input.find_last_of(' ')).c_str()));
      bTree.Print();
    } else if(input.find("smallest") != std::string::npos) {
      std::cout << "Node " << bTree.Smallest() << std::endl;
      bTree.Print();
    } else if(input.find("largest") != std::string::npos ){
      std::cout << "Node " <<  bTree.Largest() << std::endl;
      bTree.Print();
    } else {
      std::cout << "Did not recognize command - Enter again" << std::endl;
    }
  }
}


