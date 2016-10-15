// Nicholas Coleman
// CSCI 3250
// Programming Assignment 4
// Header file for maze class

#ifndef __MAZE_HPP__
#define __MAZE_HPP__

#include <string>

// Represents a position in the maze
struct Position {
  int row;
  int col;
};

// Generates neighboring positions
Position getNorth(const Position &pos);
Position getSouth(const Position &pos);
Position getEast(const Position &pos);
Position getWest(const Position &pos);

// Represents the configuration of a position in the maze
struct PositionState {
  bool north;
  bool south;
  bool east;
  bool west;
  bool visited;
  bool start;
  bool treasure;
  bool marked;
};

// The Maze class
class Maze {
public:
  // Constructors
  Maze(std::string sourceFile);
  Maze(const Maze &otherMaze);

  // Destructor
  ~Maze();

  // Overloaded Assignment Operator
  const Maze &operator=(const Maze &otherMaze);

  // Display the maze
  void draw() const;

  // Accessors
  bool north(Position pos) const;
  bool south(Position pos) const;
  bool east(Position pos) const;  
  bool west(Position pos) const;
  bool visited(Position pos) const;
  bool treasure(Position pos) const;
  Position startPos() const;

  // Mutator
  void visit(Position pos);
  void mark(Position pos);
  
private:
  // Initialize the maze
  void init(int rows, int cols);

  // Copy from another maze
  void copyFrom(const Maze &otherMaze);

  // Clear out the contents of a maze
  void clear();

  // Number of rows in the maze
  int mRows;

  // Number of columns in the maze
  int mCols;

  // Start position for the maze
  Position mStartPos;

  // The configurations of all of the positions in the maze
  PositionState ** mMaze;
};

#endif
