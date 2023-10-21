#ifndef BINARYTREE_H
#define BINARYTREE_H

template<class T>
struct Node {
    T key;
    Node<T> *left;
    Node<T> *right;
};

template<class T>
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



#endif
