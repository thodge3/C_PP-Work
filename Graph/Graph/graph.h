//
//  graph.hpp
//  Graph
//
//  Created by Travis Hodge on 4/4/16.
//  Copyright © 2016 Travis Hodge. All rights reserved.
//

#ifndef __Program7__Graph__
#define __Program7__Graph__

#include <iostream>
#include <iomanip>

// The Graph class represents a weighted graph using an adjacency matrix
class Graph {
    
public:
    
    std::string cityAbvArray [14] = {"Atla","Birm","Chrt","Chat","Char","Cinc","Colm",
        "Indi","Knox","Lexi","Loui","Memp","Nash","StLo"};

    
    // Constructor
    Graph( int numVertices );
    
    // Copy Constructor
    Graph( const Graph &);
    
    // Destructor
    ~Graph( );
    
    // Overloaded Assignment Operator
    const Graph & operator=(const Graph &testHere){
        
        deallocate();
        mMatrix = new int *[testHere.mNumVertices];
        for(int row = 0; row < testHere.mNumVertices; row++)
            mMatrix[row] = new int [testHere.mNumVertices];
        mNumVertices = testHere.mNumVertices;
        
        copyFrom(testHere);
        
        return *this;
        delete [] testHere.mMatrix;

        
    }
    
    // Adds an edge to the graph
    // Returns false if vertices are out of range or weight is negative
    bool addEdge( int sourceVertex, int targetVertex, int weight );
    
    // Computes the shortest paths from source_vertex to all other vertices
    // using Dijkstra's shortest path algorithm
    // Distances are stored in currDist
    // Predecessors in path are stored in predecessor
    void shortestPaths( int sourceVertex, int currDist [], int predecessor []);
    void displayRoute(std::string cityAr [], int pred [], int sourceVertex, int target);
    
    // Displays the contents of the adjacency matrix
    void displayMatrix( );
    
private:
    
    
    // The number of vertices in the graph
    int mNumVertices;
    
    // The adjacency matrix for the graph
    int** mMatrix;
    //int *currDist;
   // int *predecessor;
    
    
    // The maximum weight for an edge in the graph (used for non-adjacent vertices)
    static const int MAX_WEIGHT = 9999;
    
    // Deallocate the matrix
    void deallocate();
    
    // Copy data from an existing Graph object
    void copyFrom(const Graph &);
    
    
    
};

#endif
