//
//  Header.hpp
//  MyLinkedList
//
//  Created by Travis Hodge on 2/7/16.
//  Copyright © 2016 Travis Hodge. All rights reserved.
//

#ifndef __MyLinkedList_hpp__
#define __MyLinkedList_hpp__

// Node structure
template <class T>
struct Node{
    T value;
    Node<T> *next;
    Node<T> *prev;
    
    // Constructor
    Node(T v, Node<T> *n = nullptr, Node<T> *p = nullptr) {
        value = v;
        next = n;
        prev = p;
    }
};

// Linked list class
template <class T>
class MyLinkedList{
    
public:
    
    // Default constructor
    MyLinkedList() {
        head = tail = curr = nullptr;
    }
    
    // Copy constructor
    MyLinkedList(const MyLinkedList<T> &otherList) {
        init(otherList);
    }
    
    // Destructor
    ~MyLinkedList() {
        clear();
    }
    
    // Overloaded assignment operator
    const MyLinkedList &operator=(const MyLinkedList<T> &otherList) {
        clear();
        init(otherList);
        return *this;
    }
    
    // Linked list member functions
    void pushFront(T value);
    void pushBack(T value);
    T popFront();
    T popBack();
    bool isEmpty() {
        return head == nullptr;
    }
    void clear();
    
    // Iteration member functions
    void reset();
    void next();
    T value();
    void remove();
    void insert(T value);
    bool atEnd();
    
private:
    void init(const MyLinkedList<T> &otherList);
    Node<T> *head;
    Node<T> *tail;
    Node<T> *curr;
};

// Linked list member functions
template <class T>
void MyLinkedList<T>::pushFront(T value) {
    Node<T> *newNode = new Node<T>(value, head);
    
    if(isEmpty())
        tail = head = newNode;
    
    else {
        head->prev = newNode;
        head = head->prev;
    }
}

template <class T>
void MyLinkedList<T>::pushBack(T value) {
    Node<T> *newNode = new Node<T>(value, nullptr, tail);
    
    if(isEmpty())
        head = tail = newNode;
    
    else {
        tail->next = newNode;
        tail = tail->next;
    }
}

template <class T>
T MyLinkedList<T>::popFront() {
    T value = head->value;
    Node<T> *oldHead = head;
    
    if(head == tail)
        head = tail = nullptr;
    else {
        head = head->next;
        head->prev = nullptr;
    }
    
    delete oldHead;
    return value;
}

template <class T>
T MyLinkedList<T>::popBack() {
    T value = tail->value;
    Node<T> *oldTail = tail;
    
    if(head == tail)
        head = tail = nullptr;
    else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    
    delete oldTail;
    return value;
}
template <class T>
void MyLinkedList<T>::init(const MyLinkedList<T> &otherList){

    head = tail = nullptr;
    
    curr = otherList.head;
    
    while(curr != nullptr){

        pushBack(curr -> value);
        curr = curr -> next;
        
        
    }

}
    

template<class T>
void MyLinkedList<T>::clear(){ // Resets the curr pointer to the beginning of the list and removes each node until
                               // the head is NULL.
    
    reset();
    
    while(head != tail){
        remove();
    }
    
    head = tail = curr = nullptr; // sets all open pointers to NULL.

}

template<class T>
void MyLinkedList<T>::reset(){  // resets the curr to the head of the list.

    curr = head;

}

template<class T>
void MyLinkedList<T>::next(){  // sets the curr pointer to the next node
    if(curr -> next != nullptr){
        curr = curr -> next;
    }
    
    //std::cout << "Called\n";
}
template<class T>
T MyLinkedList<T>::value(){ // returns the value held in the node that curr is pointing to.
    
    return (curr -> value);
    
}
template<class T>
bool MyLinkedList<T>::atEnd(){ // if curr's next pointer is NULL then curr is pointing to the last node in the list.
 
    return (curr -> next == nullptr);
    
}

template<class T>
void MyLinkedList<T>::remove(){ // Removes a node from the list.
    
    if (head == tail){ // if the list is empty the fuctions exits.
        return;
    }
    if (curr -> prev == nullptr){ // If we remove the head of the list we must move the head pointer to the next position.
        Node<T> *oldHead = head;
        head = head -> next;
        head -> prev = nullptr;
        curr = curr -> next; // we move the curr pointer to the next node.
        
        delete oldHead;  // we then delete the node that head was pointing to.
        
    }else if (curr -> next == nullptr){ // if we delete the tail node then we must reset the tail pointer.
        Node<T> *oldTail = tail;
        tail = tail -> prev;
        tail -> next = nullptr;
        curr = curr -> prev; // we must move the curr pointer.
        
        delete oldTail; // we delete what the tail was pointing to.
    }else{ // If we hit this statement then we are deleting a middle item.

    Node<T> *newCurr = curr;
    
    Node<T> *currPrev = curr -> prev; // we must reset the next and prev pointers at that node.
    Node<T> *currNext = curr -> next;
    
    currNext -> prev = curr -> prev;
    currPrev -> next = curr -> next;
    curr = curr -> next; //  we adjust the curr pointer.
    
    delete newCurr; // we delete the node that curr was pointing to.
        
    }
}

template<class T>
void MyLinkedList<T>::insert(T value){
    
    if(curr == tail){ // if we are at the end of the list we can just call the pushBack function to insert.
        pushBack(value);
    }else{
        Node<T> *curr2;
        curr2 = curr->next;
        Node<T> *insertNode = new Node<T>(value,curr->next,curr); // we must create a new node to store the value and pointers.
        
        curr->next = insertNode;
        curr2->prev = insertNode;
        curr = curr -> next;
        
    
    }
    
}




    



#endif
