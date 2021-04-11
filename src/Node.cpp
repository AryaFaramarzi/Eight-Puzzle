#include "../header/Node.h"

Node::Node(std::vector<std::vector<char>> board, Node *parent)
{
    this->board = board;
    this->parent = parent;
    this->cost = this->calculateCost();
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

std::pair<int,int> Node::findEmpty()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(board[i][j] == '0'){
                    return {i,j};
            }
        }
    }
}


Node* Node::shiftDown(){
    if(!downValid()) {
        return nullptr;
    }
    std::vector<std::vector<char>> tmpBoard = this->getBoard();
    std::pair<int, int> location = this->findEmpty();

    board[location.first][location.second] = board[location.first + 1][location.second];
    board[location.first + 1][location.second] = '0';
    Node* res = new Node(board, this);
    return res;
}

Node* Node::shiftUp(){
    if(!upValid()) {
        return nullptr;
    }
    std::vector<std::vector<char>> tmpBoard = this->getBoard();
    std::pair<int, int> location = this->findEmpty();

    board[location.first][location.second] = board[location.first - 1][location.second];
    board[location.first - 1][location.second] = '0';
    Node* res = new Node(board, this);
    return res;
}

Node* Node::shiftLeft(){
    if(!leftValid()) {
        return nullptr;
    }
    std::vector<std::vector<char>> tmpBoard = this->getBoard();
    std::pair<int, int> location = this->findEmpty();

    board[location.first][location.second] = board[location.first][location.second - 1];
    board[location.first][location.second - 1] = '0';
    Node* res = new Node(board, this);
    return res;
}

Node* Node::shiftRight(){
    if(!rightValid()) {
        return nullptr;
    }
    std::vector<std::vector<char>> tmpBoard = this->getBoard();
    std::pair<int, int> location = this->findEmpty();

    board[location.first][location.second] = board[location.first][location.second + 1];
    board[location.first][location.second + 1] = '0';
    Node* res = new Node(board, this);
    return res;
}



//This functions checks whether or not a board is solvable
// If it is not solvable then we do not expand the tree otherwise we do 
bool Node::isSolvable(){
    int inversions = 0;
    std::vector<char> temp;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
                temp.push_back(board[i][j]);
        }
    }

     for(int i = 0; i < 3 ; i++){
            for(int j =i+1 ; j < 3 ; j++){
                if(temp[j]>temp[i]){
                    inversions++;
                }
            }
        }

    if(inversions % 2 == 1){
        return false;
    }
    else{
        return true;
    }
}

// The cost function is defined as the number of misplaced tiles on the board
int Node::calculateCost(){ //  1 2 3 4 5 6 7 8  0
    int boardDifference = 0;
    std::vector<char> temp;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    char curr = '1';
    for(int i  = 0; i < temp.size() - 1; i++){
        if(temp[i] != curr){
            boardDifference++;
        }
        curr++;
    }
    if(temp[temp.size() - 1] != '0'){
        boardDifference++;
    }
    return boardDifference;
}


bool Node::isSolution(){
    std::vector<char> temp;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    char curr = '1';
    for (int i = 0; i < temp.size() - 1; i++)
    {
        if (temp[i] != curr)
        {
            return false;
        }
    }
    if (temp[temp.size() - 1] != '0')
    {
        return false;
    }
    return true;
}

void Node::print() {
    if(this == nullptr) {
        return;
    }
    getParent()->print();
    this->printBoard();
    std::cout << std::endl;
}