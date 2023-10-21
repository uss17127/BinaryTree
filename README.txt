Program: main.cpp BinaryTree.cpp
------------------------------------------------------------------------------
BinaryTree file functions and variables
class BinaryTree {
private:
    Node<T> *root;
    int singleParents;
    int leafNode;
    T sum;
public:
    bool sumT;
    BinaryTree();
    ~BinaryTree();
    void destroy(Node<T> *&node);
    void insert(T &key);
    bool insertItem(Node<T> *&node, T &item);
    void deleteItem(T &key);
    void deleteFind(Node<T> *&node, T &item);
    void deleteNode(Node<T> *&node);
    void getPredecessor(Node<T> *node, T &data);
    void retrieve(T &item, bool &found) const;
    void find(Node<T> *node, T &item, bool &found) const;
    void preOrder() const;
    void preOrderPrint(Node<T> *node) const;
    void inOrder() const;
    void inOrderPrint(Node<T> *node) const;
    void postOrder() const;
    void postOrderPrint(Node<T> *node) const;
    int getLength() const;
    int calcLength(Node<T> *node) const;
    int getNumSingleParent();
    void numSingleParent(Node<T> *&node);
    int getNumLeafNodes();
    void numLeafNodes(Node<T> *&node);
    T getSumOfSubTrees(T data);
    void sumSub(Node<T> *&node, T item);

};
-----------------------------------------------------------------------
Psuedo code and time complexity:

- Finding number of single parents
getNumSingleParent() {
   //Calls numOfSingleParent because it is an auxillary function
}

numOfSingleParent(Node<T> *&node) {
    if (node does not equal null && either node-> or node->left must not equal null - not at the same time) {
       //adds 1 to count num of single parents
       int single parets += 1
    }
    if (node == null) {
       //recursive call
       numOfSingleParent(node->right)
       numOfSingleParent(node->left)
       }
}

Recurrence Relationship:
           T(n) = 2T(n/2) + constant
           -searching both left and right subtree so its 2
           - 2 subproblems - size of each sub problem is 2

Time Complexity:
     n ^log base2 2 = O(N)

- Finding number of leaf nodes
int getNumLeafNodes() {
    //auxillary function
    numLeafNodes(this->root);
    return this->leafNode;
}

void numLeafNodes(Node<T> *&node) {
    if (node != NULL && node left and right are NULL) {
        this->leafNode += 1; //this meand node is a leaf

    }
    if (node != NULL) {
    numLeafNodes(node->left);
    numLeafNodes(node->right);
    }
}

Recurrence Relationship:
           T(n) = 2T(n/2) + constant
           -searching both left and right subtree so its 2
           - 2 subproblems - size of each sub problem is 2

Time Complexity:
     n ^log base2 2 = O(N)

- Finding sum of subtree

T getSumOfSubTrees(T data) {
    //auxillary functiom
    sumSub(this->root, data);
    return this->sum;
}

void sumSub(Node<T> *&node, T item) {
    if (node == NULL) {
        //No sum - node does not exist
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

Recurrence Relationship:
           T(n) = nT(n/2) + 1
           - number of suproblems is n

Time Complexity:
     O(log  (n)) = n ^log base2 n
          2
