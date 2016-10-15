//
//  main.cpp
//  Graph
//
//  Created by Travis Hodge on 4/4/16.
//  Copyright © 2016 Travis Hodge. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "graph.h"
//#include "distances.txt"

using namespace std;

int main() {

    int numberOfCities, weight, sourceIndex, targetIndex; // declares the variables to be used when creating edges
    int numberOfConnections; // variable to contain the number of connections between cities

    string lines, sourceCity, targetCity; // strings to contain the source vertex and target vertex when creating edges
    ifstream myfile ("distances.txt"); // ifstream to open the .txt file
    
    
    myfile >> numberOfCities; // writes the first line of the .txt file to the "numberOfCities" variable
    
    Graph testGraph(numberOfCities); // creates an instance of the Graph class calling the constructor using the number of cities given
    //Graph testGraph2(numberOfCities);
    
    
    string *cityArray = new string [numberOfCities]; // dynamically allocates an array to contain the cities given in the .txt file
    int *dist = new int [numberOfCities]; // dynamically allocates an array of ints to hold the final distance from the source vertex to
                                          // the target vertex.
    int *pred = new int [numberOfCities]; // dynamically allocates an array to hold the index of the predecessor
    
    for (int i = 0; i < numberOfCities; i++) {
        myfile >> cityArray[i]; // writes each city in the file to the array of cities, from 0 to n-1
        
    }
    
    myfile >> numberOfConnections; // stores the number of connections given in the file to a variable.
    
    sourceIndex = 0; // used in creating an edge
    targetIndex = 0;
    weight = 0;
   
    
    for (int i = 0; i < numberOfConnections; i++) {
        myfile >> sourceCity >> targetCity >> weight; // writes the first city in the line as the source, second as the target, and the
                                                      // weight as the distance between the two cities.
        
        for (int s = 0; s < numberOfCities; s++) {
            if (sourceCity == cityArray[s]) {
                sourceIndex = s; // matches the source city to the index stored previously in the city array.
            }
            for (int dd = 0; dd < numberOfCities; dd++) {
                if (targetCity == cityArray[dd]) {
                    targetIndex = dd; // matches the target city to the index stored previously in the city array.
                }
            }
            
        }
        
        testGraph.addEdge(sourceIndex, targetIndex, weight); // adds an edge between the given cities.
        testGraph.addEdge(targetIndex, sourceIndex, weight); // adds the return edge between these two cities.
        
    }
    
    
    int menuItem = -1; // declares a switch variable
    bool exit = false; // bool used to determine whether or not the user exits.
    
    while (menuItem != 0) {
        
        cout << "Please enter a source city. " << endl;
        cout << "1 : Atlanta \n"
             << "2 : Biringham\n"
             << "3 : Charlotte\n"
             << "4 : Chattanooga\n"
             << "5 : Charleston(WV)\n"
             << "6 : Cincinnati\n"
             << "7 : Columbus\n"
             << "8 : Indianapolis\n"
             << "9 : Knoxville\n"
             << "10 : Lexington\n"
             << "11 : Louisville\n"
             << "12 : Memphis\n"
             << "13 : Nashville\n"
             << "14 : StLouis\n"
             << "Press 0 to exit\n";
        
        cin >> menuItem;
        
        if (menuItem < 0) {
            cout << "This is not an option, try again.\n";
        }
        
        switch (menuItem) {
                
                case 1:
                    testGraph.shortestPaths(0, dist, pred);
                    sourceIndex = 0;
                    menuItem = 0;
                    break;
                
                case 2:
                    testGraph.shortestPaths(1, dist, pred); // calls the algorithm to determine the shortest path to all cities using
                                                            // the given source vertex.
                    menuItem = 0;
                    sourceIndex = 1;
                    break;
                
                case 3:
                    testGraph.shortestPaths(2, dist, pred);
                    menuItem = 0; // menuItem set to zero to break the while loop.
                    sourceIndex = 2;
                    break;
                case 4:
                    testGraph.shortestPaths(3, dist, pred);
                    menuItem = 0;
                    sourceIndex = 3;
                    break;
                case 5:
                    testGraph.shortestPaths(4, dist, pred);
                    menuItem = 0;
                    sourceIndex = 4;
                    break;
                case 6:
                    testGraph.shortestPaths(5, dist, pred);
                    menuItem = 0;
                    sourceIndex = 5;
                    break;
                case 7:
                    testGraph.shortestPaths(6, dist, pred);
                    menuItem = 0;
                    sourceIndex = 6;
                    break;
                case 8:
                    testGraph.shortestPaths(7, dist, pred);
                    menuItem = 0;
                    sourceIndex = 7;
                    break;
                case 9:
                    testGraph.shortestPaths(8, dist, pred);
                    menuItem = 0;
                    sourceIndex = 8;
                    break;
                case 10:
                    testGraph.shortestPaths(9, dist, pred);
                    menuItem = 0;
                    sourceIndex = 9;
                    break;
                case 11:
                    testGraph.shortestPaths(10, dist, pred);
                    menuItem = 0;
                    sourceIndex = 10;
                    break;
                case 12:
                    testGraph.shortestPaths(11, dist, pred);
                    menuItem = 0;
                    sourceIndex = 11;
                    break;
                case 13:
                    testGraph.shortestPaths(12, dist, pred);
                    menuItem = 0;
                    sourceIndex = 12;
                    break;
                case 14:
                    testGraph.shortestPaths(13, dist, pred);
                    menuItem = 0;
                    sourceIndex = 13;
                    break;
                case 0:
                cout << "You have chosen to exit. \n";
                exit = true;
                    break;
                
            default:
                break;
        }
        
        
    }
    
    cout << endl;
    cout << endl;
    if (exit !=true) {
             // if the user didn't immediately exit from the program, this prints out the distance information and adj matrix.
     
             // returns the dist array changed from
             // the path algorithm
        
    
        
        for (int i  = 0; i < 20; i++) {
            cout << "* ";
        }
        cout << endl;
        cout << "Shortest distance to each city \n";
        for (int i  = 0; i < 20; i++) {
            cout << "* ";
        }
        for (int i = 0; i < 3; i++) {
            cout << endl;
        }
        
        
        for (int i = 0; i < numberOfCities; i++) {
            cout << setw(4) << testGraph.cityAbvArray[i] << " ";
        }
        cout << endl;
        for (int i  = 0; i < numberOfCities; i++) {
            cout << setw(4) << "----" << " ";
        }
        cout << endl;
        for (int i  = 0 ; i < numberOfCities; i++) {
            cout << setw(4) << dist[i] << " ";
        }
        
        for (int i = 0; i < 5; i++) {
            cout << endl;
        }
        for (int i  = 0; i < 20; i++) {
            cout << "* ";
        }
        cout << endl;
        cout << "Route to each city \n";
        for (int i  = 0; i < 20; i++) {
            cout << "* ";
        }
        
        for (int i = 0; i < 5; i++) {
            cout << endl;
        }
        
        for (int i = 0; i < numberOfCities; i++) {
            testGraph.displayRoute(cityArray, pred, sourceIndex, i);
            cout << endl;
        }
        for (int i = 0; i < 5; i++) {
            cout << endl;
        }
        
        for (int i  = 0; i < 20; i++) {
            cout << "* ";
        }
        cout << endl;
        cout << "Adjacency Matrix \n";
        for (int i  = 0; i < 20; i++) {
            cout << "* ";
        }
        for (int i = 0; i < 3; i++) {
            cout << endl;
        }

    
        
    testGraph.displayMatrix(); // displays the adjacency matrix representing the graph of cities.
    }
    delete [] cityArray; // deletes all dynamically allocated arrays.
    delete [] dist;
    delete [] pred;
    
    return 0;
}
