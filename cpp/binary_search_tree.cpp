#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>

void BinaryTree::insertRecursive(int key, struct TreeNode *&node) {
    if (node == nullptr) {
        node = new TreeNode(key);
        return;
    }

    if (node->key > key) insertRecursive(key, node->left);

    if (node->key < key) insertRecursive(key, node->right);
}

struct TreeNode *BinaryTree::findNode(int key, struct TreeNode *node) {
    if (node == nullptr || node->key == key) return node;

    if (node->key > key) findNode(key, node->left);

    if (node->key < key) findNode(key, node->right);
}

void BinaryTree::visitTree(struct TreeNode *node, int *count) {
    if (node == nullptr) return;

    (*count)++;
    printf("key=%d, node count=%d\n", node->key, *count);

    visitTree(node->left, count);
    visitTree(node->right, count);
}

void BinaryTree::insert(int key) {
    insertRecursive(key, this->root);
}

struct TreeNode *BinaryTree::find(int key) {
    return findNode(key, this->root);
}

void BinaryTree::dumpTree() {
    static int nodeCount = 0;
    visitTree(this->root, &nodeCount);
}

int main(void) {
    BinaryTree *bt = new BinaryTree();
    if (bt != nullptr) {
        bt->insert(10);
        bt->insert(3);
        bt->insert(8);
        bt->insert(12);
        bt->insert(34);
        bt->insert(15);

        bt->dumpTree();
    }
    printf("main done\n");
}
