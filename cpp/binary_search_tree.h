#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_Hi

struct TreeNode {
    int key;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode() {
        this->key = -1;
        this->left = nullptr;
        this->right = nullptr;
    }

    TreeNode(int key) {
        this->key = key;
        this->left = nullptr;
        this->right = nullptr;
    }
};


class BinaryTree {
public:
    BinaryTree() {
        root = nullptr; 
    }

    void insert(int key);

    struct TreeNode *find(int key);
    
    struct TreeNode *deleteNode(int key);

    void dumpTree();

private:
    struct TreeNode *root;

    void insertRecursive(int key, struct TreeNode *&node);

    struct TreeNode *findNode(int key, struct TreeNode *node);

    void visitTree(struct TreeNode *node, int* count);
};


#endif
