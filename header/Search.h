#ifndef __SEARCH_H__
#define __SEARCH_H__
#include "Node.h"

class Search
{
    Node *root;

public:
    Search(Node *root);
    ~Search();

    void UniformCostSearch();
    void AStar1();
    void AStart2();
};

#endif