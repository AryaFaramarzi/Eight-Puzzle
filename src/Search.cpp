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
    int maxQueueSize = 0;

    std::priority_queue<Node *, std::vector<Node *>, customCompareUCS> q;
    std::set<std::vector<std::vector<char>>> explored;
    if (!root->isSolvable())
    {
        std::cout << "Puzzle entered is not solveable" << std::endl;
        std::cout << "Max Queue size is 0" << std::endl;
        return;
    }

    q.push(root);

    while (!q.empty())
    {
        maxQueueSize = (maxQueueSize > q.size()) ? (maxQueueSize) : (q.size());
        Node *temp = q.top();

        q.pop();

        //std::cout << "The cost + depth squared is: " << temp->getCost() + pow(temp->getDepth(), 2) << std::endl;
        std::cout << "The best state to expand with g(n) = " << temp->getDepth() << std::endl;
        temp->printBoard();
        std::cout << "\n\n";

        if (temp->isSolution())
        {
            std::cout << " ------------------------------------------- " << std::endl;
            std::cout << "Steps taken to solve the puzzle is as follows: " << std::endl;
            temp->printUniform();
            std::cout << "Maximum queue size for UCS search is: " << maxQueueSize << std::endl;
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
    // std::cout << "Maximum queue size for this search is: " << maxQueueSize << std::endl;
}

void Search::MisplacedTilesSearch() //    priority_queue<int,CustomCompare > pq;
{
    int maxQueueSize = 0;
    std::priority_queue<Node *, std::vector<Node *>, customCompareMistile> q;
    std::set<std::vector<std::vector<char>>> explored;

    if (!root->isSolvable())
    {
        std::cout << "Puzzle entered is not solveable" << std::endl;
        std::cout << "Max Queue size is 0" << std::endl;
        return;
    }

    q.push(root);

    while (!q.empty())
    {
        maxQueueSize = (maxQueueSize > q.size()) ? (maxQueueSize) : (q.size());
        Node *temp = q.top();
        q.pop();

        //std::cout << "The cost + depth squared is: " << temp->getCost() + pow(temp->getDepth(), 2) << std::endl;
        std::cout << "The best state to expand with g(n) = " << temp->getDepth() << " and with h(n) = " << temp->getCostMisplace() << std::endl;
        temp->printBoard();
        std::cout << "\n\n";

        if (temp->isSolution())
        {
            std::cout << " ------------------------------------------- " << std::endl;
            std::cout << "Steps taken to solve the puzzle is as follows: " << std::endl;
            temp->printMisplaced();
            std::cout << "Maximum queue size for Misplaced Tile  search is: " << maxQueueSize << std::endl;
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
        explored.insert(temp->getBoard());
        this->nodes++;
    }
    std::cout << "Maximum queue size for this search is: " << maxQueueSize << std::endl;
}

void Search::EucledianDistanceSearch() //    priority_queue<int,CustomCompare > pq;
{
    int maxQueueSize = 0;
    std::priority_queue<Node *, std::vector<Node *>, customCompareEucledian> q;
    std::set<std::vector<std::vector<char>>> explored;

    if (!root->isSolvable())
    {
        std::cout << "Puzzle entered is not solveable" << std::endl;
        std::cout << "Max Queue size is 0" << std::endl;
        return;
    }

    q.push(root);

    while (!q.empty())
    {
        maxQueueSize = (maxQueueSize > q.size()) ? (maxQueueSize) : (q.size());
        Node *temp = q.top();
        q.pop();

        //std::cout << "The cost + depth squared is: " << temp->getCost() + pow(temp->getDepth(), 2) << std::endl;
        std::cout << "The best state to expand with g(n) = " << temp->getDepth() << " and with h(n) = " << temp->getCostEucliedian() << std::endl;
        temp->printBoard();
        std::cout << "\n\n";

        if (temp->isSolution())
        {
            std::cout << " ------------------------------------------- " << std::endl;
            std::cout << "Steps taken to solve the puzzle is as follows: " << std::endl;
            temp->printEucledian();
            std::cout << "Maximum queue size for Eucledian Distance search is: " << maxQueueSize << std::endl;
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
    std::cout << "Maximum queue size for this search is: " << maxQueueSize << std::endl;
}