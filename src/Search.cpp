#include "../header/search.h"
#include <queue>

struct CustomCompare
{
    bool operator()(Node* lhs, Node* rhs)
    {
        return lhs->getCost() < rhs->getCost();
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

        if(temp->isSolution()) {
            temp->print();
            return;
        }
        
        if(!temp->isSolvable()){
            q.pop();
        }
        else{
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