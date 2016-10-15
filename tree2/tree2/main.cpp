//
//  main.cpp
//  tree2
//
//  Created by Travis Hodge on 3/25/16.
//  Copyright © 2016 Travis Hodge. All rights reserved.
//

#include <iostream>
#include "LLRBT.hpp"

int main() {
    
    BST<int> check;
    
    check.insert(10);
    check.insert(15);
    check.insert(13);
    check.insert(4);
    check.insert(20);
    
    check.display();

}
