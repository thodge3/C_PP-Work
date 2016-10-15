//
//  main.cpp
//  MyStack
//
//  Created by Travis Hodge on 2/16/16.
//  Copyright © 2016 Travis Hodge. All rights reserved.
//

#include <iostream>
#include "MyStack.hpp"
#include "Maze.hpp"


using namespace std;

int main() {
    
    // must create an object of the maze class
    Maze mMaze("maze.txt");
    
    // create a MyStack object using Position type. Of size 100
    MyStack<Position> test(100);
    
    
    // Creates a Position type variable and sets its position to starting position
    Position starting = mMaze.startPos();
    
    // Creates a second Position type variable and also starts it at the starting position
    Position current = mMaze.startPos();
    
    Position print;
    
    string message = "No work";
    
    // pushes the starting position to the top of the stack
    test.push(starting);

    // loop to run until the stack is empty or exited by finding the treasure
    while(!test.isEmpty()){
    
        // calls the visit function with current position input
        mMaze.visit(current);
        
        // if the current position is also where the treasure is we must exit the while loop
        if (mMaze.treasure(current) ){
            break;
        }
        
        // if it is possible to move north, we do
        if(mMaze.north(current) && !mMaze.visited(getNorth(current))){
            
            current = getNorth(current); // updates the current position to one position north
            try {
                test.push(current); // pushes the new position to the top of the stack
            } catch (string message) {
                cout << message << "\n";
            }
            
            //cout << "north\n";
        
        }
        
        else if (mMaze.east(current) && !mMaze.visited(getEast(current))) {
            
            current = getEast(current); // updates the current position to one position east
            try {
                 test.push(current); // pushes the new position to the top of the stack
            } catch (string message) {
                cout << message << "\n";
            }
           
           // cout << "east\n";
            
        }
        
        else if (mMaze.south(current) && !mMaze.visited(getSouth(current))){
        
            current = getSouth(current); // updates the currrent position to one position south
            try {
                test.push(current); // pushes the new position to the top of the stack
            } catch (string message) {
                cout << message << "\n";
            }
            
            //cout << "south\n";
            
        
        }
        
        else if(mMaze.west(current) && !mMaze.visited(getWest(current))){
            
            current = getWest(current); // updates the currrent position to one position west
            try {
                test.push(current); // pushes the new position to the top of the stack
            } catch (string message) {
                cout << message << "\n";
            }
            
            //cout << "west\n";
            
          // if it is not possible to move, we pop the top position and backtrack
        }else{
            try {
                test.pop();
            } catch (string message) {
                cout << message << "\n";
            }
            
            //test.push(current);
            try {
                current = test.Top();
            } catch (string message) {
               cout << message << "\n";
            }
            
            
        
        }
        
        }
    
    //  if the stack is empty then we could not find a path to the treasure
    bool stackEmpty = test.isEmpty();
    
    if( stackEmpty == true){
    
        cout << "There is no path to the treasure.\n";
        
    }else{
     
        // while the stack is not empty, we want to mark each position we were at.
        while (!test.isEmpty()){
            try {
                
                mMaze.mark(test.Top()); // marks the top position
                print = test.Top();
                cout << print.row << "  " << print.col << "\n";
            } catch (string message) {
                cout << message << "\n";
            }
            
            try {
                test.pop(); // pops of the top position and continues through the stack
            } catch (string message) {
                cout << message << "\n";
            }
            
        
        
        }
        
        
    }
    
    
    
    
    
    
    
    
    mMaze.draw(); // draws the entire maze and marks
    
    
    
    
    return 0;
}