//
//  main.cpp
//  MyRecursion
//
//  Created by Travis Hodge on 2/22/16.
//  Copyright © 2016 Travis Hodge. All rights reserved.
//

#include <iostream>
#include "Maze.hpp"
using namespace std;

bool pathToTreasure(Maze &mMaze, Position pos){

    Position current = pos; // keeps track of the current position
    mMaze.visit(pos); // visits that position
    
    bool test1 = false; // boolean used to allow the function to backtrack
    
    if(mMaze.treasure(pos)){
        mMaze.mark(pos); // if the position is at the treasure we return true
        return true;
    }
    if(mMaze.north(pos) && !mMaze.visited(getNorth(pos)) && !test1 ){
        pos = getNorth(pos); // if we can move north, we update the position.
        cout << "North\n";
        test1 = pathToTreasure(mMaze, pos); // resets the boolean to what the function returns
        if (!test1){
            pos = current; // if the boolean is false we also update position using current
        }
        
        //pathToTreasure(mMaze, pos);
    } if(mMaze.east(pos) && !mMaze.visited(getEast(pos)) && !test1 ){
        pos = getEast(pos); // move east if we can
        cout << "East\n";
        test1 = pathToTreasure(mMaze, pos);
        if (!test1){
            pos = current;
        }
        
        
    } if (mMaze.south(pos) && !mMaze.visited(getSouth(pos)) && !test1 ){
        pos = getSouth(pos); // move south if possible
        cout << "West\n";
        test1 = pathToTreasure(mMaze, pos);
        if (!test1){
            pos = current;
        }
        
        
    } if (mMaze.west(pos) && !mMaze.visited(getWest(pos)) && !test1 ){
        pos = getWest(pos); // move south if possible
        cout << "South\n";
        test1 = pathToTreasure(mMaze, pos);
        if (!test1){
            pos = current;
        }
        
    }if (test1) {
        mMaze.mark(pos); // if the boolean returns true we have found a path to the treasure, and we mark it
        return true;
    }else{
       // mMaze.mark(pos);
        return false; // if we can't find a path to the treasure we return false.
    }
    
    
}

int main() {
    
    
    Maze myMaze("maze.txt");
    
    Position startPosition;
    Position currentPosition;
    
    startPosition = myMaze.startPos();
    currentPosition = myMaze.startPos();
    
    bool test;
    
    test = pathToTreasure(myMaze, currentPosition);
   
    if (test){ // if a path to the treasure is possible, test is set to true and we draw the maze
        myMaze.draw();
    }else{ // if test is false, a path was not available
        cout << "No path to treasure was found.\n";
    }
    
    
    return 0;
}

