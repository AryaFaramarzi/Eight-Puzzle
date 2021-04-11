#include "../header/Node.h"

Node::Node(std::vector<std::vector<char>> board, Node *parent)
{
    this->board = board;
    this->parent = parent;
}

Node::~Node()
{
    delete parent;
    parent = nullptr;
}

void Node::printBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool Node::upValid()
{
    if (board[0][0] != '0' and board[0][1] != '0' and board[0][2] != '0')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Node::downValid()
{
    if (board[2][0] != '0' && board[2][1] != '0' && board[2][2] != '0')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Node::leftValid()
{
    if (board[0][0] != '0' && board[1][0] != '0' && board[2][0] != '0')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Node::rightValid()
{
    if (board[0][2] != '0' && board[1][2] != '0' && board[2][2] != '0')
    {
        return true;
    }
    else
    {
        return false;
    }
}