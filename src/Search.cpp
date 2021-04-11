#include "../header/search.h"
#include <queue>

Search::Search(Node *root)
{
    this->root = root;
}

Search::~Search()
{
    delete root;
    root = nullptr;
}

void Search::UniformCostSearch()
{
    std::priority_queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        }
}