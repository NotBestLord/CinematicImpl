#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

template <class T>
class LinkedList {
private:
    T val;
    LinkedList<T> next;

public:
    LinkedList(const T& val) : val(val), next(nullptr) {}
    LinkedList(const LinkedList& other) : next(nullptr)
    {
        *this = other;
    }
    const LinkedList& operator=(const LinkedList<T>& other)
    {
        if (this != &other)
        {
            this->val = other.val;
            delete this->next;
            this->next = other.next;
        }
        return *this;
    }
    ~LinkedList()
    {
        if (hasNext()) delete next;
    }
    
    const T getVal() const { return val; }
    void setVal(T val) { this->val = val; }
    const bool hasNext() const { return next != nullptr; }
    const LinkedList<T> getNext() const { return next; }
    void setNext(LinkedList<T> next) { this->next = next; }

    const LinkedList& operator+=(T* val)
    {
        LinkedList<T> addTo = *this;
        while (addTo.hasNext()) addTo = addTo.getNext();
        addTo.setNext(new LinkedList(val));
    }
};

#endif
