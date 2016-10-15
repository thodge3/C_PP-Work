//
//  MyVector.hpp
//  MyVector
//
//  Created by Travis Hodge on 1/30/16.
//  Copyright © 2016 Travis Hodge. All rights reserved.
//

#ifndef MyVector_hpp
#define MyVector_hpp
#include <stdio.h>
#include <string>


template <class T>
class vectorClass{
    
    
    
    public:
    
    
    
    int vectorCapacity;
    int vectorCurSize;
    int assignmentCount;
    T *vecArr;

    
    vectorClass(); // default constructor prototype.
    vectorClass(int); //  constructor prototype to accept a size of a MyVector Object.
    ~vectorClass(); // destructor
    vectorClass(const vectorClass&); // copy constructor accepting a MyVector object to copy information from.
    int getSize();
    int getCapacity();
    int getAssignments();
    void push_back(T); // prototype for push back function.
    void reserve(int);
    
    
  
    vectorClass<T> &operator=(const vectorClass<T> &obj){  // Overloaded Assignment Operator.
        
        
        this->vecArr = new T[obj.vectorCurSize]; // Class defined vecArr is dynamically allocated using the size of the input object.
        vectorCurSize = obj.vectorCurSize; // resets the size and capacity of the vector.
        vectorCapacity = obj.vectorCapacity;
        for (int i = 0; i < obj.vectorCurSize; i++) {
            this->vecArr[i] = obj.vecArr[i]; // allocates all information to the new vector using the information from the input object.
        }
        
        return *this; // returns the vector.
        delete [] obj.vecArr;
        
    
    }
    
    
    
    
};

template <class T>
vectorClass<T>::vectorClass(){

    vecArr = new T[10];
    vectorCapacity = 10; // default constructor setting member values.
    vectorCurSize = 0;
    assignmentCount = 0;
    
    
}

template <class T>
vectorClass<T>::vectorClass(int newSize){
    
    if (newSize < 10) {
        newSize = 10; // checks for the size of the input size.
    }
    
    vecArr = new T [newSize];
    vectorCapacity = newSize; // allocates space based on the vector size.
    vectorCurSize = 0;
    assignmentCount = 0;
    
}

template <class T>
vectorClass<T>::vectorClass(const vectorClass &obj){ // implementation of the copy constructor.
    
    
    this->vecArr = new T[obj.vectorCurSize]; // creates a vector using the size of the input vector.
    for (int i = 0; i < obj.vectorCurSize; i++) {
        this->vecArr[i] = obj.vecArr[i];
    }
   
    vectorCurSize = obj.vectorCurSize;
    vectorCapacity = obj.vectorCapacity;
  
    
}


template <class T>
int vectorClass<T>::getSize(){
    return vectorCurSize;
}
template <class T>
int vectorClass<T>::getCapacity(){
    return vectorCapacity;
}
template <class T>
int vectorClass<T>::getAssignments(){
    return assignmentCount;
}

template <class T>
vectorClass<T>::~vectorClass(){

    delete [] vecArr; // implementation of the destructor.

}
 
template <class T>
void vectorClass<T>::reserve(int nextSize){ // reserving space for a new vector of doubled size.
   
    T *newVec;  // create a new T type pointer named newVec.
    
    if (nextSize > getCapacity()) {
       newVec = new T[nextSize]; // if the size of the vector is larger than the capacity of the vector then we must make space.
        
        for (int i = 0; i < vectorCapacity; i++) {
            newVec[i] = vecArr[i];   // moves every element from the old vector to the new vector.
            assignmentCount++; // adds a new count every time.
           // cout <<i;
        }
        delete [] vecArr; // deletes the old vector.
        
      
        vecArr = new T[nextSize]; // re-allocates the vecArr member using the size of the new vector.
        for (int i = 0; i < vectorCapacity; i++) {
            vecArr[i] = newVec[i]; // moves every element from the new vector back to the member vector.
            assignmentCount++;
        }
        vectorCapacity = nextSize; // redefines the capacity of the vector.
    }
    delete [] newVec; // deletes the temporary vector.
    
    
}

template <class T>
void vectorClass<T>::push_back(T element){
    
    if (vectorCurSize < vectorCapacity) { // if the size of the vector is within the capacity limits, then add it to the vector.
     
        vecArr[vectorCurSize] = element; // adds the element to the end of the vector.
        vectorCurSize++; // increases size of the vector by one.
        assignmentCount++; // increases number of assignments by one.

    }else{
        reserve(2*vectorCapacity); // the size of the vector exceeds the capacity, then we must allocate more space.
        vecArr[vectorCurSize] = element; // adds the element to the back of the vector with doubled size.
        vectorCurSize++; // vector is increased by one.
        assignmentCount++; // assignments increased by one.
    }
    
}



#endif /* MyVector_hpp */
