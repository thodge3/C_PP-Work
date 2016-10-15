//
//  main.cpp
//  tree
//
//  Created by Travis Hodge on 3/25/16.
//  Copyright © 2016 Travis Hodge. All rights reserved.
//

#include <iostream>
#include "LLRBT.hpp"

using namespace std;

int main() {
   
    BST <int> check;
    /*
    check.insert(18);
    check.insert(66);
    check.insert(4);
    check.insert(5);
    check.insert(40);
     */
    
    for (int i = 0; i < 50; i = i + 6) {
        check.insert(i);
    }
                                            // For loops to populate the tree
    for (int i = 0; i < 50; i = i + 3) {
        check.insert(i);
    }
    
    
    
    check.display();
    
    cout << endl;
    cout << endl;
    
    for (int i = 0; i < 50; i++) {
        if (i%2 == 0) {
            //check.remove(i);
        }
    }
    
   
    check.removeMin();
    check.display();
    check.removeMin();
    check.display();
    check.remove(18);
    check.display();
    check.remove(30);
    check.display();
    check.removeMin();
    check.display();
    check.insert(40);
    check.display();
    check.clear();
    check.display();
    
    return 0;

}
