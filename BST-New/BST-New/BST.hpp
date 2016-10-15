//
//  BST.hpp
//  BST-New
//
//  Created by Travis Hodge on 2/22/16.
//  Copyright © 2016 Travis Hodge. All rights reserved.
//

#ifndef BST_hpp
#define BST_hpp

#include <queue>

template <class T>
struct BSTNode{
    
    T value;
    BSTNode<T> *left, *right;
    
    BSTNode(v, l = nullptr, r = nullptr){
        value = v;
        left = l;
        right = r;
        
    }
    
};

template <class T>
class BST{
    
public:
    
    BST(){
        root = nullptr;
    }
    
    T *search(const T &item) const{
        
        BSTNode<T> *curr = root;
        while(curr != nullptr){
            if(item == curr->value){
                return &curr->value;
            }else if(item < curr->value){
                curr = curr->left;
            }else{
                curr = curr->right;
            }
            
            return nullptr;
            
        }
        
        //Start Function
        void insert(const &item){
            BSTNode<T> *curr = root, *prev = nullptr;
            // Trying to find a location for the item
            while (curr != nullptr){
                prev = curr;
                if (item < curr->value) {
                    curr = curr->left;
                }
                else {
                    curr = curr->right;
                }
            }
            // inserting the item
            if (root == nullptr) {
                root = new BSTNode<T>(item);
            }
            else if (item < prev->value) {
                prev->left = new BSTNode<T>(item);
            }
            else {
                prev->right = new BSTNode<T>(item);
            }
        
        }
        //End Function
        
        
        //Start Function
        void breadthFirst(){
        
            queue<BSTNode<T> *> q;
            
            BSTNode<T> *curr = root;
            
            if(curr != nullptr){
                q.push(curr)
                
                while(!q.empty()){
                
                    curr = q.pop();
                    visit(curr);
                    
                    if(curr->left != nullptr){
                        q.push(curr->left);
                    }
                    
                    if (curr->right != nullptr) {
                        q.push(curr->right);
                    }
                    
                
                }
            }
        
        }
       // End Function
        
    }
    
private:
    BSTNode<T> *root;
    
};



#endif /* BST_hpp */
