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
        return (lhs->getCostMisplace() + lhs->getDepth() > rhs->getCostMisplace() + rhs->getDepth());
    }
};

struct customCompareEucledian
{
    bool operator()(Node *lhs, Node *rhs)
    {
        return (lhs->getCostEucliedian() + lhs->getDepth() > rhs->getCostEucliedian() + rhs->getDepth());
    }
};

Search::Search(Node *root)
{
    this->root = root;
    this->nodes = 0;
}

Search::~Search()
{
    delete root;
    root = nullptr;
}

void Search::UniformCostSearch() //    priority_queue<int,CustomCompare > pq;
{

    std::priority_queue<Node *, std::vector<Node *>, customCompareUCS> q;
    std::set<std::vector<std::vector<char>>> explored;
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
            std::cout << " ------------------------------------------- " << std::endl;
            std::cout << "Steps taken to solve the puzzle is as follows: " << std::endl;
            temp->print();
            return;
        }

        if (temp->isSolvable() && explored.count(temp->getBoard()) == 0)
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
        // explored.insert(temp->getBoard());
        this->nodes++;
    }
}

void Search::MisplacedTilesSearch() //    priority_queue<int,CustomCompare > pq;
{
    //int count = 0;
    std::priority_queue<Node *, std::vector<Node *>, customCompareMistile> q;
    std::set<std::vector<std::vector<char>>> explored;

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
            std::cout << " ------------------------------------------- " << std::endl;
            std::cout << "Steps taken to solve the puzzle is as follows: " << std::endl;
            temp->print();
            return;
        }

        if (temp->isSolvable() && explored.count(temp->getBoard()) == 0)
        {
            //count++;
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
        // explored.insert(temp->getBoard());
        this->nodes++;
    }
}

void Search::EucledianDistanceSearch() //    priority_queue<int,CustomCompare > pq;
{

    std::priority_queue<Node *, std::vector<Node *>, customCompareEucledian> q;
    std::set<std::vector<std::vector<char>>> explored;

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
            std::cout << " ------------------------------------------- " << std::endl;
            std::cout << "Steps taken to solve the puzzle is as follows: " << std::endl;
            temp->print();
            return;
        }

        if (temp->isSolvable() && explored.count(temp->getBoard()) == 0)
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
        explored.insert(temp->getBoard());
        this->nodes++;
    }
}