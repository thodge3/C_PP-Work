//
//  MyStack.hpp
//  MyStack
//
//  Created by Travis Hodge on 2/16/16.
//  Copyright © 2016 Travis Hodge. All rights reserved.
//

#ifndef __MyStack_HPP__
#define __MyStack_HPP__

#include <string>

template <class T>
class MyStack{

    private :
    T *ArrElem; // pointer for creating an array
    int mCap; // capacity for the array, to be specified later
    int top; // top of the stack
    
    public :
    
    MyStack(int Cap); // one argument constructor
    void pop(); // used to pop the top item off of the stack
    void push(T elem); // pushes an element to the top of the stack
    void clear(); // clears the stack
    T Top(); // returns the array value at the top of the stack
    bool isEmpty(); // returns true if the array is empty
    bool isFull(); // returns true if the array is full
    ~MyStack(); // destructor for the array

    //Overloaded Assignment Operator
    const MyStack &operator=(const MyStack<T> &otherStack) {
        delete [] ArrElem;
        ArrElem = new T[otherStack.mCap];
        mCap = otherStack.mCap;
        top = otherStack.top;
        
        for (int i = 0; i < mCap ; i++){
            
            ArrElem[i] = otherStack.ArrElem[i];
        
        }
        
        return *this;
    }
    
    // Copy Constructor 
    MyStack(const MyStack<T> &otherStack) {
        
        delete [] ArrElem;
        mCap = otherStack.mCap;
        top = otherStack.top;
        
        for(int i = 0 ; i < otherStack.mCap ; i++){
        
            ArrElem[i] = otherStack.ArrElem[i];
        
        }
        
    }


    
    
};

// One argument constructor for the stack class. Allows for input of the capacity
template <class T>
MyStack<T>::MyStack(int Cap){
    
    mCap = Cap; // sets the member capacity to the input capacity
    ArrElem = new T[Cap]; // dynamically allocates space for the array
    top = 0; // sets the top counter to the beginning of the stack


}


// destructor for the stack array
template <class T>
MyStack<T>::~MyStack<T>(){
    delete [] ArrElem;
}

// Pops the top value off of the stack
template <class T>
void MyStack<T>::pop(){
    
    if (top == 0){ // throws an exception if the user tries to pop an empty stack
        std::string  exception = "ERROR: (description  of the  error)";
        throw exception;
    }else
        top--; // decrements the top counter, allowing the stack to be overwritten

}

// Pushes an element to the top of the stack
template <class T>
void MyStack<T>::push(T elem){

    if(top == mCap){ // throws an exception if the user tries to push a full stack.
        std::string  exception = "ERROR: (description  of the  error)";
        throw exception;
    }
    ArrElem[top] = elem; // sets the input value to the top of the stack
    top++; // increments the top counter for future use.

}

// Clears the stack and resets the top counter back to zero
template <class T>
void MyStack<T>::clear(){
 
    top = 0; // resets the top counter back to zero, allowing for the stack to be overwritten

}

// returns the value in the array at the top of the stack
template <class T>
T MyStack<T>::Top(){

    if (top == 0){ // Throws an exception if the user tries to return the top of an empty array
    std::string  exception = "ERROR: (description  of the  error)";
        throw exception;
    }
    return ArrElem[top-1]; // Because top is always the empty spot above the stack, we want to return
                           // the value just below top

}

// function returns true if the stack is empty
template <class T>
bool MyStack<T>::isEmpty(){

    return (top == 0); // if top equals zero then the stack must be empty.

}

// function returns true if the stack is full
template <class T>
bool MyStack<T>::isFull(){

    return (top == mCap); // if the top equals the capacity then the stack is full

}
#endif
