//
//  HodgeProg3.cpp
//  MyLinkedList
//
//  Created by Travis Hodge on 2/7/16.
//  Copyright © 2016 Travis Hodge. All rights reserved.
//

#include <iostream>
#include "MyLinkedList.hpp"
using namespace std;

int main() {
    
    
    MyLinkedList<int> List; // creating the test list.
    MyLinkedList<int> test1; // creating a list to test the copy constructor.
    
    
    
    int listSize = 10; // set the initial list size.
    
    for (int i = 0 ; i < listSize ; i++){
        List.pushBack(i+1); // pushing back values to the first list.
    }
    
    cout << "Original List : \n";
    for (int i = 0 ; i < listSize ; i++ ){
    
        cout << List.popFront() << "  "; // testing the popFront function of the list class.
    }
    
    cout << "\n\nList with a number inserted in the 5th position : \n";
    for (int i = 0 ; i < listSize ; i++){
        List.pushBack(i+1); // creating a new list.
    }
    List.reset();  // testing the next fuction. Resets the curr pointer to the head of the list.
    List.next(); // advances the curr pointer multiple times.
    List.next();
    List.next();
    List.insert(111); // inserts the value "111" after the node that curr is pointing to.
    
    for (int i = 0 ; i < listSize+1 ; i++ ){
        
        cout << List.popFront() << "  "; // pops the list back to view the contents.
    }
    cout << "\ncurr's current value : " << List.value(); // displays the value that curr is pointing to.
    List.clear(); // clears the entire list.
    
    cout << "\n\nList with the new value inserted and the last element removed : \n";
    
    for (int i = 0 ; i < listSize ; i++){
        List.pushBack(i+1); // creates a new list.
    }
    List.reset(); // resets the curr pointer.
    List.next(); // advances the curr pointer.
    List.next();
    List.next();
    List.insert(111); // inserts the values "111" again.
    List.next();
    List.next();
    List.next();
    List.next();
    List.next();
    List.next();
    
    
    List.remove(); // removes the node that curr is pointing to from the list.
    


    for (int i = 0 ; i < listSize ; i++ ){
        
        cout << List.popFront() << "  "; // pops the list again.
    }
     bool check = List.atEnd(); // tests to see if curr is pointing to the end of the list.
    
    cout << "\ncurr's current value is : " << List.value() << "\n\n";
    cout << "Are we at the end of the list? 1 = true , 0 = false.";
    cout << "\n" << check << "\n";


    //cout << "\n";
    
    for (int i = 0 ; i < listSize ; i++){
        List.pushBack(i+1); // creates a new list again.
    }
    
    MyLinkedList<int> test(List); // uses the contents of List to make a new list called "test". This function tests
                                  // the copy constructor.
    
    cout << "\n\nList created using the copy constructor : \n";
    for (int i = 0 ; i < listSize ; i++ ){
        
        cout << test.popFront() << "*  "; // pops the copied list to ensure it is working.
    }
    cout << "\n";
    List.clear(); // clears the list again.
    if (List.isEmpty()) cout << "\nThe list is now empty after using the clear function.\n";

    
    return 0;
}
