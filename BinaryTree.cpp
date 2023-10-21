#include <iostream>
#include "BinaryTree.h"
using namespace std;

/*
   Constuctor intializes length, singleParents, and leafNode.
   The root is set to NULL;
*/
template<class T>
BinaryTree<T>::BinaryTree() {
    this->root = NULL;
    //Stores num of single parents in BST
    this->singleParents = 0;
    //Stores num of nodes without chidren
    this->leafNode = 0;
    this->sumT = true;
}

/*
  Destructor - (auxillary function) calls function that frees node pointers and points root to null
*/
template<class T>
BinaryTree<T>::~BinaryTree() {
    destroy(this->root);
}

/*
  Frees node pointers and points root to null
 */
template<class T>
void BinaryTree<T>::destroy(Node<T> *&node) {
    if (node != NULL) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

/*
  Auxillary function that calls insert item if T &key is not found in any nodes
*/
template<class T>
void BinaryTree<T>::insert(T &key) {
    bool search = true;
    search = insertItem(this->root, key);
    if (search == false) {
        cout << "Item already in tree." << endl;
    }

}

/*
  Inserts item if T &item is not found in any nodes within he BST.
  Returns true if item is not found. Returns false if item is found.
*/
template<class T>
bool BinaryTree<T>::insertItem(Node<T> *&node, T &item) {
    //if tree is empty
    if (node == NULL) {
        node = new Node<T>();
        node->key = item;
        node->left = NULL;
        node->right = NULL;

    }
    else if (node->key > item) {
        insertItem(node->left, item);
    } else if (node->key < item) {
        insertItem(node->right, item);
    } else {
        return false;
    }
    return true;
}

/*
  Auxillary function that calls delete find to find if T &key exists
  within the BST.
*/
template<class T>
void BinaryTree<T>::deleteItem(T &key) {
    deleteFind(this->root, key);
}

/*
  Searches BST for item, and if it is found, it calls deletenode.
*/
template<class T>
void BinaryTree<T>::deleteFind(Node<T> *&node, T &item) {
    if (node != NULL) {
        if (item < node->key) {
            deleteFind(node->left, item);

        } else if (item > node->key) {
            deleteFind(node->right, item);
        } else {
            deleteNode(node);
        }
    } else {
        cout << "Item not in tree." << endl;
        return;
    }
}

/*
  Deletes node and replaces node with predecessor if need be.
*/
template<class T>
void BinaryTree<T>::deleteNode(Node<T> *&node) {
    T data;
    Node<T> *temp;
    temp = node;
    if (node->left == NULL) {
        node = node->right;
        delete temp;
    } else if (node->right == NULL) {
        node = node->left;
        delete temp;
    } else {
        getPredecessor(node->left, data);
        node->key = data;
        deleteFind(node->left, data);
    }
}

/*
  Finds predecessor to replace node key of node that needs to be deleted.
*/
template<class T>
void BinaryTree<T>::getPredecessor(Node<T> *node, T &data) {
    while (node->right != NULL) {
        node = node->right;
    }
    data = node->key;
}

/*
  Auxillary function that calls find. Will print out if such key exists
  within the node or not based on if find1 is true or false.
*/
template<class T>
void BinaryTree<T>::retrieve(T &key, bool &found) const {
    Node <T> *node = this->root;
    T item = key;
    bool find1 = found;
    find(node, item, find1);
    if (find1 == false) {
        cout << "Item not in tree." << endl;
    } else {
        cout << "Item found in tree." << endl;
    }
}

/*
  Traverse binary tree and sets bool to true or false based on
  if item is found or not.
*/
template<class T>
void BinaryTree<T>::find(Node<T> *node, T &item, bool &found) const {
    if (node == NULL) {
        found = false;
    } else if (node->key > item) {
        find(node->left, item, found);
    } else if (node->key < item) {
        find(node->right, item, found);
    } else {
        found = true;
        item = node->key;
    }
}

/*
  Auxillary function to print preorder.
*/
template<class T>
void BinaryTree<T>::preOrder() const{
    preOrderPrint(this->root);
}

/*
  Prints preorder traversal of tree.
*/
template<class T>
void BinaryTree<T>::preOrderPrint(Node<T> *node) const {
    if (node != NULL) {
        cout << node->key << " ";
        preOrderPrint(node->left);
        preOrderPrint(node->right);
    }
}

/*
  Auxillary function to print inOrder.
*/
template<class T>
void BinaryTree<T>::inOrder() const {
    inOrderPrint(this->root);
}

/*
  Prints in order traversal of tree.
*/
template<class T>
void BinaryTree<T>::inOrderPrint(Node<T> *node) const {
    if (node != NULL) {
        inOrderPrint(node->left);
        cout << node->key << " ";
        inOrderPrint(node->right);
    }
}

/*
  Auxillary function to print postOrder.
*/
template<class T>
void BinaryTree<T>::postOrder() const {
    postOrderPrint(this->root);
}

/*
  Prints post order traversal of tree.
*/
template<class T>
void BinaryTree<T>::postOrderPrint(Node<T> *node) const{
    if (node != NULL) {
        postOrderPrint(node->left);
        postOrderPrint(node->right);
        cout << node->key << " ";
    }
}

/*
  Auxillary function to calculate length of BST. Returns length of BST.
*/
template<class T>
int BinaryTree<T>::getLength() const {
    return calcLength(this->root);
}

/*
   Caculates the length of BST by traversing through tree.
*/
template<class T>
int BinaryTree<T>::calcLength(Node<T> *node) const {
    if (node == NULL) {
        return 0;
    } else {
        return calcLength(node->left) + calcLength(node->right) + 1;
    }

}

/*
  Auxillary function to find the number of single parents within the BST.
*/
template<class T>
int BinaryTree<T>::getNumSingleParent() {
    numSingleParent(this->root);
    return this->singleParents;
}

/*
  Finds number of single parents within BST.
*/
template<class T>
void BinaryTree<T>::numSingleParent(Node<T> *&node) {
    if (node != NULL && ((node->left != NULL && node->right == NULL)||
    (node->left == NULL && node->right != NULL))) {
        this->singleParents += 1;

    }
    if (node != NULL) {
    numSingleParent(node->left);
    numSingleParent(node->right);
    }
}

/*
  Auxillary function to find the number of leaf nodes within the BST.
*/
template<class T>
int BinaryTree<T>::getNumLeafNodes() {
    numLeafNodes(this->root);
    return this->leafNode;
}

/*
  Finds number of leaf nodes within the BST.
*/
template<class T>
void BinaryTree<T>::numLeafNodes(Node<T> *&node) {
    if (node != NULL && (node->left == NULL && node->right == NULL)) {
        this->leafNode += 1;

    }
    if (node != NULL) {
    numLeafNodes(node->left);
    numLeafNodes(node->right);
    }
}

/*
  Auxillary function to find the the sum of a subtrees of a given data.
*/
template<class T>
T BinaryTree<T>::getSumOfSubTrees(T data) {
    sumSub(this->root, data);
    return this->sum;
}

/*
  Finds item within the BST and calculates the sum of its subtrees.
*/
template<class T>
void BinaryTree<T>::sumSub(Node<T> *&node, T item) {
    if (node == NULL) {
        this->sumT = false;
    } else if (node->key > item) {
        sumSub(node->left,item);
    } else if (node->key < item) {
        sumSub(node->right,item);
    } else {
        this->sumT = true;
        if (node->left != NULL) {
            this->sum += node->left->key;
        }
        if (node->right != NULL) {
            this->sum += node->right->key;
        }
    }
}



template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<std::string>;
