#include <iostream>
using namespace std;
struct binaryTreeNode {
    char info;
    binaryTreeNode *rlink;
    binaryTreeNode *llink;
};

int heightOfTree(binaryTreeNode *current) {
    if (current == NULL) 
        return 0;
    else
        return 1 + max(heightOfTree(current->llink), heightOfTree(current->rlink));
}

void inOrderT(binaryTreeNode *current) {
    if (current != NULL) {
        inOrderT(current->llink);
        cout << current->info << " ";
        inOrderT(current->rlink);
    }
}

void preOrderT(binaryTreeNode *current) {
    if (current != NULL) {
        cout << current->info << " ";
        preOrderT(current->llink);
        preOrderT(current->rlink);
    }
}

void postOrderT(binaryTreeNode *current) {
    if (current != NULL) {
        postOrderT(current->llink);
        postOrderT(current->rlink);
        cout << current->info << " ";
    }
}
//Simple binary tree creation:
int main() {
    binaryTreeNode *root = new binaryTreeNode();
    root->info = 'A';
    binaryTreeNode *leftSubTree = new binaryTreeNode();
    binaryTreeNode *rightSubTree = new binaryTreeNode();
    root->llink = leftSubTree;
    root->rlink = rightSubTree;
    leftSubTree->info = 'B';
    rightSubTree->info = 'C';
    leftSubTree->llink = leftSubTree->rlink = NULL;
    rightSubTree->llink = rightSubTree->rlink = NULL;

    binaryTreeNode *D = new binaryTreeNode();
    D->info = 'D';
    leftSubTree->rlink = D;
    D->llink = D->rlink = NULL;

    //Printing the left-most segment of the tree
    binaryTreeNode *current = root;
    while (current != NULL) {
        cout << current->info << " ";
        current = current->llink;
    }
    
    cout << endl << heightOfTree(root);
    
    cout << endl << "Inorder: ";
    inOrderT(root);
    cout << endl << "Preorder: ";
    preOrderT(root);
    cout << endl << "Postorder: ";
    postOrderT(root);
    return 0;
}
