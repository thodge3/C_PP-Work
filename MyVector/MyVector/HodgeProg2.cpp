//
//  main.cpp
//  MyVector
//
//  Created by Travis Hodge on 1/30/16.
//  Copyright © 2016 Travis Hodge. All rights reserved.
//

#include <iostream>
#include <string>
#include "MyVector.hpp"
using namespace std;

int main() {

    int numberItems,currentItem,j;
    vectorClass<int> vectorNew; // Instance of a MyVector Object
    vectorClass<int> vtest; // Instance of a MyVector Object.
    

        
    
                
    
                
                cout << "Please enter the number of items you would like to add \n";
                cin >> numberItems;
                
    j = 0;
    
    do{
                    cout << "Please enter the item. \n";
                    cin >> currentItem;             // A loop to push an item to the back of a vector until the counter matches the number given.
                    vectorNew.push_back(currentItem);
                    j++;
        
    }while(j < numberItems);
    
    cout << "This is the output of the original vector.\n";
    
                for (int i = 0; i < vectorNew.getSize(); i++) {
                    cout << i+1 << " : " << vectorNew.vecArr[i] << "\n"; // accesses the vecArr member through the instance of vectorNew.
                }
                
             vectorClass<int> test(vectorNew); // Calls the copy constructor accepting a MyVector Object.
                cout << "This is using the Copy Constructor.\n";
    
                for (int i = 0; i < test.getSize(); i++) {
                    cout << i+1 << " : " << test.vecArr[i] << "*" <<"\n";
                }
                cout << "This is using the Overloaded Assignment Operator.\n";
    
            vtest = vectorNew; // assignment operator overloaded 
    
                for (int i = 0; i < vtest.getSize(); i++) {
                    cout << i+1 << " : " << vtest.vecArr[i] << "**" <<"\n";
                }
    
    
                cout << "Number of Items added : " << vectorNew.getSize()<<"\n";
                cout << "Number of Assignments Made : " << vectorNew.getAssignments() << "\n";
                cout << "Ratio of Assignments Made per Items added : " << double(vectorNew.getAssignments()) / double(vectorNew.getSize()) << "\n";
                
    
  
     return 0;
}
