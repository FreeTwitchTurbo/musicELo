//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLYLINKEDLIST_H
#define LINKEDLIST_DOUBLYLINKEDLIST_H

#include <vector>
#include <memory>
#include "DoublyLinkedNode.h"
#include "DoublyLinkedListEmptyError.h"
#include "ConstDoublyLinkedListIterator.h"
#include "DoublyLinkedListIterator.h"
#include "ConstReverseDoublyLinkedIterator.h"
#include "ReverseDoublyLinkedListIterator.h"
#include <string>

template<typename T>
class DoublyLinkedList {

 public:
  using Node_Ptr = DoublyLinkedNode<T>*;
  using iterator = DoublyLinkedListIterator<T>; //put the type of your iterator here
  using const_iterator =  ConstDoublyLinkedListIterator<T>; //put the type of your const iterator here
  using reverse_iterator = ReverseDoublyLinkedListIterator<T>; //put the type of your reverse iterator here
  using const_reverse_iterator = ConstReverseDoublyLinkedListIterator<T>; //put the type of your const reverse iterator here

  //create a Doubly Linked List that has the same values
  //as in the vector and in the same order
  explicit DoublyLinkedList(const std::vector<T>& values);

  //create an empty DoublyLinkedList
  DoublyLinkedList();


  //destructor
  virtual ~DoublyLinkedList();

  //remove all of the elements from your list
  void clear();

  //get a reference to the front element in the list
  const T& front() const;
  T& front();

  //get a reference to the last element in the list
  const T& back() const;
  T& back();

  //add a value to the front of the list
  void push_front(const T& value);

  //add a value to the back of the list
  void push_back(const T& value);

  //is the list empty?
  bool empty() const;

  //return the number of elements in the list
  int size() const;

  //return a constant bidirectional iterator to the front of the list
  const_iterator begin() const;
  const_iterator end() const;

  //return a nonconstant bidirectional iterator to the front of the list
  iterator begin();
  iterator end();
  iterator tailItr();

  const_reverse_iterator crbegin() const;
  const_reverse_iterator crend() const;

  reverse_iterator rbegin();
  reverse_iterator rend();

  //insert the value at the position in the list
  //I promise not to use the iterator again after the insertion is done
  //An example if we had the list 1 <-> 9 <-> 17
  //And the iterator was pointing to the 9 and we wanted to
  //insert -22 the result would be
  //1 <-> 22 <-> 9 <-> 17
  void insert(iterator& position, const T& value);

  //remove the element at the position pointed to
  //by the iterator.
  //I promise not to use the iterator again after the erase is done
  //An example if we had the list 1 <-> 9 <-> 17
  //And when the wanted to erase the iterator was at the 9
  //1 <-> 17
  void erase(iterator& position);

  DoublyLinkedNode<T>* getNode(int pos) {
      auto cur = head;
      for (int i = 0; i < pos; ++i) {
          cur = cur->next;
      }
      return cur;
  }

 private:
    friend DoublyLinkedNode<T>;
    std::unique_ptr<DoublyLinkedNode<T>> head;
    DoublyLinkedNode<T>* tail;
    int listSize;

    void insertAt(T val, int n);
};
//write to the stream each element in the list in order
//with a space in between them
template<typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& doublyLinkedList);

//read elements from the stream as long as it is good
// or until a newline (\n) is encountered
//if a newline is encountered it should be consumed
template<typename T>
std::istream& operator>>(std::istream& in, DoublyLinkedList<T>& doublyLinkedList);

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), listSize(0) {

}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const std::vector<T>& values) : head(nullptr), tail(nullptr), listSize(0) {
    for(int i = 0; i < (int)values.size(); ++i) {
        this->push_back(values.at(i));
    }
}

template<typename T>
void DoublyLinkedList<T>::insertAt(T val, int n){
    auto itr = this->begin();
    for(int i = 0; i < n; ++i){
        ++itr;
    }
    insert(itr, val);
}

template<typename T>
bool DoublyLinkedList<T>::empty() const {
    return (this->size() > 0);
}

template<typename T>
int DoublyLinkedList<T>::size() const {
    return listSize;
}

template<typename T>
const T& DoublyLinkedList<T>::front() const {
    if(listSize == 0){
        throw DoublyLinkedListEmptyError();
    }
    return *head;
}

template<typename T>
T& DoublyLinkedList<T>::front() {
    if(listSize == 0){
        throw DoublyLinkedListEmptyError();
    }
    return *(this->begin());
}

template<typename T>
const T& DoublyLinkedList<T>::back() const {
    if(listSize == 0){
        throw DoublyLinkedListEmptyError();
    }
    return *tail;
}

template<typename T>
T& DoublyLinkedList<T>::back() {
    if(listSize == 0){
        throw DoublyLinkedListEmptyError();
    }
    return *(this->rbegin());
}

template<typename T>
void DoublyLinkedList<T>::push_front(const T& value) {
    auto itr = this->begin();
    insert(itr,value);
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
    if(size() == 0){
        auto itr = this->begin();
        insert(itr,value);
    }else{
        auto newNode = std::make_unique<DoublyLinkedNode<T>>(); // will we have to destruct this?
        newNode->setValue(value);
        newNode->setNext(nullptr); //set new node's next to nullptr
        newNode->setPrev(tail); //set new node's prev to tail
        auto& currentTail = *tail;
        //tail -> next = std::move(newNode);
        currentTail.setNext(std::move(newNode)); //move the ownership from newNode to next of prev
        tail = currentTail.getNext(); //set tail to point at new node's dumb pointer
        ++listSize;
    }
}

template<typename T>
void DoublyLinkedList<T>::clear() {

    while(this->size() > 0) {
        erase(this->begin());
    }

}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {

}

template<typename T>
typename DoublyLinkedList<T>::const_iterator DoublyLinkedList<T>::begin() const {
    return ConstDoublyLinkedListIterator<T>(head.get());
    //.get here because head needs to be unique pointer, get returns the dumb pointer
}

template<typename T>
typename DoublyLinkedList<T>::const_iterator DoublyLinkedList<T>::end() const {
    return ConstDoublyLinkedListIterator<T>(nullptr);
}

template<typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::begin() {
    // the compiler keeps screaming abt this and I can't seem to fix it
    // I think it has to do with it being a unique pointer and not realizing the iterator is const
    return DoublyLinkedListIterator<T>(head.get());
}

template<typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::end() {
    return DoublyLinkedListIterator<T>(nullptr);
}

template<typename T>
void DoublyLinkedList<T>::insert(iterator& position, const T& value) {
    auto newNode = std::make_unique<DoublyLinkedNode<T>>(); // will we have to destruct this?
    newNode->setValue(value);
    //i now know more about unique pointers then i ever thought i would
    if(listSize == 0) {
        newNode->setNext(nullptr); //new node's next and prev is nullptr
        newNode->setPrev(nullptr); // Had to add setters, not sure if I retained what you were trying to do though, since
        head = std::move(newNode); //head now owns new node
        tail = head.get(); //tail points to head
        // move transfers ownership of the smart pointer so all backwards pointers must be dumb pointers
    }
    else if(position == this->begin()) { //insert front
        head->setPrev(newNode.get()); //whatever head is pointing at's perv is the new node
        newNode->setNext(std::move(head)); //head now belongs to new node
        newNode->setPrev(nullptr); //new node's prev is nothing
        head = std::move(newNode); //head now owns new node
        //inserting in the back is its own function now
    }
    else if(position == this->end()) {
        push_back(value);
        --listSize; //offset adding 1 in pushback
    } else { // middle insertion
        //current element's prev
        auto prev = position.getPrevNode();
        // new node's prev points to prev
        newNode->setPrev(prev);
        // new node's next points to the point of insertion (getNextUnique returns a non const form of the next datamember)
        newNode->getNextUnique() = std::move(prev->getNextUnique());
        //point of insertion's prev points to new node
        position.setPrev(newNode.get());
        //prev's next points to newNode
        prev->getNextUnique() = std::move(newNode);
    }
    ++listSize;
}

template<typename T>
void DoublyLinkedList<T>::erase(iterator& position) {
    if(listSize == 0) {
 // move transfers ownership of the smart pointer so all backwards pointers must be dumb pointers
    throw DoublyLinkedListEmptyError();
    }
    if(listSize == 1) {
        auto toRemove = std::move(head); //create dummy var to go out of scope
        head = nullptr;
        tail = nullptr;
        //this needs to remove the one thing in the thing, why is it not going out of scope
    }
    else if(position.getCurNode() == tail || position == this->end()) { //remove end. This might not work perhaps but the idea is there. The idea is that if whatever pos is pointing to is what tail is pointing to then we want to remove the end
        auto prev = tail->getPrev();
        auto toRemove = std::move(prev->getNextUnique());
        prev->setNext(nullptr);
        tail = prev;

    } else if(position == this -> begin()) { // remove front
        auto toRemove = std::move(head); //create dummy var to go out of scope
        toRemove->getNCNext()->setPrev(nullptr); //set new head's prev to nullptr
        head = std::move(toRemove->getNextUnique()); // set head to next element in list

    } else { // middle removal
        auto& currentPrev = *position.getPrevNode();  //why does the dereference not work
        // I think it can't get copied cause it contains unique pointers, so I think both need to be references
        auto& currentNext = *position.getNextNode();  //should this be a reference
        auto toRemove = std::move(currentPrev.getNextUnique());
        //currentNext -> prev = toRemove.get(); // this syntax feels super off
        //currentPrev -> next = std::move(toRemove->next);
        currentNext.setPrev(&currentPrev);
        currentPrev.setNext(std::move(toRemove->getNextUnique()));

        // new node's next points to current element
    }
    --listSize;
}

template<typename T>
typename DoublyLinkedList<T>::const_reverse_iterator DoublyLinkedList<T>::crbegin() const {
    return ConstReverseDoublyLinkedListIterator<T>(tail);
}

template<typename T>
typename DoublyLinkedList<T>::const_reverse_iterator DoublyLinkedList<T>::crend() const {
    return ConstReverseDoublyLinkedListIterator<T>(nullptr);
}

template<typename T>
typename DoublyLinkedList<T>::reverse_iterator DoublyLinkedList<T>::rbegin() {
    return ReverseDoublyLinkedListIterator<T>(tail);
}

template<typename T>
typename DoublyLinkedList<T>::reverse_iterator DoublyLinkedList<T>::rend() {
    return ReverseDoublyLinkedListIterator<T>(nullptr);
}

template<typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::tailItr() {
    return DoublyLinkedListIterator<T>(tail);
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& doublyLinkedList) {
    for(auto itr = doublyLinkedList.begin(); itr != doublyLinkedList.end(); ++itr){
        out << *itr << " ";
    }
    return out;
}
//read elements from the stream as long as it is good
// or until a newline (\n) is encountered
//if a newline is encountered it should be consumed

//does consumed mean added?
template<typename T>
std::istream& operator>>(std::istream& in, DoublyLinkedList<T>& doublyLinkedList) {
    T valueToAdd;
    while(in >> valueToAdd) {
        doublyLinkedList.push_back(valueToAdd);
        /*if(valueToAdd == '\n') {
            break;
        }*/
    }
    return in;
}

#endif //LINKEDLIST_DOUBLYLINKEDLIST_H
