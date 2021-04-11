#ifndef __NODE_H__
#define __NODE_H__
#include <vector>
#include <iostream>
class Node
{
private:
    std::vector<std::vector<char>> board;
    Node *parent;

public:
    // Getters and Setters
    std::vector<std::vector<char>> getBoard() { return board; }
    Node *getParent() { return parent; }
    void setBoard(std::vector<std::vector<char>> board) { this->board = board; }
    void setParent(Node *parent) { this->parent = parent; }

    // Additional helpful methods
    void printBoard();

    bool downValid();
    bool upValid();
    bool leftValid();
    bool rightValid();

    // Constructor and Destructor
    Node(std::vector<std::vector<char>> board, Node *parent);
    ~Node();
};

#endif
