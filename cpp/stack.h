#ifndef _STACK_H
#define _STACK_H

#include <list>

using std::list;

template <typename T>
class Stack {
public:
    Stack() {}

    bool isEmpty() const {
        return elements.empty();
    }

    void push(const T& element) {
        elements.push_back(element);
    }

    T pop() {
        T res = elements.back();
        elements.pop_back();
        return res;
    }

    void clear() {
        elements.clear();
    }

    T top() {
        return elements.back();
    }


private:
    list<T> elements;
};

#endif
