//
//  BST.hpp
//  tree
//
//  Created by Travis Hodge on 3/25/16.
//  Copyright © 2016 Travis Hodge. All rights reserved.
//

#ifndef BST_hpp
#define BST_hpp

#include <string>
#include <iostream>
enum Color {RED, BLACK};

// Structure for BST node
template <class T>
struct Node {
    T key;
    Node<T> *left, *right;
    
    Color myColor;
    bool testColor;
    Node<T>(T k, Node<T> *l=nullptr, Node<T> *r=nullptr) {
        key = k;
        left = l;
        right = r;
        myColor = RED;
        testColor = true;
        
    }
};

// BST class template
template <class T>
class BST {
public:
    // Default constructor
    BST();
    
    // Copy constructor
    BST(const BST<T> &otherTree);
    
    // Destructor
    ~BST();
    
    Node<T>* rotateLeft(Node<T> *x);
    Node<T>* rotateRight(Node<T> *x);
    void colorFlip(Node<T> *x);
    Node<T>* moveRedLeft(Node<T> *x);
    Node<T>* moveRedRight(Node<T> *x);
    Node<T>* fixUp(Node<T> *x);
    void rotateLeftTest();
    void colorFlipTest();
    bool isRed(Node<T> *x);
    bool isBlack(Node<T> *x);
    
    // Overloaded assignment operator
    const BST<T> & operator=(const BST<T> &otherTree);
    
    // Inserts a key into the tree
    void insert(T key);
    
    // Returns true if a key is in the tree and false otherwise
    bool contains(T key) const;
    
    // Returns the minimum key in the tree
    // Throws an exception if the tree is empty
    T min() const;
    
    // Removes the miminum key from the tree
    // Throws an exception if the tree is empty
    void removeMin();
    
    // Removes a key from the tree
    void remove(T key);
    
    // Removes all keys from the tree
    void clear();
    
    // Returns true if the tree is empty and false otherwise
    bool isEmpty() const;
    
    // Displays the tree
    void display() const;
    
private:
    // The root of the tree
    Node<T> *root;
    
    
    // Recursively builds a copy of the tree rooted at the given node
    Node<T> *copyFrom(const Node<T> *node);
    
    // Recursively deallocates the tree rooted at the given node
    void deallocateSubtree(Node<T> *node);
    
    // Recursively displays the subtree rooted at the given node
    void displaySubtree(Node<T> *subtree, std::string above, std::string mid, std::string below) const;
    
    // Recursively inserts a key into the subtree rooted at the given node
    Node<T> *insert(Node<T> *node, T key);
    
    // Recursively checks if a key is in the subtree rooted at the given node
    bool contains(Node<T> *node, T key) const;
    
    // Recursively finds the minimum key in the subtree rooted at the given node
    T min(Node<T> *node) const;
    
    // Recursively removes the minimum key in the subtree rooted at the given node
    Node<T> *removeMin(Node<T> *node);
    
    // Recursively deletes a key from the subtree rooted at the given node
    Node<T> *remove(Node<T> *node, T key);
};

// Default constructor
template <class T>
BST<T>::BST() {
        root = nullptr;
    
}

// Copy constructor
template <class T>
BST<T>::BST(const BST<T> &otherTree) {
    root = copyFrom(otherTree.root);
}

// Destructor
template <class T>
BST<T>::~BST() {
    clear();
}

// Overloaded assignment operator
template <class T>
const BST<T> & BST<T>::operator=(const BST<T> &otherTree) {
    clear();
    root = copyFrom(otherTree.root);
    return *this;
}

// Inserts a key into the tree
template <class T>
void BST<T>::insert(T key) {
    root = insert(root, key);
    root -> myColor = BLACK; // sets the root color black.
    root -> testColor = false;
}


template <class T>
Node<T>* BST<T>::rotateLeft(Node<T> *x)
{
    Node<T> *y = x -> right; // creates a node and points it at the nodes right child
    x -> right = y -> left; // sets the input node's right child to the new node's left child
    y -> left = x; // sets the new node's left child to the input node
    y -> myColor = x -> myColor; // transfers the color of the input node to the new node
    y->testColor = x->testColor;
    x -> myColor = RED; // sets the input node's color to red
    x -> testColor = true;
    
    return y; // returns the new pointer
    
}

template <class T>
Node<T>* BST<T>:: rotateRight(Node<T> *x)
{
   
    
    Node<T> *y = x -> left;
    x -> left = y -> right;
    y -> right = x;
    y -> myColor = x -> myColor;
    y -> testColor = x->testColor;
    x -> myColor = RED;

    x -> testColor = true;
    return y;

}

template <class T>
void BST<T>::colorFlip(Node<T> *x)
{
    

    
        if (x -> myColor == RED){ // takes the input node and sets to the opposite color
            x -> myColor = BLACK;
          //  x -> testColor = false;
        }else{
            x -> myColor = RED;
            
        }
  
        if (isRed(x -> left) ){ // resets the color of the left child
            x -> left -> myColor = BLACK;
            
        }else{
            x -> left -> myColor = RED;
        }
    
  
    
        if (x -> right -> myColor == RED){ // resets the color of the right child
            x -> right -> myColor = BLACK;
        }else{
            
            x -> right -> myColor = RED;
        }
    if (x == root) { // if the node is the root, set the color to black
        x -> myColor = BLACK;
    }
    
}

template <class T>
bool BST<T>::isRed(Node<T> *x)
{
    if(x == nullptr){
        return false;
    }
    if (x->myColor == RED) {
        return true ;

    }else
        return false;
    
}

template <class T>
bool BST<T>::isBlack(Node<T> *x)
{
    if (x == nullptr) {
        return false;
    }
    if (x->myColor == BLACK) {
        return true;
    }else
        return false;

}

template <class T>
Node<T>* BST<T>::moveRedLeft(Node<T> *x)
{
    
    colorFlip(x); // first flips the color
    if (isRed(x -> right -> left) ) {
        x -> right = rotateRight(x -> right); // rotates the right child right
        x = rotateLeft(x); // rotates left
        colorFlip(x); // flips the color of the nodes
    }
    return x;

}

template <class T>
Node<T>* BST<T>::moveRedRight(Node<T> *x)
{
    colorFlip(x);
    
    
    if (isRed(x -> left -> left) ) {
        x = rotateRight(x);
        colorFlip(x);
    }

    return x;

}

template <class T>
Node<T>* BST<T>::fixUp(Node<T> *x)
{
    

    
    

    if ( (isRed(x -> right) ))
        x = rotateLeft(x);
    
    
    
    
    
    if ( (isRed(x -> left)  && isRed(x -> left -> left) ))
        x = rotateRight(x);
    
    
    
    
     if ( isRed(x -> left)  && isRed(x -> right) )
         colorFlip(x);
 
    return x;
    
}


// Returns true if a key is in the tree and false otherwise
template <class T>
bool BST<T>::contains(T key) const {
    return contains(root, key);
}

// Returns the minimum key in the tree
// Throws an exception if the tree is empty
template <class T>
T BST<T>::min() const {
    if(isEmpty()) {
        std::string except = "Error: tree is empty";
        throw except;
    }
    else
        return min(root);
}

// Removes the miminum key from the tree
// Throws an exception if the tree is empty
template <class T>
void BST<T>::removeMin() {
    if(isEmpty()) {
        std::string except = "Error: tree is empty";
        throw except;
    }
    else
        root = removeMin(root);
}

// Removes a key from the tree
template <class T>
void BST<T>::remove(T key) {
    root = remove(root, key);
}


// Removes all keys from the tree
template <class T>
void BST<T>::clear() {
    deallocateSubtree(root);
    root = nullptr;
}

// Returns true if the tree is empty and false otherwise
template <class T>
bool BST<T>::isEmpty() const {
    return root == nullptr;
}

// Displays the tree
template <class T>
void BST<T>::display() const {
    if(isEmpty())
        std::cout << "(empty)" << std::endl;
    else
        displaySubtree(root, "", "", "");
}

// Recursively builds a copy of the tree rooted at the given node
template <class T>
Node<T> *BST<T>::copyFrom(const Node<T> *node) {
    if(node == nullptr)
        return nullptr;
    else
        return new Node<T>(node->key, copyFrom(node->left), copyFrom(node->right));
}

// Recursively deallocates the tree rooted at the given node
template <class T>
void BST<T>::deallocateSubtree(Node<T> *node) {
    if(node != nullptr) {
        deallocateSubtree(node->left);
        deallocateSubtree(node->right);
        delete node;
    }
}

// Recursively displays the subtree rooted at the given node
template <class T>
void BST<T>::displaySubtree(Node<T> *subtree, std::string above,
                            std::string mid, std::string below) const {
    // display the node's right subtree
    if(subtree->right != nullptr)
        displaySubtree(subtree->right, above + "      ", above + "  /---", above + "  |   ");
    
    // display the contents of the node
    std::string test1;
    if (subtree->myColor == RED && subtree != root){
         test1 = "R";
        
    }
    else{
        
         test1 = "B";
    }
    std::cout << mid << subtree->key  << test1 << std::endl;
    
    // display the node's left subtree
    if(subtree->left != nullptr)
        displaySubtree(subtree->left, below + "  |   ", below + "  \\---", below + "      ");
}

// Recursively inserts a key into the subtree rooted at the given node
template <class T>
Node<T> *BST<T>::insert(Node<T> *node, T key) {
    
    
    if(node == nullptr)
        return new Node<T>(key);
    if(key < node->key){
        
        node->left = insert(node->left, key);
        
    }
    else if(key > node->key)
        node->right = insert(node->right, key);
    
   
   
    return fixUp(node);
}

// Recursively checks if a key is in the subtree rooted at the given node
template <class T>
bool BST<T>::contains(Node<T> *node, T key) const {
    if(node == nullptr)
        return false;
    else if(key == node->key)
        return true;
    else if(key < node->key)
        return contains(node->left, key);
    else
        return contains(node->right, key);
}

// Recursively finds the minimum key in the subtree rooted at the given node
template <class T>
T BST<T>::min(Node<T> *node) const {
    if(node->left == nullptr)
        return node->key;
    else
        return min(node->left);
}

// Recursively removes the minimum key in the subtree rooted at the given node
template <class T>
Node<T> *BST<T>::removeMin(Node<T> *node) {
   
   
    if(node->left == nullptr) {
            delete node;
            return nullptr;
    }if (isBlack(node -> left) && !isRed(node -> left -> left) ) {
        node = moveRedLeft(node);
    }
    
    
    

    node->left = removeMin(node->left);
    
    node = fixUp(node);
    
    return node;
    
    
}

// Recursively deletes a key from the subtree rooted at the given node
template <class T>
Node<T> *BST<T>::remove(Node<T> *node, T key) {
    
    
    if(node == nullptr) // Case 1: key was not found
        return nullptr;
    
    if(key < node->key) {// Case 2: key might be in left subtree
        
    
        if (isBlack(node->left) && !isRed(node -> left -> left) ) {
            node = moveRedLeft(node);
        }
        node -> left = remove(node->left, key);
        
    }else{
        
        if (isRed(node->left)) {
            node = rotateRight(node);
        }if(key == node->key && node->right == nullptr){
            delete node;
            return nullptr;
        
        } if (isBlack(node->right) && !isRed(node->right->left)){
            node = moveRedRight(node);
        } if (key > node->key){
            node->right = remove(node->right, key);
        } if(key == node->key && node->right != nullptr && node->left != nullptr){
            node->key = min(node->right);
            node->right = removeMin(node->right);
        }
        
        
        
    }
    
    node = fixUp(node);
    return node;

}

    



#endif /* BST_hpp */
