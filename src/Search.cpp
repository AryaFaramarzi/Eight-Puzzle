#include "../header/search.h"
#include <queue>

struct CustomCompare
{ 
    bool operator()(Node* lhs, Node* rhs)
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
    
    std::priority_queue<Node *, std::vector<Node*>, CustomCompare> q;
    q.push(root);

    while (!q.empty())
    {

        Node *temp = q.top();
        q.pop();

        if(temp->isSolution()) {
            temp->print();
            return;
        }
        

        if(temp->isSolvable()){
            Node* left = temp->shiftLeft();
            Node* up = temp->shiftUp();
            Node* down = temp->shiftDown();
            Node* right = temp->shiftRight();
            if(left != nullptr) {
                    q.push(left);
            }
            if(up != nullptr){
                q.push(up);
            }
            if(right != nullptr){
                q.push(right);
            }
            if(down != nullptr){
                q.push(down);
            }
        }
    }

}