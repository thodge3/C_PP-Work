//
//  graphtest.cpp
//  Graph
//
//  Created by Travis Hodge on 4/5/16.
//  Copyright © 2016 Travis Hodge. All rights reserved.
//

#include <stdio.h>
#include "graph.h"
#include <iostream>
#include <string>
#include <iomanip>

Graph::Graph(int numVertices){ // constructor accepting the number of vertices as input.

    mNumVertices = numVertices; // sets the input number to the member number of vertices.
    
    int numRows = mNumVertices; // these variables are used to create the adjacency matrix
    int numCols = mNumVertices;

    mMatrix = new int *[numRows]; // declares a 2x2 adjacency matrix representing a graph of cities.
    for(int row = 0; row < numRows; row++)
        mMatrix[row] = new int [numCols];
    
    
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            
            if (i == j) {
                mMatrix[i][j] = 0; // sets the diagonal of the matrix to zero, which is the distance of a city to itself.
            }else
                mMatrix[i][j] = MAX_WEIGHT; // sets all other elements of the matrix equal to infinity.
            
        }
    }
}

Graph::~Graph(){

    deallocate(); // deletes the dynamically allocated matrix.

}

Graph::Graph(const Graph &testGraph){ // copy constructor.

    mMatrix = new int *[testGraph.mNumVertices]; // allocates a new dynamic 2x2 matrix using the input graph's size.
    for(int row = 0; row < testGraph.mNumVertices; row++)
        mMatrix[row] = new int [testGraph.mNumVertices];
    
    copyFrom(testGraph); // copies each element from the input matrix to the member matrix.
    
    mNumVertices = testGraph.mNumVertices; // sets the member size variable using the input size.


}

bool Graph::addEdge(int sourceVertex, int targetVertex, int weight){ // adds an edge to the graph using an input source and target vertex.

    if (sourceVertex < mNumVertices && targetVertex < mNumVertices && weight > 0) { // requires a positive weight and possible city index.
        mMatrix[sourceVertex][targetVertex] = weight; // sets the proper element of the matrix to the weight provided.
        return true; // returns true for the return type.
    }else
        return false; // if the addition fails.
}

void Graph::displayMatrix(){
    int w = 7;
    std::cout << std::setw(w+5) << "Atla" << std::setw(w) << "Birm" << std::setw(w) << "Chrt" << std::setw(w) << "Chat"
              << std::setw(w) << "Char" <<  std::setw(w) << "Cinc" <<  std::setw(w) << "Colm" << std::setw(w) << "Indi"
              << std::setw(w) << "Knox" << std::setw(w) << "Lexi" << std::setw(w) << "Loui" <<  std::setw(w) << "Memp"
              << std::setw(w) << "Nash" << std::setw(w) << "StLo" <<std::endl << std::endl;

    std::cout << std::setw(12) << "----" << std::setw(7) << "----" << std::setw(7) << "----" << std::setw(7) << "----"
              << std::setw(7) << "----" <<  std::setw(7) << "----" <<  std::setw(7) << "----" << std::setw(7) << "----"
              << std::setw(7) << "----" << std::setw(7) << "----" << std::setw(7) << "----" <<  std::setw(7) << "----"
              << std::setw(7) << "----" << std::setw(7) << "----" <<std::endl << std::endl;

    for (int i = 0; i < mNumVertices; i++) {
        std::cout << cityAbvArray[i] << " |";
        for (int j = 0; j < mNumVertices; j++) {
            
            std::cout << std::setw(6) << mMatrix[i][j] << " "; // displays each element of the matrix.
        }
        std::cout << std::endl << std::endl;
    }
}

void Graph::shortestPaths(int sourceVertex, int currDist [], int predecessor [] ){

    bool *visited = new bool [mNumVertices]; // creates a dynamic array of bools to maintain a list of visited vertices.
    
    currDist[sourceVertex] = 0; // initializes the source vertex to zero in the distance array.
    predecessor[sourceVertex] = 0; // sets the source predecessor index to zero.
    visited[sourceVertex] = false; // initializes the source vertex as false to kickstart the process.
    int visitCounter = mNumVertices; // uses a visited counter to determine if every vertex has been visited.
    
    for (int i = 0; i < mNumVertices; i++) {
        if (i != sourceVertex) { // sets each element that isn't the source to infinity in the distance array.
            currDist[i] = MAX_WEIGHT;
            predecessor[i] = 0; // sets the entire predecessor array to zero.
        }
    }
    for (int i = 0 ; i < mNumVertices; i++) {
        if (i != sourceVertex) {
            visited[i] = false; // sets the entire visited array to false. Signifying that no vertex has been visited yet.
        }
    }
    
    while (visitCounter != 0) { // runs until all vertices have been visited.
        int min = MAX_WEIGHT; // setes the minimum value equal to infinity.
        int minCount = 0; // sets the index of the min value to the first spot.
        for (int i = 0; i < mNumVertices; i++) {
            if (currDist[i] < min && visited[i] == false) { // runs only if the weight in the distance array is smaller than the min and
                                                            // that vertex has not been visited yet.
                min = currDist[i]; // if a smaller vertex is found, set the minimum value equal to that value.
                minCount = i; // set the index of that vertex.
            }
        }
        visited[minCount] = true; // visit that vertex.
        visitCounter--; // decrement the visit counter. Signifying that a vertex has been visited.
        
        
        for (int i = 0; i < mNumVertices; i++) {
            if ( mMatrix[minCount][i] != MAX_WEIGHT && visited[i] == false) { // runs only if the test vertex has adjacent vertices
                                                                              // that haven't been visited.
                if (currDist[i] > currDist[minCount] + mMatrix[minCount][i]) { // runs if the min distance is smaller than other edges.
                    currDist[i] = currDist[minCount] + mMatrix[minCount][i]; // sets that element in the distance array.
                    predecessor[i] = minCount; // sets that tested index to the predecessor array.
                }
            }
        }
        
    }

}

void Graph::deallocate(){

    for (int row = 0; row < mNumVertices; row++)
        delete [] mMatrix[row]; // deletes the dynamically allocated matrix
    delete [] mMatrix;


}

void Graph::copyFrom(const Graph &testHere){ // accepts a graph object as input to copy data from.

    for (int i = 0 ; i < testHere.mNumVertices; i++) {
        for (int j = 0; j < testHere.mNumVertices; j++) {
            mMatrix[i][j] = testHere.mMatrix[i][j]; // sets each member matrix element to that of the input matrix elements.
        }
    }
}



void Graph::displayRoute(std::string cityAr [], int prede [], int sourceVertex, int target){
      
    
        if (target == sourceVertex) {
            std::cout << cityAr[target];
            
            return;
        }
        if (prede[target] == 0){
            std::cout << cityAr[sourceVertex] << "-->" << cityAr[target];
            return;
        }else
            displayRoute(cityAr, prede, sourceVertex, prede[target]); // recursively calls the route function to display the route to
                                                                      // a target city.
    
    std::cout << "-->" << cityAr[target];


}

