#include "../header/search.h"

struct customCompareUCS
{
    bool operator()(Node *lhs, Node *rhs)
    {
        return (lhs->getDepth() > rhs->getDepth());
    }
};

struct customCompareMistile
{
    bool operator()(Node *lhs, Node *rhs)
    {
        return (lhs->getCost() + lhs->getDepth() > rhs->getCost() + rhs->getDepth());
    }
};

struct customCompareEucledian
{
    bool operator()(Node *lhs, Node *rhs)
    {
        return (lhs->getCost() + lhs->getDepth() > rhs->getCost() + rhs->getDepth());
    }
};

Search::Search(Node *root)
{
    this->root = root;
}

Search::~Search()
{
    delete root;
    root = nullptr;
}

void Search::UniformCostSearch() //    priority_queue<int,CustomCompare > pq;
{

    std::priority_queue<Node *, std::vector<Node *>, customCompareUCS> q;

    if (!root->isSolvable())
    {
        std::cout << "Puzzle entered is not solveable" << std::endl;
        return;
    }

    q.push(root);

    while (!q.empty())
    {

        Node *temp = q.top();
        q.pop();

        //std::cout << "The cost + depth squared is: " << temp->getCost() + pow(temp->getDepth(), 2) << std::endl;
        temp->printBoard();
        std::cout << "\n\n";

        if (temp->isSolution())
        {
            temp->print();
            return;
        }

        if (temp->isSolvable())
        {
            Node *left = temp->shiftLeft();
            Node *up = temp->shiftUp();
            Node *down = temp->shiftDown();
            Node *right = temp->shiftRight();
            if (left != nullptr)
            {
                q.push(left);
            }
            if (up != nullptr)
            {
                q.push(up);
            }
            if (right != nullptr)
            {
                q.push(right);
            }
            if (down != nullptr)
            {
                q.push(down);
            }
        }
    }
}

void Search::MisplacedTilesSearch() //    priority_queue<int,CustomCompare > pq;
{

    std::priority_queue<Node *, std::vector<Node *>, customCompareMistile> q;

    if (!root->isSolvable())
    {
        std::cout << "Puzzle entered is not solveable" << std::endl;
        return;
    }

    q.push(root);

    while (!q.empty())
    {

        Node *temp = q.top();
        q.pop();

        //std::cout << "The cost + depth squared is: " << temp->getCost() + pow(temp->getDepth(), 2) << std::endl;
        temp->printBoard();
        std::cout << "\n\n";

        if (temp->isSolution())
        {
            temp->print();
            return;
        }

        if (temp->isSolvable())
        {
            Node *left = temp->shiftLeft();
            Node *up = temp->shiftUp();
            Node *down = temp->shiftDown();
            Node *right = temp->shiftRight();
            if (left != nullptr)
            {
                q.push(left);
            }
            if (up != nullptr)
            {
                q.push(up);
            }
            if (right != nullptr)
            {
                q.push(right);
            }
            if (down != nullptr)
            {
                q.push(down);
            }
        }
    }
}

void Search::EucledianDistanceSearch() //    priority_queue<int,CustomCompare > pq;
{

    std::priority_queue<Node *, std::vector<Node *>, customCompareEucledian> q;

    if (!root->isSolvable())
    {
        std::cout << "Puzzle entered is not solveable" << std::endl;
        return;
    }

    q.push(root);

    while (!q.empty())
    {

        Node *temp = q.top();
        q.pop();

        //std::cout << "The cost + depth squared is: " << temp->getCost() + pow(temp->getDepth(), 2) << std::endl;
        temp->printBoard();
        std::cout << "\n\n";

        if (temp->isSolution())
        {
            temp->print();
            return;
        }

        if (temp->isSolvable())
        {
            Node *left = temp->shiftLeft();
            Node *up = temp->shiftUp();
            Node *down = temp->shiftDown();
            Node *right = temp->shiftRight();
            if (left != nullptr)
            {
                q.push(left);
            }
            if (up != nullptr)
            {
                q.push(up);
            }
            if (right != nullptr)
            {
                q.push(right);
            }
            if (down != nullptr)
            {
                q.push(down);
            }
        }
    }
}