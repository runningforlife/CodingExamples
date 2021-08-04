#include <iostream>
#include <string.h>
#include "linked_list.h"
#include "stack.h"
#include "binary_search_tree.h"

int main(void) {
    LinkedList *list = new LinkedList();

    std::cout << "the size of list is: " << list->size() << std::endl;

    list->addToHead(3);
    list->addToTail(5);
    list->addToHead(8);
    list->addToHead(10);

    list->delFromHead();
    list->addToHead(11);
    list->addToHead(13);
    list->delNode(5);
    std::cout << "the size of list is: " << list->size() << std::endl;

    list->dump();


     std::string s = "32324242";
     Stack<char> chs;     
     for (std::string::size_type i = 0; i < s.size(); ++i) {
          chs.push(s[i]);
     }

     while(!chs.isEmpty()) {
          std::cout << chs.top() << std::endl;
          chs.pop();
     }

     BinaryTree *bt = new BinaryTree();
     if (bt != NULL) {
          bt->insert(8);
          bt->insert(5);
          bt->insert(9);
          bt->insert(10);

          struct TreeNode *node = bt->find(10);
          std::cout << (node != NULL ? "found" : "not found") << " node in tree" << std::endl;
          if (node != NULL) {
               std::cout << "node value is " <<  node->key << std::endl;
          }
          bt->dumpTree();
     }

    return 0;
}
