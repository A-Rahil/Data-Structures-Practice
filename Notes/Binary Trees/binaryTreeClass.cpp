#include <iostream>
using namespace std;
struct binaryTreeNode {
    int info;
    binaryTreeNode *rlink;
    binaryTreeNode *llink;
};

class binaryTree {
    binaryTreeNode *root;   //Only private member here
    void inOrder(binaryTreeNode *) const;
    void preOrder(binaryTreeNode *) const;
    void postOrder(binaryTreeNode *) const;
    int height(binaryTreeNode *) const;
    int nodeCount(binaryTreeNode *) const;
    int leavesCount(binaryTreeNode *) const;
    void destroy(binaryTreeNode *);
    void copyTree(binaryTreeNode *&, binaryTreeNode *);
    public:
    bool isEmpty() const;
    void inOrderT() const;
    void preOrderT() const;
    void postOrderT() const;
    int treeHeight() const;
    int treeNodeCount() const;
    int treeLeavesCount() const;
    void destroyTree();
    binaryTree();
    binaryTree(const binaryTree &);
    ~binaryTree();
    const binaryTree& operator=(const binaryTree &);
};

void binaryTree::inOrder(binaryTreeNode *current) const {
    if (current != NULL) {
        inOrder(current->llink);
        cout << current->info << " ";
        inOrder(current->rlink);
    }
}
void binaryTree::preOrder(binaryTreeNode *current) const {
    if (current != NULL) {
        cout << current->info << " ";
        inOrder(current->llink);
        inOrder(current->rlink);
    }
} 
void binaryTree::postOrder(binaryTreeNode *current) const {
    if (current != NULL) {
        inOrder(current->llink);
        inOrder(current->rlink);
        cout << current->info << " ";
    }
} 
int binaryTree::height(binaryTreeNode *current) const {
    if (current == NULL)
        return 0;
    else 
        return 1 + max(height(current->llink), height(current->rlink));
}
int binaryTree::nodeCount(binaryTreeNode *current) const {
    if (current != NULL)
        return 1 + nodeCount(current->llink) + nodeCount(current->rlink);
    else 
        return 0;
}
int binaryTree::leavesCount(binaryTreeNode *current) const {
    if (current == NULL)
        return 0;
    else if (current->llink == NULL && current->rlink == NULL) 
        return 1;
    else 
        return leavesCount(current->llink) + leavesCount(current->rlink);
}
void binaryTree::destroy(binaryTreeNode *current) {
    if (current != NULL) {
        destroy(current->llink);
        destroy(current->rlink);
        delete current;
        current = NULL;
    }
    else 
        return;
}
void binaryTree::copyTree(binaryTreeNode *&copier, binaryTreeNode *other) {
    if (other == NULL) 
        copier = NULL;
    else {
        copier = new binaryTreeNode();
        copier->info = other->info;
        copyTree(copier->llink, other->llink);
        copyTree(copier->rlink, other->rlink);
    }
}
bool binaryTree::isEmpty() const {
    return (root == NULL);
}
void binaryTree::inOrderT() const {
    inOrder(root);
}
void binaryTree::preOrderT() const {
    preOrder(root);
}
void binaryTree::postOrderT() const {
    postOrder(root);
}
int binaryTree::treeHeight() const {
    return height(root);
}
int binaryTree::treeNodeCount() const {

    return nodeCount(root);
}
int binaryTree::treeLeavesCount() const {
    return leavesCount(root);
}
void binaryTree::destroyTree() {
    destroy(root);
}
binaryTree::binaryTree() {
    root = NULL;
}
binaryTree::~binaryTree() {
    destroy(root);
}
binaryTree::binaryTree(const binaryTree &other) {
    copyTree(root, other.root);
}
const binaryTree& binaryTree::operator=(const binaryTree &other) {
    if (this != &other) {
        destroy(root);
        copyTree(root, other.root);
    }
    return *this;
}
