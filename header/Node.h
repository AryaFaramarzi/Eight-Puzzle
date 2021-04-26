#ifndef __NODE_H__
#define __NODE_H__
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
class Node
{
private:
    std::vector<std::vector<char>> board;
    Node *parent;
    int costEucledian;
    int costMisplace;
    int depth;

public:
    // Getters and Setters
    std::vector<std::vector<char>> getBoard() { return board; }
    Node *getParent() { return parent; }
    int getCostEucliedian() { return costEucledian; }
    int getCostMisplace() { return costMisplace; }
    int getDepth() { return depth; }
    void setBoard(std::vector<std::vector<char>> board) { this->board = board; }
    void setParent(Node *parent) { this->parent = parent; }
    void setDepth(int depth) { this->depth = depth; }

    // Additional helpful methods
    void printBoard();
    std::pair<int, int> findEmpty();
    bool downValid();
    bool upValid();
    bool leftValid();
    bool rightValid();
    bool isSolvable();
    int calculateCostMistile();
    double calculateCostEucledian();
    bool isSolution();
    void printUniform();
    void printMisplaced();
    void printEucledian();

    // Methods to create child nodes
    Node *shiftDown();
    Node *shiftUp();
    Node *shiftLeft();
    Node *shiftRight();

    // Constructor and Destructor
    Node(std::vector<std::vector<char>> board, Node *parent, int depth);
    ~Node();
};

#endif
