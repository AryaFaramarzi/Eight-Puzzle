#ifndef __SEARCH_H__
#define __SEARCH_H__
#include "Node.h"
#include <queue>
#include <cmath>

class Search
{
    Node *root;

public:
    Search(Node *root);
    ~Search();

    void UniformCostSearch();
    void MisplacedTilesSearch();
    void EucledianDistanceSearch();
    void AStar1();
    void AStart2();
};

#endif