//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLELINKEDNODE_H
#define LINKEDLIST_DOUBLELINKEDNODE_H
#include <iostream>
#include <memory>


template<typename T>
class DoublyLinkedNode {
class DoublyLinkedList;
private:
    friend DoublyLinkedList;
    T value;
    std::unique_ptr<DoublyLinkedNode<T>> next;
    DoublyLinkedNode<T>* prev;
public:
    DoublyLinkedNode() = default;

    void setValue(T contents) {
        value = contents;
    }

//    void setNextNull() {
//        next = std::move(nullptr);
//    }


    void setNext(std::unique_ptr<DoublyLinkedNode<T>> nextNode) {
        next = std::move(nextNode);
    }

    void setPrev(DoublyLinkedNode<T>* prevNode) {
        prev = prevNode;
    }

    const T& getValueConst() const {
        return value;
    }

    T& getValue() {
        return value;
    }

    DoublyLinkedNode<T>* getNext() const { //get next returns the dumb pointer if you want the unique version use
        return next.get();
    }

    std::unique_ptr<DoublyLinkedNode<T>>& getNextUnique() {
        return next;
    }

    std::unique_ptr<DoublyLinkedNode<T>>& getNCNext() {
        return next;
    }

    DoublyLinkedNode<T>* getPrev() const {
        return prev;
    }

};

#endif //LINKEDLIST_DOUBLELINKEDNODE_H
