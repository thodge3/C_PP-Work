// Nicholas Coleman
// CSCI 3250
// Programming Assignment 4
// Source file for maze class

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Maze.hpp"

using namespace std;

// Get the position to the north
Position getNorth(const Position &pos) {
  Position newPos = pos;
  newPos.row--;
  return newPos;
}

// Get the position to the south
Position getSouth(const Position &pos) {
  Position newPos = pos;
  newPos.row++;
  return newPos;
}

// Get the position to the east
Position getEast(const Position &pos) {
  Position newPos = pos;
  newPos.col++;
  return newPos;
}

// Get the position to the west
Position getWest(const Position &pos) {
  Position newPos = pos;
  newPos.col--;
  return newPos;
}

// Load a maze from a source file
Maze::Maze(string sourceFile) {

  ifstream source;
  int rows, cols, row, col;
  unsigned int walls;

  // Attempt to open the source file
  source.open(sourceFile.c_str());
  if(source.fail()) {
    cerr << "Error: " << sourceFile << " does not exist" << endl;
    exit(EXIT_FAILURE);
  }

  // Get the number of rows and columns and initialize the maze
  source >> rows >> cols;
  if(rows <= 0 || cols <= 0) {
    cerr << "Invalid maze dimensions" << endl;
    exit(EXIT_FAILURE);
  }  
  init(rows, cols);
  for(int row = 0; row < mRows; row++) {
    for(int col = 0; col < mCols; col++) {
      // Default is no walls
      mMaze[row][col].north = true;
      mMaze[row][col].south = true;
      mMaze[row][col].west = true;
      mMaze[row][col].east = true;
      
      // Set visited and treasure flags to false;
      mMaze[row][col].visited = false;
      mMaze[row][col].treasure = false;
      mMaze[row][col].start = false;
    }
  }
  
  // Get the start position
  source >> row >> col;
  if(row < 0 || row >= mRows || col < 0 || col >= mCols) {
    cerr << "Invalid start position" << endl;
    exit(EXIT_FAILURE);
  }  
  mStartPos.row = row;
  mStartPos.col = col;
  mMaze[row][col].start = true;

  // Get the treasure position
  source >> row >> col;
  if(row < 0 || row >= mRows || col < 0 || col >= mCols) {
    cerr << "Invalid treasure position" << endl;
    exit(EXIT_FAILURE);
  }  
  mMaze[row][col].treasure = true;

  // Build the maze
  for(int i = 0; i < rows * cols; i++) {
    source >> row >> col >> walls;
    if(row < 0 || row >= mRows || col < 0 || col >= mCols) {
      cerr << "Invalid position" << endl;
      exit(EXIT_FAILURE);
    }  
    if(walls > 15) {
      cerr << "Invalid wall configuration" << endl;
      exit(EXIT_FAILURE);
    }
    if(walls & 1) {
      mMaze[row][col].west = false;
    }
    if(walls & 2) {
      mMaze[row][col].north = false;
    }
    if(walls & 4) {
      mMaze[row][col].east = false;
    }
    if(walls & 8) {
      mMaze[row][col].south = false;
    }
  }

  source.close();
}

// Copy constructor
Maze::Maze(const Maze &otherMaze) {
  init(otherMaze.mRows, otherMaze.mCols);
  copyFrom(otherMaze);
}

// Destructor
Maze::~Maze() {
  clear();
}

// Overloaded assignment operator
const Maze &Maze::operator=(const Maze &otherMaze) {
  clear();
  init(otherMaze.mRows, otherMaze.mCols);
  copyFrom(otherMaze);
  return *this;
}

// Deallocate the maze
void Maze::clear() {
  for(int row = 0; row < mRows; row++)
    delete [] mMaze[row];
  delete [] mMaze;
}

// Initialize a maze with a given number of rows and columns
void Maze::init(int rows, int cols) {
  mRows = rows;
  mCols = cols;
  mMaze = new PositionState *[mRows];  
  for(int row = 0; row < mRows; row++) {
    mMaze[row] = new PositionState[mCols];
  }
}

// Copy from an existing maze
void Maze::copyFrom(const Maze &otherMaze) {
  for(int row = 0; row < mRows; row++)
    for(int col = 0; col < mCols; col++)
      mMaze[row][col] = otherMaze.mMaze[row][col];
}

// Draw the maze to the console
void Maze::draw( ) const {
  // Draw north border
  for( int col = 0; col < mCols; col++ )
    cout << "____";
  cout << "_" << endl;
  
  // Draw rest of maze
  for( int row = 0; row < mRows; row++ ) {
    
    // Each row is made up of three lines of text
    for(int line = 0; line < 3; line++ ) {
      for( int col = 0; col < mCols; col++ ) {

	// Display west wall
	if(mMaze[row][col].west)
	  if(line == 2 && !mMaze[row][col].south)
	    cout << "_";
	  else
	    cout << " ";
	else
	  cout << "|";

	// Display interior
	if(line == 0) // Empty space
	  cout << "   ";
	else if(line == 1) { // Check for start point, treasure, or mark
	  cout << " ";
	  if(mMaze[row][col].start)
	    cout << "S";
	  else if(mMaze[row][col].treasure)
	    cout << "T";
	  else if(mMaze[row][col].marked)
	    cout << "*";
	  else
	    cout << " ";
	  cout << " ";
	}
	else if(mMaze[row][col].south)
	  cout << "   ";
	else // Display south wall
	  cout << "___";
      }

      // Display final east wall
      cout << "|" << endl;
    }
  }
  cout << endl;
}

// Determine if there is a way to the north
bool Maze::north(Position pos) const {
  if(pos.row >= 0 && pos.row < mRows && pos.col >=0 && pos.col < mCols)
    return mMaze[pos.row][pos.col].north;
  else
    return false;
}

// Determine if there is a way to the south
bool Maze::south(Position pos) const {
  if(pos.row >= 0 && pos.row < mRows && pos.col >=0 && pos.col < mCols)
    return mMaze[pos.row][pos.col].south;
  else
    return false;
}

// Determine if there is a way to the east
bool Maze::east(Position pos) const {
  if(pos.row >= 0 && pos.row < mRows && pos.col >=0 && pos.col < mCols)
    return mMaze[pos.row][pos.col].east;
  else
    return false;
}

// Determine if there is a way to the west
bool Maze::west(Position pos) const {
  if(pos.row >= 0 && pos.row < mRows && pos.col >=0 && pos.col < mCols)
    return mMaze[pos.row][pos.col].west;
  else
    return false;
}

// Check if the treasure has been found
bool Maze::treasure(Position pos) const {
  if(pos.row >= 0 && pos.row < mRows && pos.col >=0 && pos.col < mCols)
    return mMaze[pos.row][pos.col].treasure;
  else
    return false;
}

// Check if a position has already been visited
bool Maze::visited(Position pos) const {
  if(pos.row >= 0 && pos.row < mRows && pos.col >=0 && pos.col < mCols)
    return mMaze[pos.row][pos.col].visited;
  else
    return false;
}

// Get the start position
Position Maze::startPos() const {
  return mStartPos;
}

// Visit a position
void Maze::visit(Position pos) {
  if(pos.row >= 0 && pos.row < mRows && pos.col >=0 && pos.col < mCols)
    mMaze[pos.row][pos.col].visited = true;
}

// Mark a position
void Maze::mark(Position pos) {
  if(pos.row >= 0 && pos.row < mRows && pos.col >=0 && pos.col < mCols)
    mMaze[pos.row][pos.col].marked = true;
}
