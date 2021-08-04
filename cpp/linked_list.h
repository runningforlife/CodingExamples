#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct ListNode {
    ListNode() {
        next = NULL;
    }

    ListNode(int val, ListNode *in = NULL) {
        this->value = val;
        this->next = in;
    }

    int value;
    ListNode *next;
};


class LinkedList {
public:
     LinkedList() {
         head = tail = NULL;
     }

     ~LinkedList();
     
     bool isEmpty();
     void addToHead(int val);
     void addToTail(int val);
     int  delFromHead();
     int  delFromTail();
     void delNode(int val);
     bool isInList(int val) const;
     unsigned int size() const;
     void dump() const;
private:
    ListNode *head, *tail;
};

#endif
