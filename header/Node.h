#ifndef __NODE_H__
#define __NODE_H__
#include <vector>
#include <iostream>
#include <algorithm>
class Node
{
private:
    std::vector<std::vector<char>> board;
    Node *parent;
    int cost;
    int depth;
public:
    // Getters and Setters
    std::vector<std::vector<char>> getBoard() { return board; }
    Node *getParent() { return parent; }
    int getCost() {return cost;}
    int getDepth() {return depth;}
    void setBoard(std::vector<std::vector<char>> board) { this->board = board; }
    void setParent(Node *parent) { this->parent = parent; }
    void setCost(int cost) {this->cost = cost;}
    void setDepth(int depth) { this->depth = depth; }

    // Additional helpful methods
    void printBoard();
    std::pair<int, int> findEmpty();
    bool downValid();
    bool upValid();
    bool leftValid();
    bool rightValid();
    bool isSolvable();
    int calculateCost();
    bool isSolution();
    void print();

    // Methods to create child nodes
    Node* shiftDown();
    Node* shiftUp();
    Node* shiftLeft();
    Node* shiftRight();

    // Constructor and Destructor
    Node(std::vector<std::vector<char>> board, Node *parent, int depth);
    ~Node();
};

#endif
