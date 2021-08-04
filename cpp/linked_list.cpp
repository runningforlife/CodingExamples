#include <iostream>
#include <stdlib.h>
#include "linked_list.h"


LinkedList::~LinkedList() {
     ListNode *p;
     while (isEmpty()) {
		p = head->next;
		delete head;
		head = p;
     }
}

bool LinkedList::isEmpty() {
    return head == NULL;
}

void LinkedList::addToHead(int val) {
    ListNode *node = new ListNode(val);
    if (isEmpty()) {
		head = tail = node;
    } else {
		node->next = head;
        head = node;
    }
}

void LinkedList::addToTail(int val) {
    ListNode *node = new ListNode(val);
    if (isEmpty()) {
		head = tail = node;
    } else {
		tail->next = node;
		tail = node;
    }
}

int LinkedList::delFromHead() {
    if (!isEmpty()) {
		ListNode *tmp = head;
		int res = tmp->value;
		if (head == tail) {
			tail = NULL;
		} else {
			head = head->next;
			delete tmp;

			return res;
		}
	}

    return -1;
}

int LinkedList::delFromTail() {
     if (!isEmpty()) {
		if (head == tail) {
			delete tail;
			head = tail = NULL;
		} else {
			ListNode *p = head;
			while (p->next != tail) {
				p = p->next;
			}
			delete tail;
			tail = p;
		}
     }
     return -1;
}

void LinkedList::delNode(int val) {
   if (!isEmpty()) {
		if (head->value == val) {
			ListNode *p = head;
			if (head == tail) {
				head == tail == NULL;
			} else head = head->next;
			delete p;
		} else {
			ListNode *p = head;
			while (p->next != NULL) {
				if (p->next->value == val) break;
				p = p->next;
			}

			if (p->next != NULL) {
				ListNode *tmp = p->next;
				if (tmp == tail) {
					tail = p;
				}
					p->next = tmp->next;
				delete tmp;
			}
		}
   }
}


bool LinkedList::isInList(int val) const {
    ListNode *p = head;
    while (p != NULL) {
		if (p->value == val) return true;
		p = p->next;
    }

    return false;
}


unsigned int LinkedList::size() const {
     unsigned int len = 0;
     ListNode *p = head;
     while(p != NULL) {
		++len;
		p = p->next;
     }
    
     return len;
}

void LinkedList::dump() const {
    ListNode *p = head;
    if (p != NULL) {
		std::cout << p->value;
    }
    p = p->next;
    while (p != NULL) {
		std::cout << "->";
		std::cout << p->value;
		p = p->next;
    }

    std::cout << std::endl;
}
